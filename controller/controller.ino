// Transmitter (Controller)
#include <RH_ASK.h>
#include <SPI.h>
RH_ASK controller;

const int potentiometerP1 = A0;
const int potentiometerP2 = A1;
int p = 0;
int p1 = 0;
int p2 = 0;
//int prevP = 0;
char data[6];
bool datasent[3] = {true, false, false};
int counter = 0;

void setup() {
  Serial.begin(9600); // debugging purposes only

  if (!controller.init()) {
    Serial.println("Failed to initialize controller (transmitter)"); // debugging purposes only
  }
}

void loop() {
  int p1 = analogRead(potentiometerP1);
  p1 = map(p1, 0, 1023, 0, 255);

  char msg[3];
  prepareMessage(msg, p1, 'a');

  controller.send((uint8_t *)msg, strlen(msg));

  int p2 = analogRead(potentiometerP2);
  p2 = map(p2, 0, 1023, 0, 255);

  prepareMessage(msg, p1, 'b');

  controller.send((uint8_t *)msg, strlen(msg));
  //controller.waitPacketSent();
    
  //delay(10);
//  p = newP;
}

void prepareMessage(char* result, int p, char suffix) {
  char data[6];
  sprintf(data, "%d", p);

  if (strlen(data) == 1){
    result[0] ='0';
    result[1] = '0';
    result[2] = data[0]; 
    
  }
  else if (strlen(data) == 2){
    result[0] ='0';
    result[1] = data[0];
    result[2] = data[1];
  }
  else {
    result[0] = data[0];
    result[1] = data[1];
    result[2] = data[2];
  }
  result[3] = suffix;
}
