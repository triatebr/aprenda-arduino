#include <ESP8266WiFi.h>  //declarar a library com letra MAIUSCULA

    const char* ssid     = "2.4G_COTONETES";
    const char* password = "31012015anapaulalucas";     
 
    int wifiStatus;
 
    void setup() {
 
      Serial.begin(115200);
      delay(200);
 
 
      // Iniciar ligação à rede
 
      Serial.println();
      Serial.println();
      Serial.print("A ligar à rede ");
      Serial.println(ssid);
 
      WiFi.begin(ssid, password);
 
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
      }
 
 }   
 
void loop() {
      wifiStatus = WiFi.status();
 
      if(wifiStatus == WL_CONNECTED){
         Serial.println("");
         Serial.println("O seu nodeMCU está ligado!");  
         Serial.print("Endereço IP: ");
         Serial.println(WiFi.localIP()); 
        }  
      else{
        Serial.println("");
        Serial.println("Upsss...o seu nodeMCU não se consegue ligar...");
      }
      delay(1000); 
 
}
