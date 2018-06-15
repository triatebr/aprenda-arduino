/*  ___   ___  ___  _   _  ___   ___   ____ ___  ____  
 * / _ \ /___)/ _ \| | | |/ _ \ / _ \ / ___) _ \|    \ 
 *| |_| |___ | |_| | |_| | |_| | |_| ( (__| |_| | | | |
 * \___/(___/ \___/ \__  |\___/ \___(_)____)___/|_|_|_|
 *                  (____/    
 *  project tutorial url:http://osoyoo.com/?p=1215   
 *  copyright osoyoo.com
 */ 
const int AOUTpin=0;//the AOUT pin of the CO sensor goes into analog pin A0 of the arduino
const int DOUTpin=8;//the DOUT pin of the CO sensor goes into digital pin D8 of the arduino
const int ledPin=13;//the anode of the LED connects to digital pin D13 of the arduino

int limit;
int value;

void setup() {
  Serial.begin(9600);//sets the baud rate
  pinMode(DOUTpin, INPUT);//sets the pin as an input to the arduino
  pinMode(ledPin, OUTPUT);//sets the pin as an output of the arduino
}

void loop()
{
  value= analogRead(AOUTpin);//reads the analaog value from the CO sensor's AOUT pin
  limit= digitalRead(DOUTpin);//reads the digital value from the CO sensor's DOUT pin
  Serial.print("CO value: ");
  Serial.println(value);//prints the CO value
  Serial.print("Limit: ");
  Serial.println(limit);//prints the limit reached as either LOW or HIGH (above or underneath)
  delay(5000);
  if (limit == HIGH){
    digitalWrite(ledPin, HIGH);//if limit has been reached, LED turns on as status indicator
  }
  else{
    digitalWrite(ledPin, LOW);//if threshold not reached, LED remains off
  }
}

