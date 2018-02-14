int led1 = 6;
int led2 = 5;
int led3 = 4;
int led4 = 3;
int led5 = 2;
int potenciometro = A1;
 
void setup(){
Serial.begin(9600);        //incia a comunicação serie
pinMode(led1,OUTPUT);      //Define o pino 6 como OUTPUT(saída)
pinMode(led2,OUTPUT);      //Define o pino 5 como OUTPUT(saída)
pinMode(led3,OUTPUT);      //Define o pino 4 como OUTPUT(saída)
pinMode(led4,OUTPUT);      //Define o pino 3 como OUTPUT(saída)
pinMode(led5,OUTPUT);      //Define o pino 2 como OUTPUT(saída)
pinMode(potenciometro,INPUT);     //define o pino A1 como entrada
}
 
void loop(){
int ler = analogRead(potenciometro);     //guarda na variável "ler" os valores recebidos da porta A1
Serial.println(ler);     //Mostra no Serial Monitor os valores da porta A1
 
if(ler >= 0 && ler <= 205)   //se a variável ler for maior ou igual a 0 ou(&&) menor ou igual a 205
digitalWrite(led1,HIGH);     //Atribuirá HIGH(5V) ao led1
else                         //Se não
digitalWrite(led1,LOW);      //Atribuirá LOW(0V) ao led1
 
if(ler > 205 && ler <= 410)
digitalWrite(led2,HIGH);
else
digitalWrite(led2,LOW);
 
if(ler > 410 && ler <= 615)
digitalWrite(led3,HIGH);
else
digitalWrite(led3,LOW);
 
if(ler > 615 && ler <= 820)
digitalWrite(led4,HIGH);
else
digitalWrite(led4,LOW);
 
if(ler > 820 && ler <= 1023)
digitalWrite(led5,HIGH);
else
digitalWrite(led5,LOW);
 
delay(100);      //Cria um intervalo de 100 milissegundos
}
