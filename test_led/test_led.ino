#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define LED_COUNT 16

Adafruit_NeoPixel ring(LED_COUNT, LED_PIN, NEO_RGBW + NEO_KHZ800);

void setup() {
  ring.begin();           
  ring.show();  
  ring.setBrightness(50);
}

void loop() {
  for (int i=0; i<=16; i++) {
    ring.setPixelColor(i, 255, 255, 255, 0);  
  }
  ring.show(); 
     
}
