const int buzzer=2;
const int bouton=4;
int val=0;

void setup() {
  Serial.begin(9600);
  pinMode(bouton, INPUT);
  delay(1000); 

}

void loop() {
 val=digitalRead(bouton);

 if (val==HIGH) {
 noTone(buzzer);
 Serial.println("nobuzzer");
 }

 else {
 tone(buzzer, 500, 100); //tone(broche, frequence, durée)
 delay(1000);
 Serial.println("buzzer");
 }


 
  
}
