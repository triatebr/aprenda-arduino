#include <Adafruit_Sensor.h> //Bibliotecas usadas no código
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <MQ135.h>
#include "DHT.h"
#include "MQ7.h"
#include <stdlib.h>

#define DHTPIN 4 // pino do sensor de temperatura
#define DHTTYPE DHT22 // DHT 22
#define MQ135PIN A0  // pino do sensor de gas A0 = A0


DHT dht(DHTPIN, DHTTYPE);
MQ135 gasSensor = MQ135(MQ135PIN);

// Update these with values suitable for your network.

const char* ssid     = "2.4G_COTONETES";
const char* password = "31012015anapaulalucas"; 
const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;
const char* mqttUser = "";
const char* mqttPassword = "";

char  json[100];

WiFiClient espClient;
PubSubClient client(espClient);

void setup() 
{
  Serial.begin(115200);
  Serial.println("DHTxx test!");
  dht.begin();

  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
 
  client.setServer(mqttServer, mqttPort);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP8266Client", mqttUser, mqttPassword)) {
 
      Serial.println("connected");
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
}

void loop() 
{
  // A leitura da temperatura e umidade pode levar 250ms!
  // O atraso do sensor pode chegar a 2 segundos.
  float valor_umidade = dht.readHumidity();
  float valor_temp = dht.readTemperature();     
  float valor_co2 = analogRead(A0);
  
  // testa se retorno é valido, caso contrário algo está errado.
  if (isnan(valor_co2)) 
  {
    Serial.println("Failed to read from MQ-135");
  } 
  else 
  {

    
    DynamicJsonBuffer jBuffer;
    JsonObject & root = jBuffer.createObject();

    root["temperatura"] = valor_temp;
    root["umidade"] = valor_umidade;
    root["nivel_co"] = valor_co2;
    
    root.printTo(Serial);
    Serial.println();

    root.printTo(json);
    client.publish("smartcity/tdc4", json);
    client.loop();
    
  }
  
  delay(30000);
  
}
