// Transmitter (Controller)
#include <RH_ASK.h>
#include <SPI.h>
RH_ASK controller;

const int potentiometerPO = A0;
int p = 0;
//int prevP = 0;
char data[3];

void setup() {
  Serial.begin(9600); // debugging purposes only

  if (!controller.init()) {
    Serial.println("Failed to initialize controller (transmitter)"); // debugging purposes only
  }
}

void loop() {
  int newP = analogRead(potentiometerPO);
  newP = map(newP, 0, 1023, 0, 255);

  // Only send new message if potentiometer value changed
  
  //if (!(newP <= p+1 && newP >= p-1))  {
    Serial.println(newP);
    
  
    sprintf(data, "%d", newP);
  //  char newArray[sizeof(data)];
  //  int j = sizeof(newArray)-1;
  //  for(int i = sizeof(data)-1; i >= 0; i--)
  //  {
  //      newArray[j-i] = data[i];
  //      
  //  }
  //  Serial.println(strlen(consArray));
    //itoa(p, data, 10);
    //data[3] = 'a';
    //data[4] ='\0';
    //for (int i = 0; i < strlen(data); i++)  {
      //Serial.print(data[i]);
    //}
    //Serial.println(strlen(data));
    //const char *msg = "Heloo World";
    char consArray[4];
    if(strlen(data) < 3 && strlen(data) >1){
      consArray[0] ='0';
      consArray[1] = data[0];
      consArray[2] = data[1];
      consArray[3] = 'a';
    }
    else if(strlen(data)< 2){
      consArray[0] ='0';
      consArray[1] = '0';
      consArray[2] = data[0]; 
      consArray[3] = 'a';
    }
    else{
      for(int i =0; i < strlen(data); i++){
        consArray[i] = data[i];
        }
        consArray[3] = 'a';
    }
  
    //Serial.println(consArray);
    controller.send((uint8_t *)consArray, strlen(consArray));
    controller.waitPacketSent();
    
    delay(10);
    p = newP;
 // }
}
