/* Code starts from here */

const int led[]={4,5,6,7,8,9,10,11,12,13},d=5;

void setup() {
  for(int i=0;i<10;i++)
    pinMode(led[i],OUTPUT);
}

void loop() {
  for(int i=0;i<10;i++)
    {
    digitalWrite(led[i],HIGH);
    delay(d);
    digitalWrite(led[i],LOW);
    }

  for(int j=0;j<8;j++)
    {
    digitalWrite(led[8-j],HIGH);
    delay(d);
    digitalWrite(led[8-j],LOW);
    }
}

/* Code ends here */
