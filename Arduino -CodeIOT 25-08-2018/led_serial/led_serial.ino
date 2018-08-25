int led = 9;
int led2 = 10;
int led3 = 11;
int led4 = 12;
int botao = 6;
int botao2 = 5;
int bota3 = 7;
int frequencia = 0;
int Pinofalante = 8;
int buzzer = 8;
#define tempo 10


//Variável leitura mudou de "int" para "char"
char leitura;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(Pinofalante,OUTPUT); //Pino do buzzer
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(botao, INPUT);
  pinMode(buzzer,OUTPUT);   
  Serial.begin(9600);
}

void loop() {
  while (Serial.available()) {
    leitura = Serial.read();
    Serial.println(leitura);

//Variáveis do tipo char são caracteres e não números, por isso os ' '
    if (leitura == 'A') {
      digitalWrite(led, 1);
      digitalWrite(led2, 0);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);
       }
    if (leitura == 'a') {
      digitalWrite(led, 0);
      digitalWrite(led2, 1);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);
       }
    if (leitura == 'B') {
      digitalWrite(led, 0);
      digitalWrite(led2, 0);
      digitalWrite(led3, 1);
      digitalWrite(led4, 0);
    }
      if (leitura == 'b') {
      digitalWrite(led, 0);
      digitalWrite(led2, 0);
      digitalWrite(led3, 0);
      digitalWrite(led4, 1);
    }
    if (leitura == 'C') {
      digitalWrite(led, 0);
      digitalWrite(led2, 0);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);
    }
      if (leitura == 'c') {
      digitalWrite(led, 0);
      digitalWrite(led2, 0);
      digitalWrite(led3, 0);
      digitalWrite(led4, 0);
      noTone(buzzer);
    }
      if (leitura == 'd'){
        for (frequencia = 150; frequencia < 1800; frequencia += 1) 
         {
           tone(Pinofalante, frequencia, tempo); 
           delay(2);    
           noTone(buzzer); 
          }
        for (frequencia = 1800; frequencia > 150; frequencia -= 1) 
          {
            tone(Pinofalante, frequencia, tempo); 
           delay(2);    
           noTone(buzzer); 
          }                
        }


    
  }
}

