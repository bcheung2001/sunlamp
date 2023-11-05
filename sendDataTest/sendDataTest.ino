#include <Adafruit_NeoPixel.h>

#define LED_PIN 6
#define LED_COUNT 16

const byte numChars = 32;
char receivedChars[numChars];
char tempChars[numChars];        

// variables to hold the parsed data
int R = 0;
int G = 0;
int B = 0;

boolean newData = false;

Adafruit_NeoPixel ring(LED_COUNT, LED_PIN, NEO_RGBW + NEO_KHZ800);


//============

void setup() {
    ring.begin();           
    ring.show();  
    ring.setBrightness(50); 
    Serial.begin(9600);
    Serial.println();
}

//============

void loop() {
    recvWithStartEndMarkers();
    if (newData == true) {
        strcpy(tempChars, receivedChars);
            // this temporary copy is necessary to protect the original data
            //   because strtok() used in parseData() replaces the commas with \0
        parseData();
        updateRing();
        newData = false;
    }
}

//============

void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;

    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

//============

void parseData() {      // split the data into its parts

    char * strtokIndx; // this is used by strtok() as an index
 
    strtokIndx = strtok(tempChars, ","); // this continues where the previous call left off
    R = atoi(strtokIndx);     // convert this part to an integer

    strtokIndx = strtok(NULL, ",");
    G = atoi(strtokIndx);     // convert this part to a float

    strtokIndx = strtok(NULL, ",");
    B = atoi(strtokIndx);     // convert this part to a float

}

//============

void updateRing() {

    ring.setPixelColor(1, R, G, B, 0);
    ring.show();
  
    Serial.print("Red");
    Serial.println(R);
    Serial.print("Green");
    Serial.println(G);
    Serial.print("Blue");
    Serial.println(B);


    
}
