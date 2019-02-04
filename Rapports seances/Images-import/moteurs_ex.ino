//-- MOTEUR A --
int ENA=9;//Connecté à Arduino pin 9(sortie PWM)
int IN1=4; //Connecté à Arduino pin 4
int IN2=5; //Connecté à Arduino pin 5
//-- MOTEUR B --
int ENB=10; //Connecté à Arduino pin 10(Sortie PWM)
int IN3=6; //Connecté à Arduino pin 6
int IN4=7; //Connecté à Arduino pin 7
#include <NewPing.h>

int val;
int cm;
NewPing sonar(12,11,50);
void setup() {
pinMode(ENA,OUTPUT); // Configurer
pinMode(ENB,OUTPUT); // les broches
pinMode(IN1,OUTPUT); // comme sortie
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
digitalWrite(ENA,LOW);// Moteur A - Ne pas tourner
digitalWrite(ENB,LOW);// Moteur B - Ne pas tourner
Serial.begin(9600);


}
void loop() {

Serial.println(cm);

cm=sonar.ping_cm();
  if (cm>10 || cm==0){
// Direction du Moteur A
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
// Direction du Moteur B
// NB: en sens inverse du moteur

digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);



  
// Moteur A - Plein régime
analogWrite(ENA,255);
// Moteur B - Mi-régime
analogWrite(ENB,255);}

else{
  Serial.println("boucle tourner");
  analogWrite(ENA,255);
  analogWrite(ENB,255);

  digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
// Direction du Moteur B
// NB: en sens inverse du moteur

digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);

delay(1000);
  analogWrite(ENA,255);
  analogWrite(ENB,255);

  digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
// Direction du Moteur B
// NB: en sens inverse du moteur

digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
delay(300);
  }
}
