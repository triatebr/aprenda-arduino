int LED = 13; // Pino no qual o LED está conectado
void setup() {
 pinMode(LED, OUTPUT); // Definir o pino como saída
}
void loop() {
 digitalWrite(LED, HIGH); // Colocar nível 1 no pino (acende o LED)
 delay(2000); // Aguardar por 2 segundos
 digitalWrite(LED, LOW); // Colocar nível 0 no pino (apaga o LED)
 delay(2000);
}
