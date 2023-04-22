int redPin = 8;
int greenPin = 7;
int bluePin = 6;
int pinREAD=A2;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  int value = analogRead(pinREAD);
  float volt = value * 5.0 / 1023.0;
  if (value < 4.3) {
    analogWrite(redPin, 255);
  }
}
