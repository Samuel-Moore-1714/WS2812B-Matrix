#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      256

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 10; // delay for half a second

void setup() 
{
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {

  for(int i=0;i<NUMPIXELS;i++)
  {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(10,0,0)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(250);
  }

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  // for(int i=0;i<NUMPIXELS;i++)
  // {
  //   // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
  //   pixels.setPixelColor(i, pixels.Color(10,0,0)); // Moderately bright green color.
  //   pixels.show(); // This sends the updated pixel color to the hardware.
  //   //delay(delayval);
  // }
  // delay(1000);
  // for(int i=0;i<NUMPIXELS;i++)
  // {
  //   // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
  //   pixels.setPixelColor(i, pixels.Color(0,10,0)); // Moderately bright green color.
  //   pixels.show(); // This sends the updated pixel color to the hardware.
  //   //delay(delayval);
  // }
  // delay(1000);
  // for(int i=0;i<NUMPIXELS;i++)
  // {
  //   // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
  //   pixels.setPixelColor(i, pixels.Color(0,0,10)); // Moderately bright green color.
  //   pixels.show(); // This sends the updated pixel color to the hardware.
  //   //delay(delayval);
  // }
  // delay(1000);
}