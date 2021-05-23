// Receiver
#include <Servo.h>
Servo servo, ESC;
int sRange[2]={0, 180};
int escRange[2]={1000, 2000};

void setup() {
  Serial.begin(9600);

  //servo.attach(A5, sRange[0], sRange[1]);
  ESC.attach(A5, escRange[0], escRange[1]);
  //servo.write(sRange[0]);
  ESC.write(escRange[1]);
} 

void loop() {
  /*int p = analogRead(A3); // Potentiometer
  Serial.println(p);
  p = map(p, 0, 1023, sRange[0], sRange[1]);
  servo.write(p);*/

  int p = analogRead(A3); // Potentiometer
  Serial.println(p);
  p += 120; // Reduce deadzone
  p = map(p, 0, 1023, escRange[0], escRange[1]);
  ESC.write(p);
  
  //delay(100);
  
}
