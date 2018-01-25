// Programa: Semáforo simplificado interativo
// Autor: Gleydson Zeca Monteiro
// Executado: Lucas Barros 25/01/2018yukykjyj


// Definição do tipo de variável e estas aos pinos do Arduino
int carVM = 12;                          // definição da variável carVM como booleana e atribuída ao pino 12
int carAM = 11;                          // definição da variável carAM como booleana e atribuída ao pino 11
int carVD = 10;                          // definição da variável carVD como booleana e atribuída ao pino 10
int pedVM = 9;                           // definição da variável pedVM como booleana e atribuída ao pino 9
int pedVD = 8;                           // definição da variável pedVD como booleana e atribuída ao pino 8
int botao = 2;                           // definição da variável botao como booleana e atribuída ao pino 2
unsigned long tempo;                      // definição da variável tempo para verificar tempo desde que o botão foi pressionado

// Definições dos modos dos pinos
void setup() {                           // início da função setup() a qual não retorna nenhum valor para função
pinMode(carVM, OUTPUT);                  // definição do modo da variável carVM como saída
pinMode(carAM, OUTPUT);                  // definição do modo da variável carAM como saída
pinMode(carVD, OUTPUT);                  // definição do modo da variável carVD como saída
pinMode(pedVM, OUTPUT);                  // definição do modo da variável pedVM como saída
pinMode(pedVD, OUTPUT);                  // definição do modo da variável pedVD como saída
pinMode(botao, INPUT);                   // definição do modo da variável botao como entrada
digitalWrite(carVD, HIGH);               // coloca a variável digital carVD em nível lógico alto, ou seja, acende a luz verde dos carros
digitalWrite(pedVM, HIGH);               // coloca a variável digital pedVM em nível lógico alto, ou seja, acende a luz vermelha dos pedestres
}                                        // fechamento da função setup()


void loop() {                            // abertura da função loop - Laço de repetição do programa 
bool estado = digitalRead(botao);        // definição da variável estado como booleana a qual irá ler a entrada digital botao

  if (estado == HIGH && (millis() - tempo) > 5000)      // verifica se o botão foi pressionado e se transcorreram 5 segundos desde a última vez que isso ocorreu
  {
  semaforo();                            // chama a função semaforo para acender e apagar as luzes na sequencia semafórica
  }                                      // fechamento da função condicional if
}                                        // fechamento da função loop - Laço de repetição do programa


void semaforo() {                        // abertura da função semaforo 
digitalWrite(carVD, LOW);                // coloca a variável digital carVD em nível lógico baixo, ou seja, apaga a luz verde dos carros
digitalWrite(carAM, HIGH);               // coloca a variável digital carAM em nível lógico alto, ou seja, acende a luz verde dos carros
delay(2000);                             // coloca um atraso de 2 segundos
digitalWrite(carAM, LOW);                // coloca a variável digital carAM em nível lógico baixo, ou seja, apaga a luz amarela dos carros
digitalWrite(carVM, HIGH);               // coloca a variável digital carVM em nível lógico alto, ou seja, acende a luz vermelha dos carros
delay(1000);                             // coloca um atraso de 1 segundo, para segurança dos pedestres
digitalWrite(pedVM, LOW);                // coloca a variável digital pedVM em nível lógico baixo, ou seja, apaga a luz vermelha dos pedestres
digitalWrite(pedVD, HIGH);               // coloca a variável digital pedVD em nível lógico alto, ou seja, acende a luz verde dos pedestres
delay(5000);                             // adiciona um atraso equivalente a um intervalo de tempo predefinido para travessia dos pedestres

// pisca o vermelho dos pedestres
digitalWrite(pedVD, LOW);                // coloca a variável digital pedVD em nível lógico baixo, ou seja, apaga a luz verde dos pedestres
for (int x=0; x<10; x++) {               // inicia um laço de repetição 'for' de 0 a 10 incrementado de 1 em 1
digitalWrite(pedVM, HIGH);               // coloca a variável digital pedVM em nível lógico alto, ou seja, acende a luz vermelha dos pedestres
delay(250);                              // coloca um atraso de 250 milisegundos
digitalWrite(pedVM, LOW);                // coloca a variável digital pedVM em nível lógico baixo, ou seja, apaga a luz vermelha dos pedestres
delay(250);                              // coloca um atraso de 250 milisegundos
  }

digitalWrite(pedVM, HIGH);               // coloca a variável digital pedVM em nível lógico alto, ou seja, acende a luz vermelha dos pedestres
delay(500);                              // coloca um atraso de 0,5 segundo
digitalWrite(carVM, LOW);                // coloca a variável digital carVM em nível lógico baixo, ou seja, apaga a luz vermelha dos carros
delay(500);                              // coloca um atraso de 0,5 segundo
digitalWrite(carVD, HIGH);               // coloca a variável digital carVD em nível lógico alto, ou seja, acende a luz verde dos carros
digitalWrite(carAM, LOW);                // coloca a variável digital carAM em nível lógico baixo, ou seja, acende a luz amarela dos carros
tempo = millis();                        // registra o tempo desde a última alteração no semáforo e retorna para o loop principal do programa
}                                        // fechamento da função semaforo 
