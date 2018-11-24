#include <Adafruit_Sensor.h> //Bibliotecas usadas no código
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "stdlib.h"

#define PIR 7 // pino do sensor de presença
#define PIRTYPE PIR 
PIR pir(D7, 3.3);

// Update these with values suitable for your network.

const char* ssid     = "2.4G_COTONETES";
const char* password = "31012015anapaulalucas";  
const char* mqttServer = "iot.eclipse.org";
const int mqttPort = 1883;
const char* mqttUser = "";
const char* mqttPassword = "";

char  json[100];

WiFiClient espClient;
PubSubClient client(espClient);

void setup() 
{
  Serial.begin(115200);
  Serial.println("Sensor PIR test!");
  pir.begin();

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
