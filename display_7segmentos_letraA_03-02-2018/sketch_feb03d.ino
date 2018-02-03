int SEG_A = 2;
int SEG_B = 3;
int SEG_C = 4;
int SEG_D = 5;
int SEG_E = 6;
int SEG_F = 7;
int SEG_G = 8;
int PONTO = 9;
int ATRASO = 1000;
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
 // Para displays de catodo comum:
 digitalWrite(SEG_A, HIGH);
 digitalWrite(SEG_B, HIGH);
 digitalWrite(SEG_C, HIGH);
 digitalWrite(SEG_E, HIGH);
 digitalWrite(SEG_F, HIGH);
 digitalWrite(SEG_G, HIGH);
 // Para displays de anodo comum:
 // digitalWrite(SEG_A, LOW);
 // digitalWrite(SEG_B, LOW);
 // digitalWrite(SEG_C, LOW);
 // digitalWrite(SEG_E, LOW);
 // digitalWrite(SEG_F, LOW);
 // digitalWrite(SEG_G, LOW);
 delay(ATRASO);
}
