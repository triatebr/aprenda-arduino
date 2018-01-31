int const rPotPin = A2;
int const gPotPin = A1;
int const bPotPin = A0;

int const rOutPin = 3;
int const gOutPin = 5;
int const bOutPin = 6;

int rVal;
int gVal;
int bVal;

void setup()
{
  pinMode(rOutPin, OUTPUT);
  pinMode(gOutPin, OUTPUT);
  pinMode(bOutPin, OUTPUT);
}

void loop()
{
  rVal = analogRead(rPotPin) / 4;
  gVal = analogRead(gPotPin) / 4;
  bVal = analogRead(bPotPin) / 4;

  analogWrite(rOutPin, rVal);
  analogWrite(gOutPin, gVal);
  analogWrite(bOutPin, bVal);
}

