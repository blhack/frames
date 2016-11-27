#include <Adafruit_NeoPixel.h>
/*LEDS are connected to the 5V pin on the arduino, which has a max rated [nominal] current of 500ma.
 * Each pixel draws a maximum of 60ma, thus THERE SHOULD NEVER BE MORE THAN 9 PIXELS AT FULL BRIGHTNESS
 * USE THE blackOut() function liberally!
 * 
  */

#define PIN 6
#define NUM_LEDS 180

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void blackOut() {
  for (int i=0; i<NUM_LEDS; i++) {
    strip.setPixelColor(i, 0,0,0);
  }
  strip.show();
}

void frame(int index, int r, int g, int b) {
  blackOut();
  for (int i=index-1; i<180; i+=60) {
    strip.setPixelColor(i, 50,50,255);
  }
  for (int i=60-index; i<180; i+=60){
    strip.setPixelColor(i, 50,50,255);
  }
  strip.show();
}

void setup() {
  strip.begin();
  Serial.begin(9600);
}

void loop() {
  for (int i=1; i<30; i++) {
    frame(i, 50, 50, 255);
    delay(10);
  }
  delay(1);
}
