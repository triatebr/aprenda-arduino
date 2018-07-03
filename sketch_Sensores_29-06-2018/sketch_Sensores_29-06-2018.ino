//#include <location.h>
#include <MQ135.h>
#include <Adafruit_Sensor.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"
#include <stdlib.h>

#define DHTPIN 14 // pino do sensor de temperatura
#define MQ135PIN A0 // pino do sensor de gas
#define DHTTYPE DHT22 // DHT 22

DHT dht(DHTPIN, DHTTYPE);
MQ135 gasSensor = MQ135(MQ135PIN);

// Update these with values suitable for your network.

const char* ssid     = "2.4G_COTONETES";
const char* password = "31012015anapaulalucas";
const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;
const char* mqttUser = "";
const char* mqttPassword = "";

String geolocationKey = "AIzaSyDVAaEpDA9klnhAv4xo5427crBJNo0Pa4M";
String geocodingKey = "AIzaSyDVAaEpDA9klnhAv4xo5427crBJNo0Pa4M";

int MCC = 724;
int MNC = 11;
String carrier = "Vivo";

//Location myLocation;

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

    if (client.connect("NodeMCUFulvio", mqttUser, mqttPassword)) {

      Serial.println("connected");

    } else {

      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);

    }
  }

  //myLocation.begin(geolocationKey, geocodingKey, MCC, MNC, carrier);

}

void loop()
{
  // A leitura da temperatura e umidade pode levar 250ms!
  // O atraso do sensor pode chegar a 2 segundos.
  float valor_umidade = dht.readHumidity();
  float valor_temp = dht.readTemperature();
  //float valor_co2 = analogRead(MQ135PIN);
  //myLocation.getLocation();

  // testa se retorno é valido, caso contrário algo está errado.
  if (isnan(valor_umidade) || isnan(valor_temp))
  {
    Serial.println("Failed to read from DHT");
  }
  else
  {

    DynamicJsonBuffer jBuffer;
    JsonObject& root = jBuffer.createObject();

    root["temperatura"] = valor_temp;
    root["umidade"] = valor_umidade;
    //root["nivel_co2"] = valor_co2;
    //root["latitude"] = myLocation.latitude;
    //root["longitude"] = myLocation.longitude;
    //root["accuracy"] = myLocation.accuracy;
    //root["address"] = myLocation.address;
    //root["id"] = "tdc2";

    root.printTo(Serial);
    Serial.println();

    root.printTo(json);

    //client.publish("smartcity/tdc4", json);
    client.publish("agrichain/sensor1", json);

  }

  client.loop();
  delay(10000);

}
