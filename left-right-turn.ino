#include <Servo.h>
#include<Wire.h>

Servo tailservo;
int amplitude = 5; // create a variable to hold the vehicle amplitude
int offset = 0;
int pin = 3;
int swing_degree = 30; //create a variable to hold the fish's swing degree
bool left_side = true; //used to determine if the tail has reached its maximum on the left point
int servo_pos=swing_degree; //initialize beginning position
int time_delay=20; //used to fine-tune the delay
bool turn_left=false;
bool turn_right=true;


void setup() {
    tailservo.attach(pin);
    tailservo.write(90);
}

void loop() {
  if (turn_left) {
    offset = 30;
  } else if (turn_right) {
    offset = -30;
  }

  if(servo_pos >= (180-swing_degree)+offset){
    left_side=false;        
  } else if (servo_pos <= swing_degree+offset) {
    left_side=true;
  }

  if(left_side) {
    servo_pos += amplitude;
    tailservo.write(servo_pos);
    delay(time_delay);
  } else {
    servo_pos -= amplitude;
    tailservo.write(servo_pos);
    delay(time_delay);
  }    
}
