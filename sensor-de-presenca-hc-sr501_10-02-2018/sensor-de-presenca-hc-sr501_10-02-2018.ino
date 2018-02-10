#define LED 13
#define PIR 2
 
void setup() {
pinMode(LED, OUTPUT);
pinMode(PIR, INPUT);
delay(5000);
}
 
void loop() {
byte leitura = digitalRead(PIR);
digitalWrite(LED, leitura);
}
 
 

