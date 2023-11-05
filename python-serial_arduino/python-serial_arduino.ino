#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define LED_COUNT 16
Adafruit_NeoPixel ring(LED_COUNT, LED_PIN, NEO_RGBW + NEO_KHZ800);

SoftwareSerial BT(0,1);

#define BUFFER_SIZE 64
char inData[BUFFER_SIZE];//This is a character buffer where the data sent by the python script will go.
char inChar=-1;//Initialie the first character as nothing
int count=0;//This is the number of lines sent in from the python script
int i=0;

void setup()
{
  ring.begin();           
  ring.show();  
  ring.setBrightness(50);
  Serial.begin(9600);
  BT.begin(9600);
  BT.println("Hello!");
  Serial.println("Beginning Connection");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(BT.available()) {
    char out=BT.read();
    //Serial.println(out);
    for (int i=0; i<=16; i++) {
        ring.setPixelColor(i, 255, 255, 255, 0);  
      }
      ring.show();
    BT.write("W");
  }
}
