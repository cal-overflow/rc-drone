// Receiver (Drone)
#include <RH_ASK.h>
#include <SPI.h>
#include <Servo.h>

RH_ASK drone;
Servo servo, ESC;

const int servoPO = A5;
const int escPO = A5;

const int sRange[2]={0, 180};
const int escRange[2]={1000, 2000};
uint8_t data;
uint16_t p;

void setup() {
  Serial.begin(9600); // debugging purposes only


  if (!drone.init())
    Server.println("Failed to initialize drone (receiver)"); // debugging purposes only

  servo.attach(servoPO, sRange[0], sRange[1]);
  //ESC.attach(escPO, escRange[0], escRange[1]);
  servo.write(sRange[0]);
  //ESC.write(escRange[1]);
} 

void loop() {
  uint8_t buf = sizeof(data);
  if (drone.recv((uint8_t*)&data, &datalen) && datalen == sizeof(data)) {
    uint16_t p = data;

    // debugging purposes only:
    Serial.print("Received:");
    Serial.println(p);
  }
  
  p += 120; // Reduce deadzone
  p = map(p, 0, 1023, servoRange[0], servoRange[1]);
  servo.write(p);
  
  //p = map(p, 0, 1023, escRange[0], escRange[1]);
  //ESC.write(p);

  
}
