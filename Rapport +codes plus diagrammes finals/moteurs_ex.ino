
int ENA = 2;
int IN1 = 30;
int IN2 = 31;
int IN3 = 32;
int IN4 = 33;
int ENB = 3;
#include <NewPing.h>

int val;
int cm;
NewPing sonar(22, 23, 50);
void setup() {
  pinMode(ENA, OUTPUT); // Configurer
  pinMode(ENB, OUTPUT); // les broches
  pinMode(IN1, OUTPUT); // comme sortie
  pinMode(IN2, OUTPUT);
  Serial.println("1");
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  Serial.begin(9600);


}
void loop() {
  
  cm = sonar.ping_cm();
  Serial.print(cm);
  int vitesse=255;


  if (cm > 10 || cm == 0) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);


    analogWrite(ENA, vitesse);
    analogWrite(ENB, vitesse);
  }

   else {
    int i = vitesse;
    while (i > 0) {
      analogWrite(ENA, i);
      analogWrite(ENB, i);
      i -= 15;
      
    Serial.println("decceler");
      delay(20);
    }


  
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    
     i = 0;


     
    while (i < vitesse) {
      analogWrite(ENA, i);
      analogWrite(ENB, i);
      
    Serial.println("acceler");
      i += 15;
      delay(20);
    }
    
digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

      analogWrite(ENA, vitesse);
      analogWrite(ENB, vitesse);
    Serial.println("boucle reculer");


while (i > 0) {
      analogWrite(ENA, i);
      analogWrite(ENB, i);
      i -= 15;
      
    Serial.println("decceler");
      delay(20);
    }


  
digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    // Direction du Moteur B
    // NB: en sens inverse du moteur

    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    
     i = 0;
    while (i < vitesse) {
      analogWrite(ENA, i);
      analogWrite(ENB, i);
      
    Serial.println("acceler");
      i += 15;
      delay(20);
    }
    Serial.println("boucle tourner");

    
while (i > 0) {
      analogWrite(ENA, i);
      analogWrite(ENB, i);
      i -= 15;
      
    Serial.println("decceler");
      delay(20);
    }

    
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

  }
  


}
