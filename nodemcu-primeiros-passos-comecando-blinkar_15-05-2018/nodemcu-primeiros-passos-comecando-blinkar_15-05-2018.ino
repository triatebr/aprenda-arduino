int ledState = LOW;     
const int ledPin = 13;

unsigned long previousMillis = 0;
const long interval = 4000;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;   
    if (ledState == LOW)
      ledState = HIGH;  
    else
      ledState = LOW;  
    digitalWrite(ledPin, ledState);
  }
}
