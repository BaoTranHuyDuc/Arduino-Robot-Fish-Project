int pinLED = 4;
int pinREAD=A3;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(pinLED, OUTPUT);
  Serial.begin(9600);
  digitalWrite(pinLED, HIGH);
}

// the loop function runs over and over again forever
void loop() {
  int value = analogRead(pinREAD);
  float volt = value * 5.0 / 1023.0;
  if (value < 2) {
    digitalWrite(pinLED, LOW);
  }
}
