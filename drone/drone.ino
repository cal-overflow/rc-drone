// Receiver (Drone)
#include <RH_ASK.h>
#include <SPI.h>
#include <Servo.h>

RH_ASK drone;
Servo servo1, servo2, ESC;

const int servo1PO = 10;
const int servo2PO = 9;
const int escPO = A5;

const int sRange[2]={0, 180};
const int escRange[2]={1000, 2000};
uint16_t p;

void setup() {
  Serial.begin(9600); // debugging purposes only

   if (!drone.init())
    Serial.println("Failed to initialize drone (receiver)"); // debugging purposes only

  servo1.attach(servo1PO);
  servo2.attach(servo2PO);
  //ESC.attach(escPO);
  servo1.write(sRange[0]);
  servo2.write(sRange[0]);
  //ESC.write(escRange[1]);
} 

void loop() {
    uint8_t buf[4];
    uint8_t buflen = sizeof(buf);
    if (drone.recv(buf, &buflen)) { // Non-blocking
      Serial.println("received");
      char bufNumber[3];
      for (int i = 0; i < buflen - 1; i++) {
        bufNumber[i] = buf[i];
      }
      int p = atoi(bufNumber); // cast ASCII number array to int
      char letter = buf[3]; //  cast ASCII int to char
      Serial.println(letter);
    
      p = map(p, 0, 255, sRange[0], sRange[1]);
      Serial.println(p);

      if (letter == 'a') {
        servo.write(p);
        servo2.write(abs(180 - p));
      }
      else if (letter == 'b') {
        // do something :)
      }
      else if (letter == 'c') {
        // do something :)
      }
      else {
        // do something :)
      }
      
      buf[0] = '0';
      buf[1] = '0';
      buf[2] = '0';
      buf[3] = '\0';

//      delay(5); // TODO: determine if a delay is beneficial here
    }
}
