#include<SoftwareSerial.h>
#define RX 12
#define TX 13
SoftwareSerial BlueT(RX,TX);

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
delay(500);
Serial.println("d");
BlueT.begin(9600);
delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(BlueT.available()){
    Serial.print(int(BlueT.read()));
    delay(1000);
     Serial.println("");
  }
while (Serial.available()) {
  BlueT.write(char(Serial.read()));
 
}
}
