// Receiver (Drone)
#include <RH_ASK.h>
#include <SPI.h>
#include <Servo.h>

RH_ASK drone;
Servo servo, servo2, ESC;

const int servoPO = 10;
const int servo2PO = 9;
const int escPO = A5;

const int sRange[2]={0, 180};
const int escRange[2]={1000, 2000};
uint16_t p;

void setup() {
  Serial.begin(9600); // debugging purposes only

   if (!drone.init())
    Serial.println("Failed to initialize drone (receiver)"); // debugging purposes only

  servo.attach(servoPO);
  servo2.attach(servo2PO);
  //ESC.attach(escPO);
  servo.write(sRange[0]);
  servo2.write(sRange[0]);
  //ESC.write(escRange[1]);
} 

void loop() {
  servo.write(sRange[0]);
  Serial.println("servo");
  delay(500);
  servo.write(sRange[1]);
  delay(500);
//    uint8_t buf[4];
//    uint8_t buflen = sizeof(buf);
//    if (drone.recv(buf, &buflen)) { // Non-blocking
//      char bufNumber[3];
//      for (int i = 0; i < buflen - 1; i++) {
//        bufNumber[i] = buf[i];
//      }
//      int p = atoi(bufNumber);
//      Serial.println(p);
//    
//      p = map(p, 0, 255, sRange[0], sRange[1]);
//      Serial.println("writing to servo");
//      servo.write(p);
//      
//      //p = map(p, 0, 1023, escRange[0], escRange[1]);
//      //ESC.write(p);
//      buf[0] = '0';
//      buf[1] = '0';
//      buf[2] = '0';
//    }
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

      servo.write(p);
      delay(5);
      servo2.write(p);
//      if (letter == 'a') {
//        servo.write(p);
//      }
//      else if (letter == 'b') {
//       servo2.write(abs(180 - p)); 
//      }
      
      buf[0] = '0';
      buf[1] = '0';
      buf[2] = '0';
      buf[3] = '\0';
//      delay(5);
    }
<<<<<<< HEAD
    //delay(5);
=======
>>>>>>> c0468d1768cdb119180d8c7cf33de5226db39621
}
