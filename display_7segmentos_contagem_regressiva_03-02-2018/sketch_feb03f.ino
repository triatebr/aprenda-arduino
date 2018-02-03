// Matriz com os dígitos de 0 a 9.
byte digitos[10][7] = {
 { 1,1,1,1,1,1,0 }, // = 0
 { 0,1,1,0,0,0,0 }, // = 1
 { 1,1,0,1,1,0,1 }, // = 2
 { 1,1,1,1,0,0,1 }, // = 3
 { 0,1,1,0,0,1,1 }, // = 4
 { 1,0,1,1,0,1,1 }, // = 5
 { 1,0,1,1,1,1,1 }, // = 6
 { 1,1,1,0,0,0,0 }, // = 7
 { 1,1,1,1,1,1,1 }, // = 8
 { 1,1,1,0,0,1,1 } // = 9
};
void setup() {
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 pinMode(6, OUTPUT);
 pinMode(7, OUTPUT);
 pinMode(8, OUTPUT);
 pinMode(9, OUTPUT); 
  pontoDecimal(false);
}
void pontoDecimal(boolean ponto) {
 digitalWrite(9, ponto);
}
void escrever(int digito) {
 int pino = 2;
 for (int segmento = 0; segmento < 7; segmento++) {
 // Para Catodo Comum:
 digitalWrite(pino, digitos[digito][segmento]);
 // Para Anodo Comum - apenas inverter o valor através do operador not (!):
 // digitalWrite(pino, !digitos[digito][segmento]);
 pino++;
 }
 pontoDecimal(false);
}
void limpar() {
 byte pino = 2;
 for (int segmento = 0; segmento < 7; segmento++) {
 // Para Catodo Comum:
 digitalWrite(pino, LOW);
 // Para Anodo Comum:
 // digitalWrite(pino, HIGH);
 pino++;
 }
}
void loop() {
 for (int cont = 9; cont >= 0; cont--) {
 escrever(cont);
 boolean ponto = true;
 for (int i = 0; i < 4; i++) {
 delay(250);
 pontoDecimal(ponto);
 ponto = !ponto;
 }
 }
 limpar();
 delay(1000);
}
