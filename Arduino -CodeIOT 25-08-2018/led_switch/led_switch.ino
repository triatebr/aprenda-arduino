int led = 9;
int botao = 6;
int leitura = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);
  Serial.begin(9600);
}

void loop() {
  leitura = digitalRead(botao);
  Serial.println(leitura);

  if (leitura == 1) {
    digitalWrite(led, 1);
  }
  if (leitura == 0) {
    digitalWrite(led, 0);
  }

}
