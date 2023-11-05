#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define LED_COUNT 16

const byte numChars = 3;
char receivedChars[numChars];  
char tempChars[numChars];  

char messageFromPC[numChars] = {0};
int integerFromPC = 0;
float floatFromPC = 0.0;

int R = 0;
int G = 0;
int B = 0;
int W = 0;

boolean newData = false;

Adafruit_NeoPixel ring(LED_COUNT, LED_PIN, NEO_RGBW + NEO_KHZ800);

void recvWithEndMarker() {
    static byte ndx = 0;
    char endMarker = '\n';
    char rc;
    
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (rc != endMarker) {
            receivedChars[ndx] = rc;
            ndx++;
            if (ndx >= numChars) {
                ndx = numChars - 1;
            }
        }
        else {
            receivedChars[ndx] = '\0'; // terminate the string
            ndx = 0;
            newData = true;
        }
    }
}

void showNewData() {
    if (newData == true) {
        Serial.print("This just in ... ");
        Serial.println(receivedChars);
        newData = false;
    }
}


void setup() {
  ring.begin();           
  ring.show();  
  ring.setBrightness(50);
  Serial.begin(9600);
}

void loop() {
    recvWithEndMarker();
    showNewData();

    R = int(receivedChars[0]) + int(receivedChars[1]) ;
    Serial.println(R);


    ring.setPixelColor(1, R, G, B, W);
    ring.show();
  }
    
