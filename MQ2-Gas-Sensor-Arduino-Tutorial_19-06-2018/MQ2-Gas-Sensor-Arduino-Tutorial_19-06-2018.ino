/* Testing MQ-2 GAS sensor with serial monitor
   Suitable for detecting of LPG, i-butane, propane, methane ,alcohol, Hydrogen or smoke
   More info: http://www.ardumotive.com/how-to-use-mq2-gas-sensor-en.html
   Dev: Michalis Vasilakis // Date: 11/6/2015 // www.ardumotive.com                     */

const int gasPin = A0; //GAS sensor output pin to Arduino analog A0 pin


void setup()
{
  Serial.begin(9600); //Initialize serial port - 9600 bps
}

void loop()
{
  Serial.println("Gas Inflamável e Fumaça:");
  Serial.println(analogRead(gasPin));
  delay(5000); // Print value every 5 sec.
}

