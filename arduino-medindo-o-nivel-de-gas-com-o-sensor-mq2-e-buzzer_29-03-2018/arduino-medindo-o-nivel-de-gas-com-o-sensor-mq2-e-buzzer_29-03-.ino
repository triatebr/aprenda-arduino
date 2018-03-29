int Pinbuzzer = 8; //PINO UTILIZADO PELO BUZZER
int PinA0 = A0;//PINO UTILIZADO PELO SENSOR DE GÁS MQ-2

int leitura_sensor = 300;//DEFININDO UM VALOR LIMITE (NÍVEL DE GÁS NORMAL)

void setup(){
pinMode(PinA0, INPUT); //DEFINE O PINO COMO ENTRADA
pinMode(Pinbuzzer, OUTPUT); //DEFINE O PINO COMO SAÍDA
Serial.begin(9600);//INICIALIZA A SERIAL
}
void loop(){
int valor_analogico = analogRead(PinA0); //VARIÁVEL RECEBE O VALOR LIDO NO PINO ANALÓGICO
Serial.print("Leitura: "); //EXIBE O TEXTO NO MONITOR SERIAL
Serial.println(valor_analogico);// MOSTRA NO MONITOR SERIAL O VALOR LIDO DO PINO ANALÓGICO
 if (valor_analogico > leitura_sensor){//SE VALOR LIDO NO PINO ANALÓGICO FOR MAIOR QUE O VALOR LIMITE, FAZ 
 digitalWrite(Pinbuzzer, HIGH); //ATIVA O BUZZER E O MESMO EMITE O SINAL SONORO
 }else{ //SENÃO, FAZ
 digitalWrite(Pinbuzzer, LOW);//BUZZER DESLIGADO
 }
 delay(100); //INTERVALO DE 100 MILISSEGUNDOS
}
