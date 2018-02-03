int SEG_A = 2;
int SEG_B = 3;
int SEG_C = 4;
int SEG_D = 5;
int SEG_E = 6;
int SEG_F = 7;
int SEG_G = 8;
int PONTO = 9;
int ATRASO = 150;
void setup() {
 for (int pino = SEG_A; pino <= PONTO; pino++) {
 pinMode(pino, OUTPUT);
 // Para displays de catodo comum:
 digitalWrite(pino, LOW);
 // Para displays de anodo comum:
 // digitalWrite(pino, HIGH);
 }
}
void loop() {
 for (int pino = SEG_A; pino < SEG_G; pino++) {
 // Para displays de catodo comum:
 digitalWrite(pino, HIGH);
 // Para displays de anodo comum:
 // digitalWrite(pino, LOW);
 if (pino > SEG_A) {
 // Para displays de catodo comum:
 digitalWrite(pino - 1, LOW);
 // Para displays de anodo comum:
 // digitalWrite(pino - 1, HIGH);
 }
 else {
 // Para displays de catodo comum:
 digitalWrite(SEG_F, LOW);
 // Para displays de anodo comum:
 // digitalWrite(SEG_F, HIGH);
 }
 delay(ATRASO);
 }
}
