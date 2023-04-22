#include <SPI.h>
#include <LoRa.h>
#include <Servo.h>

Servo tailservo;
int amplitude = 5; // create a variable to hold the vehicle amplitude
int offset = 0;
int pin = 3;
int swing_degree = 10; //create a variable to hold the fish's swing degree
bool left_side = true; //used to determine if the tail has reached its maximum on the left point
int servo_pos=swing_degree; //initialize beginning position
int time_delay=25; //used to fine-tune the delay
bool state=false;

void setup() {
  Serial.begin(9600); // initialize serial communication
  while (!Serial);

  if (!LoRa.begin(433E6)) { // initialize LoRa module
    Serial.println("LoRa initialization failed.");
    while (1);
  }
  Serial.println("LoRa Receiver initialization successful.");
  tailservo.attach(pin);  // attaches the servo on pin 3 to the servo object
}

void loop() {
  if (LoRa.parsePacket()) { // if there is LoRa packet received
    String incoming = "";
    while (LoRa.available()) {
      incoming = String(LoRa.read()); // read the incoming string
    }
    incoming.trim();
    Serial.print("Received: ");
    Serial.println(incoming);
    Serial.println(state);

//code to change behavior of fish based on user input
    if (incoming == "ww") { 
      state = true;
    } else if (incoming == "ss") {
      state = false;
    } else if (incoming[0]=="d"){
      swing_degree=incoming.substring(0,2).toInt();
      servo_pos=swing_degree;
      Serial.println("New swing degree: ");
      Serial.print(swing_degree);
      tailservo.write(90);
      delay(time_delay);
    } else if (incoming[0]=="a") {
      amplitude=incoming.substring(0,2).toInt();
      servo_pos=swing_degree;
      Serial.println("New amplitude: ");
      Serial.print(amplitude);
      tailservo.write(90);
      delay(time_delay);
    } else if (incoming[0]=="t") {
      time_delay=incoming.substring(0,2).toInt();
      servo_pos=swing_degree;
      Serial.println("New time delay: ");
      Serial.print(time_delay);
      tailservo.write(90);
      delay(time_delay);      
    }
  }
//code to turn servo on or off by changing the state boolean
  if (state) {
    flapping();
  } else {
    servo_pos=swing_degree;
    tailservo.write(90);
    delay(time_delay);
  }
}

//code to move the servo
void flapping(){
  if(servo_pos>=180-swing_degree+offset){
    left_side=false;        
  } else if (servo_pos<=swing_degree+offset) {
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