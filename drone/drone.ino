// Receiver (Drone)
#include <RH_ASK.h>
#include <SPI.h>
//#include <Servo.h>

RH_ASK drone;
//Servo servo, ESC;

const int servoPO = A5;
const int escPO = A5;

const int sRange[2]={0, 180};
const int escRange[2]={1000, 2000};
uint16_t p;

void setup() {
  Serial.begin(9600); // debugging purposes only


  if (!drone.init())
    Serial.println("Failed to initialize drone (receiver)"); // debugging purposes only

  //servo.attach(servoPO, sRange[0], sRange[1]);
  //ESC.attach(escPO, escRange[0], escRange[1]);
 // servo.write(sRange[0]);
  //ESC.write(escRange[1]);
} 

void loop() {
    uint8_t buf[4];
    uint8_t buflen = sizeof(buf);
    if (drone.recv(buf, &buflen)) { // Non-blocking
      char bufNumber[3];
      for (int i = 0; i < buflen - 1; i++) {
        bufNumber[i] = buf[i];
      }
      int p = atoi(bufNumber);
      Serial.println(number);
    
      buf[0] = '0';
      buf[1] = '0';
      buf[2] = '0';
    
      //p = map(p, 0, 1023, sRange[0], sRange[1]);
      //p = map(p, 0, 255, sRange[0], sRange[1]);
      // servo.write(p);
      
      //p = map(p, 0, 1023, escRange[0], escRange[1]);
      //ESC.write(p);
    }
}
