// Program to show full catalog of the MD_Parola animations
//
// NOTE: MD_MAX72xx library must be installed and configured for the LED
// matrix type being used. Refer documentation included in the MD_MAX72xx
// library or see this link:
// https://majicdesigns.github.io/MD_MAX72XX/page_hardware.html
//

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
#define MAX_DEVICES 4
#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

// Hardware SPI connection
MD_Parola P = MD_Parola(CS_PIN, MAX_DEVICES);
// Arbitrary output pins
// MD_Parola P = MD_Parola(DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

#define ARRAY_SIZE(x)  (sizeof(x)/sizeof(x[0]))

// Global data
typedef struct
{
  textEffect_t  effect;   // text effect to display
  char *        psz;      // text string nul terminated
  uint16_t      speed;    // speed multiplier of library default
  uint16_t      pause;    // pause multiplier for library default
} sCatalog;

sCatalog  catalog[] =
{
    { PA_SLICE, "ASSALTO", 1, 1 },
    { PA_SLICE, "NESSE", 1, 1 },
    { PA_SLICE, "CARRO", 1, 1 },
    { PA_SLICE, "AJUDE-ME!", 1, 1 },
    
 
};

int button=2;
int buttonState=0;

void setup(void)
{
  pinMode(button, INPUT);
  P.begin();
  P.setInvert(false);

  for (uint8_t i=0; i<ARRAY_SIZE(catalog); i++)
  {
    catalog[i].speed *= P.getSpeed();
    catalog[i].pause *= 500;
  }
}

void loop(void)
{
  buttonState=digitalRead(button);
  if(buttonState==1){
  
  for (uint8_t j=0; j<3; j++)
  {
    textPosition_t  just;

    switch (j)
    {
    case 0: just = PA_LEFT;    break;
    case 1: just = PA_CENTER;  break;
    case 2: just = PA_RIGHT;   break;
    }

    for (uint8_t i=0; i<ARRAY_SIZE(catalog); i++)
    {
      P.displayText(catalog[i].psz, just, catalog[i].speed, catalog[i].pause, catalog[i].effect, catalog[i].effect);

      while (!P.displayAnimate())
        ; // animates and returns true when an animation is completed

      delay(catalog[i].pause);
    }
  }
  }
}
