/*******************************************************************************
*
*    Projeto 07 – Código S.O.S
*                   http://squids.com.br/arduino
*
*******************************************************************************/
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
 
// roda uma vez quando resetada:
void setup() {
  // inicializa o pino digital como SAÍDA do microcontrolador
  pinMode(led, OUTPUT);
}
 
// rotina de loop - roda indefinitivamente:
void loop() {
  // 3 pontos (letra S)
  for (int x=0; x<3; x++) {
  digitalWrite(led, HIGH);   // acende o LED on (HIGH is the voltage level)
  delay(150);               // espera por 150 ms
  digitalWrite(led, LOW);    // apaga o LED (the voltage LOW)
  delay(100);               // espera por 100ms
  }
   
  delay(200); // espera de 200ms entre as letras
   
  // 3 traços (letra O)
  for (int x=0; x<3; x++) {
   digitalWrite(led, HIGH);
   delay(400);
   digitalWrite(led, LOW);
   delay(100);
  }
 
  delay(200); //espera 200 ms entre as letras
   
  // 3 pontos (letra S)
  for (int x=0; x<3; x++) {
  digitalWrite(led, HIGH);   // acende o LED on (HIGH is the voltage level)
  delay(150);               // espera por 150 ms
  digitalWrite(led, LOW);    // apaga o LED (the voltage LOW)
  delay(100);               // espera por 100ms
  }
   
  //espera 3 segundos para repetir o sinal S.O.S
  delay(3000);
   
}
