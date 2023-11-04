char incomingValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);

}

void loop() {
  if (Serial.available() > 0){
    incomingValue = Serial.read();
    Serial.print(incomingValue);
    Serial.print("\n");
    if (incomingValue == '1')
      digitalWrite(13, HIGH);
    if (incomingValue == '0')
      digitalWrite(13, LOW);
  }

}
