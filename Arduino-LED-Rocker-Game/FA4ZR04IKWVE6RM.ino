
int LEDpos = 1 ;
int leds[] = {1,2,3,4,5,6,7,8,9};
int ledStateA = LOW;
int var=10;
int status=0;
int button=13;
int lives =3;

// ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated

long interval = 500;           // interval at which to blink (milliseconds)

void setup() {
  
  //All LEDs are set as output
  for(int a=2;a<11;a++){
     pinMode(a, OUTPUT);
  } 
  
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop()
{
  
  if(lives==0)    //Setting starting interval
  {
    interval=500;
   
  }
  
  

 //Detect if button is pressed 
 if(digitalRead(button)== LOW )
   {
    Serial.println("pressed");
       if(LEDpos==6)   // Button was pressed at the middle LED !!
          {
               interval/=1.5;               // Reduce interval ; LED blink faster
               
               //Blink Middle LED twice for user to notice he won!
               digitalWrite(6,HIGH);
               delay(200);
               digitalWrite(6,LOW);
               delay(200);
               digitalWrite(6,HIGH);
               delay(200);
               digitalWrite(6,LOW);
               
               Serial.println("LEVEL UP");
           }
            
       else // Button was pressed but not at the middle LED :(
         {    delay(200);
              digitalWrite(leds[1], HIGH);
              lives--;    // user Lost a life
         }
       if(lives==0){
        interval= 500;
        Serial.println("GAME OVER");
       }
    }
  
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {
    
    
    if(status==0) { 
      if (LEDpos> 9 )
        status=1;
      else
        LEDpos++;
     }
    
    
    if(status==1)  //Reached the start
    {  if (LEDpos<3)
         status=0;
       else
         {   LEDpos--;
             if(LEDpos == 2)
             status=0;
         }
    }
    
    
     
     // save the last time you blinked the LED 
    previousMillis = currentMillis;   
     
      //Turn off all LEDs
for (int x = 2; x <= 10;x++)
{
  digitalWrite(x, LOW);
}

//Turn on the LED
digitalWrite(LEDpos , HIGH);
}

  }


