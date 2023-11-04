#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(0,1);

#define ledPin 13
char state;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
  BT.begin(9600); // Default communication rate of the Bluetooth module
}

void loop() {
  if(BT.available()){ // Checks whether data is coming from the serial port
    state = BT.read(); // Reads the data from the serial port
    BT.print(state);
    //digitalWrite(ledPin, HIGH);

    if (state == '0') {
      digitalWrite(ledPin, LOW); // Turn LED OFF
      //BT.print("LED: OFF"); // Send back, to the phone, the String "LED: ON"
      //state = 0;
    }
    else if (state == '1') {
      digitalWrite(ledPin, HIGH);
      //BT.print("LED: ON");
      //state = 1;
    } 
    else{
      BT.print("Invalid syntax");
    }
  }
}

