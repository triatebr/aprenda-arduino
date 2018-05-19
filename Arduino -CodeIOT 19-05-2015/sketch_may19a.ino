// Programa realizado no CodeIOT
// data: 19-05-2018
// Devs: Kelvia, Mateus & Lucas
// Objetivo: acender o LED no Arduino
int tempo=1000;
int led=13;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite (led,0);
delay (tempo);
digitalWrite (led,1);
delay (tempo);
}
