//Autor: FILIEFLOP
 
int pino_D0 = 7;
int pino_A0 = A1;
 
int valor_a = 0;
int valor_d = 0;
 
void setup()
{
  Serial.begin(9600);
  pinMode(pino_A0, INPUT);
  pinMode(pino_D0, INPUT);
}
 
void loop()
{
  int valor_a = analogRead(pino_A0);
  int valor_d = digitalRead(pino_D0);
 
  Serial.print("Porta analogica: ");
  Serial.print(valor_a);
  Serial.print(" Porta digital: ");
  Serial.println(valor_d);
 
  if (valor_d != 1)
  {
    Serial.println("Fogo detectado !!!");
  }
  delay(500);
}
