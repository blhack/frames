#include <Adafruit_NeoPixel.h>
/*LEDS are connected to the 5V pin on the arduino, which has a max rated [nominal] current of 500ma.
 * Each pixel draws a maximum of 60ma, thus THERE SHOULD NEVER BE MORE THAN 9 PIXELS AT FULL BRIGHTNESS
 * USE THE blackOut() function liberally!
 * 
  */

#define PIN 6
#define NUM_LEDS 180

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

short framePixels[18] = {255, 0, 0,
                        255, 255, 0,
                        0, 0, 255,
                        0, 255, 0,
                        255, 0, 0,
                        0, 255, 0};


void blackOut() {
  for (int i=0; i<NUM_LEDS; i++) {
    strip.setPixelColor(i, 0,0,0);
  }
  strip.show();
}

void frame(int index) {
  blackOut();
  
  short pixelIndex = 0; 
  short pixelStart = 0;
  for (int i=index-1; i<180; i+=60) {
    pixelStart = pixelIndex * 3;
    strip.setPixelColor(i, framePixels[pixelStart],framePixels[pixelStart+1],framePixels[pixelStart+2]);
    pixelIndex+=2;
  }
  pixelIndex = 1;
  for (int i=60-index; i<180; i+=60){
    pixelStart = pixelIndex * 3;
    strip.setPixelColor(i, framePixels[pixelStart],framePixels[pixelStart+1],framePixels[pixelStart+2]);
    pixelIndex+=2;
  }
  strip.show();
}

void generateFrame() {
  //modify the global framePixels in here.
}

void setup() {
  strip.begin();
  Serial.begin(9600);
}

void loop() {

  generateFrame();
  
  for (int i=1; i<30; i++) {
    frame(i);
    delay(10);
  }
  delay(1);
}
