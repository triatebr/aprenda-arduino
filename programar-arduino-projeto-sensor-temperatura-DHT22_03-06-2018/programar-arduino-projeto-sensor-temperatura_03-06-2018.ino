#include <DHT.h>
 
int Sensor = 2;  //Pino onde está ligado o sensor DHT22    
DHT dht(Sensor, DHT22); //Esta instrução indica qual à biblioteca qual o modelo do sensor utilizado
float temperatura; // Variável que nos irá mostrar a temperatura 
float humidade; // Variável que nos irá mostrar a humidade
 
 
void setup() {
 
  Serial.begin(9600);// Sincronizar a porta serial a 9600 bits por segundo
  pinMode(Sensor, INPUT); // Definir o nosso sensor como INPUT
  dht.begin();// Esta instrução é necessária, para que o nosso sensor possa estar pronto para ser utilizado
}
 
void loop() {
 
  temperatura = dht.readTemperature(); // Esta instrução permite que o sensor guarde a leitura da temperatura na variável
  humidade = dht.readHumidity(); // Esta instrução permite que o sensor guarde a leitura da humidade na variável
  delay(5000); // Para o programa durante 2000 milissegundos;
 
// Escreve para a porta serial a temperatura e a humidade:
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print("c Humidade: ");
  Serial.print(humidade);
  Serial.println("%");
}
