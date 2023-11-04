#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>

#define LED_PIN 6
#define LED_COUNT 16
Adafruit_NeoPixel ring(LED_COUNT, LED_PIN, NEO_RGBW + NEO_KHZ800);

char state;
SoftwareSerial BT(0,1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BT.begin(9600);
  ring.begin();           
  ring.show();  
  ring.setBrightness(50);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BT.available()){ // Checks whether data is coming from the serial port
    state = BT.read(); // Reads the data from the serial port
    BT.print(state);
    //digitalWrite(ledPin, HIGH);

    if (state == '0') {
      for (int i=0; i<=16; i++) {
        ring.setPixelColor(i, 0, 0, 0, 0);  
      }
      ring.show();
    }

    else if (state == '1') {
      for (int i=0; i<=16; i++) {
        ring.setPixelColor(i, 255, 255, 255, 0);  
      }
      ring.show();
    } 
  }
}
