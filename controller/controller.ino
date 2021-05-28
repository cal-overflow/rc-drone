// Transmitter (Controller)
#include <RH_ASK.h>
#include <SPI.h>
RH_ASK controller;

const int potentiometerPO = A0;
int p = 0;

void setup() {
  Serial.begin(9600); // debugging purposes only

  if (!controller.init()) {
    Server.println("Failed to initialize controller (transmitter)"); // debugging purposes only
  }
}

void loop() {
  int newP = analogRead(potentiometerPO);

  // Only send new message if potentiometer value changed
   if (newP != p)  {
    p = newP;
    
    controller.send((uint8_t *)p, sizeof(p));
    controller.waitPacketSent();
    
    delay(50);
   }
}
