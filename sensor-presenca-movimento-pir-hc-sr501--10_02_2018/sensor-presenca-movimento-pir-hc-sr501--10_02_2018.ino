// Programa : Sensor de presenca com modulo PIR
// Autor : Arduino e Cia

int pinoledverm = 5; //Pino ligado ao led vermelho
int pinoledazul = 6; //Pino ligado ao led azul
int pinopir = 3;  //Pino ligado ao sensor PIR
int acionamento;  //Variavel para guardar valor do sensor

void setup()
{
  pinMode(pinoledverm, OUTPUT); //Define pino como saida
  pinMode(pinoledazul, OUTPUT); //Define pino como saida
  pinMode(pinopir, INPUT);   //Define pino sensor como entrada

}

void loop()
{
 acionamento = digitalRead(pinopir); //Le o valor do sensor PIR
 if (acionamento == LOW)  //Sem movimento, mantem led azul ligado
 {
    digitalWrite(pinoledverm, LOW);
    digitalWrite(pinoledazul, HIGH);
 }
 else  //Caso seja detectado um movimento, aciona o led vermelho
 {
    digitalWrite(pinoledverm, HIGH);
    digitalWrite(pinoledazul, LOW);
 }
}

