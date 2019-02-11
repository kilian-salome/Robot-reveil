#include <config.h>
#include <ds3231.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <NewPing.h>
#include<SoftwareSerial.h>

#include <NewTone.h>
#define TONE_PIN 4

#define RX 2
#define TX 3
SoftwareSerial BlueT(RX, TX);


int ENA = 9; 
int IN1 = 5; 
int IN2 = 6; 
int ENB = 10;
int IN3 = 7; 
int IN4 = 8;

const int button = 13;
int val;
int cond;


int cm;
NewPing sonar(12, 11, 50);

struct ts t;
struct ts a;

int alarmMinutes = 0;
int alarmHeures = 0;



void setup() {
  Serial.begin(9600);
  BlueT.begin(9600);
  Wire.begin();
  pinMode(button, INPUT);

  pinMode(ENA, OUTPUT); 
  pinMode(ENB, OUTPUT); 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  digitalWrite(ENA, LOW); 
  digitalWrite(ENB, LOW); 


  //  DS3231_init(DS3231_INTCN);
  //  lcd.begin(16, 2);
  //remettreHeure(t,10,45,0,11,2,2019);
}










void loop() {
  DS3231_get(&t);

  //Serial.println(alarmMinutes);
  //Serial.println(t.min);
  //Serial.println(alarmHeures);
  //Serial.println(t.hour);
  //Serial.print("cond=");
  //Serial.println(cond);
  //Serial.print("val=");
  //Serial.println(val);


  if (BlueT.available()) {
    Serial.println("rentrer boucle 0");
    alarmMinutes = recupererAlarm(a).min;
    alarmHeures = recupererAlarm(a).hour;
    cond = 0;
  }

  if (alarmMinutes == t.min && alarmHeures == t.hour && cond == 0) {
    cond = 2;
  }



  if (cond == 2) {
    Serial.println("rentrer boucle 1");
    //BlueT.write(char("ca sonne"));
    faireSonnerReveil();
    faireRoulerrobot();
    //lcd.clear();

    if (val == LOW) {
      // Moteur A -pas tourner
      analogWrite(ENA, 0);
      // Moteur B - pas tourner
      analogWrite(ENB, 0);
      Serial.println("rentrer boucle 2");
      cond = 1;
    }
  }

  val = digitalRead(button);
  cm = sonar.ping_cm();
  //Serial.println(cm);
  if (cm > 0 && cm < 45) {

    Serial.println("rentrer boucle 3");
    afficherDateMONI(t);
    //afficherDateLCD(t);
    delay(1000);
    //lcd.clear();
    cm = 0;
  }
}


















void remettreHeure(struct ts t, int heure, int minu, int sec, int mday, int mon, int year) {
  t.hour = heure;
  t.min = minu;
  t.sec = sec;
  t.mday = mday;
  t.mon = mon;
  t.year = year;

  DS3231_set(t);
}

void afficherDateMONI(struct ts t) {
  Serial.print("date : ");
  Serial.print(t.mday);
  Serial.print("/");
  Serial.print(t.mon);
  Serial.print("/");
  Serial.print(t.year);
  Serial.print("\t Heure : ");
  Serial.print(t.hour);
  Serial.print(":");
  Serial.print(t.min);
  Serial.print(".");
  Serial.println(t.sec);
}

/*void afficherDateLCD(struct ts t){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(t.mday);
  lcd.print("/");
  lcd.print(t.mon);
  lcd.print("/");
  lcd.print(t.year);
  lcd.setCursor(0,1);
  lcd.print(t.hour);
  lcd.print(":");
  lcd.print(t.min);
  lcd.print(".");
  lcd.print(t.sec);}
*/
struct ts recupererAlarm(struct ts a) {
  if (BlueT.available()) {
    //Serial.print(int(BlueT.read()));
    //Serial.println("");
    a.hour = int(BlueT.read());
    delay(1000);
    a.min = int(BlueT.read());
    Serial.print("Alarme:");
    Serial.print(a.hour);
    Serial.print(" h ");
    Serial.println(a.min);
    return a;
  }
}

void faireSonnerReveil() {
  Serial.println("STOP");
  //lcd.setCursor(0, 0);
  //lcd.print("STOP");

  for (unsigned long freq = 500 ; freq < 1000; freq++) {
    NewTone(TONE_PIN, freq); // Play the frequency (125 Hz to 15 kHz sweep in 10 Hz steps).
    delay(1);
  }
  for (unsigned long freq = 1000 ; freq > 500; freq--) {
    NewTone(TONE_PIN, freq); // Play the frequency (125 Hz to 15 kHz sweep in 10 Hz steps).
    delay(1);
  }

  noNewTone(TONE_PIN);
}


void faireRoulerrobot() {
  cm = sonar.ping_cm();



  if (cm > 10 || cm == 0) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);


    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
  }

  else {
    Serial.println("boucle reculer");
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    delay(3000);


    Serial.println("boucle tourner");
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    // Direction du Moteur B
    // NB: en sens inverse du moteur

    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(300);
  }

}
