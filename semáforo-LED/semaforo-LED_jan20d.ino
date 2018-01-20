//Projeto Arduino sinal de trânsito
//Por Jota
//www.comofazerascoisas.com.br
 
//Método setup, assim que o arduino é ligado ele 
//é executado, uma vez apenas.
void setup() {
  pinMode(8,OUTPUT);     //define o pino 8 como saída
  pinMode(9,OUTPUT);     //define o pino 9 como saída
  pinMode(10,OUTPUT);    //define o pino 10 como saída
}
//Método loop, é executado enquanto o arduino estiver ligado.
void loop() {
  //Controle do led verde
  digitalWrite(8,HIGH);  //acende o led
  delay(8000);           //espera 8 segundos
  digitalWrite(8,LOW);   //apaga o led
   
  //Controle do led amarelo
  digitalWrite(9,HIGH);  //acende o led
  delay(4000);           //espera 4 segundos
  digitalWrite(9,LOW);   //apaga o led
   
  //Controle do led vermelho
  digitalWrite(10,HIGH); //acende o led
  delay(6000);           //espera 6 segundos
  digitalWrite(10,LOW);  //apaga o led
}
