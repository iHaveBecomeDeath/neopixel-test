#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIXELPIN       13
#define NUMPIXELS      16
int delayval = 400;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIXELPIN, NEO_GRB + NEO_KHZ800);
int j = 1;

void setup() {
  // put your setup code here, to run once:
  //pinMode(13, OUTPUT);
  pixels.begin();
}

void loop() {
  for(int i=0; i<NUMPIXELS; i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    int r = 5*i + 5*j;
    int g = j*10;
    int b = 10*j - (i*2);
    pixels.setPixelColor(i, pixels.Color(r, g, b));
    
    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval);
  }
  pixels.clear();
  if (j <= 24){
    j++;
  } else {
    j = 1;
  }
}
