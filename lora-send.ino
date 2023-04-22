#include <SPI.h>
#include <LoRa.h>

void setup() {
  Serial.begin(9600); // initialize serial communication
  while (!Serial);

  if (!LoRa.begin(433E6)) { // initialize LoRa module
    Serial.println("LoRa initialization failed.");
    while (1);
  }
  LoRa.setSyncWord(0xF3);   
  Serial.println("LoRa Sender initialization successful.");
}

void loop() {
  if (Serial.available()) { // if there is serial data available
    char input = Serial.read(); // read the incoming byte
    switch (input) {
      case 'w': // move the servo up
        LoRa.beginPacket();
        LoRa.print("w");
        LoRa.endPacket();
        Serial.println("Sent: w");
        break;
      case 'e': // move the servo down
        LoRa.beginPacket();
        LoRa.print("e");
        LoRa.endPacket();
        Serial.println("Sent: e");
        break;
      case 's': // move the servo down
        LoRa.beginPacket();
        LoRa.print("s");
        LoRa.endPacket();
        Serial.println("Sent: s");
        break;
      case 'd': // move the servo down
        LoRa.beginPacket();
        LoRa.print("d");
        LoRa.endPacket();
        Serial.println("Sent: d");
        break;
      case 'x': // move the servo down
        LoRa.beginPacket();
        LoRa.print("x");
        LoRa.endPacket();
        Serial.println("Sent: x");
        break;
      case 'c': // move the servo down
        LoRa.beginPacket();
        LoRa.print("c");
        LoRa.endPacket();
        Serial.println("Sent: c");
        break;
      case 'b': // move the servo down
        LoRa.beginPacket();
        LoRa.print("b");
        LoRa.endPacket();
        Serial.println("Sent: b");
        break;
      case 'n': // move the servo down
        LoRa.beginPacket();
        LoRa.print("n");
        LoRa.endPacket();
        Serial.println("Sent: n");
        break;
      case 'u': // move the servo down
        LoRa.beginPacket();
        LoRa.print("u");
        LoRa.endPacket();
        Serial.println("Sent: u");
        break;
      case 'i': // move the servo down
        LoRa.beginPacket();
        LoRa.print("i");
        LoRa.endPacket();
        Serial.println("Sent: i");
        break;
      case 'o': // move the servo down
        LoRa.beginPacket();
        LoRa.print("o");
        LoRa.endPacket();
        Serial.println("Sent: 0");
        break;
      case 'p': // move the servo down
        LoRa.beginPacket();
        LoRa.print("p");
        LoRa.endPacket();
        Serial.println("Sent: p");
        break;
    }
  }
}
