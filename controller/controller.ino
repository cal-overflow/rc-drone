// Transmitter (Controller)
#include <RH_ASK.h>
#include <SPI.h>
RH_ASK controller;

const int potentiometerPO = A0;
int p = 0;
char data[3];

void setup() {
  Serial.begin(9600); // debugging purposes only

  if (!controller.init()) {
    Serial.println("Failed to initialize controller (transmitter)"); // debugging purposes only
  }
}

void loop() {
  int newP = analogRead(potentiometerPO);
  

  // Only send new message if potentiometer value changed
   //if (newP != p)  {
  //newP += 120; // Reduce deadzone
  newP = map(newP, 0, 1023, 0, 255);
  p = newP;
  //Serial.println(p);

   data[0] = '\0';
   data[1] = '\0';
   data[2] = '\0';
  sprintf(data, "%d", p);
  //itoa(p, data, 10);
  //data[3] = 'a';
  //data[4] ='\0';
  //for (int i = 0; i < strlen(data); i++)  {
    //Serial.print(data[i]);
  //}
  Serial.println(strlen(data));
  controller.send((uint8_t *)data, strlen(data));
  controller.waitPacketSent();
  
  delay(50);
   //}
   data[0] = '0';
   data[1] = '0';
   data[2] = '0';
}
