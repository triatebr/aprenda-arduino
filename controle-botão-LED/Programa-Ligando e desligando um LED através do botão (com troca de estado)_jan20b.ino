int LED = 9; // Pino no qual o LED está conectado
int BOTAO = 7; // Pino no qual o Botão está conectado
int valor;
int anterior = 0;
int estado = LOW;
void setup() {
 pinMode(LED, OUTPUT); // Definir o pino como saída
 pinMode(BOTAO, INPUT); // Definir o pino com entrada
}
void loop() {
 valor = digitalRead(BOTAO);
 if (valor == HIGH && anterior == LOW) {
 estado = !estado;
 }
 digitalWrite(LED, estado);
 anterior = valor;
 delay (50);
}
