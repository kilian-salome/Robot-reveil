#include <config.h>
#include <ds3231.h>
#include <Wire.h>
#include <LiquidCrystal.h>
#include <NewPing.h>
#include<SoftwareSerial.h>


#define RX 11
#define TX 10
SoftwareSerial BlueT(RX,TX);


LiquidCrystal lcd( 2, 3, 4, 5, 6, 7);

int cm;
NewPing sonar(10,9,50);

struct ts t;
struct ts a;

 int alarmMinutes=0;
 int alarmHeures=0;
void setup() {
  Serial.begin(9600);
  BlueT.begin(9600);
  Wire.begin();
  //DS3231_init(DS3231_INTCN);
  lcd.begin(16, 2);
  //remettreHeure(t,0,0,0,0,0,0);
}
 
void loop() {
  DS3231_get(&t);
 
 //Serial.println(alarmMinutes);
  //Serial.println(t.min);
    //Serial.println(alarmHeures);
    //  Serial.println(t.hour);
      if (BlueT.available()){

      alarmMinutes=recupererAlarm(a).min;
      alarmHeures=recupererAlarm(a).hour;

      }
      
   if (alarmMinutes==t.min && alarmHeures==t.hour && t.sec<10){
    //BlueT.write(char("ca sonne"));
 faireSonnerReveil();
}
cm=sonar.ping_cm();
 //;Serial.println(cm);

 if (cm>0 && cm<45){
  
  afficherDateMONI(t);
  afficherDateLCD(t);
  delay(1000);
  lcd.clear();
  cm=0;
}}

void remettreHeure(struct ts t,int heure,int min,int sec,int mday,int mon,int year){
  t.hour=22;
  t.min=26;
  t.sec=30;
  t.mday=12;
  t.mon=12;
  t.year=2018;
 
  DS3231_set(t);}

void afficherDateMONI(struct ts t){
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
  
void afficherDateLCD(struct ts t){
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

 struct ts recupererAlarm(struct ts a){
  if (BlueT.available()){
//Serial.print(int(BlueT.read()));
//Serial.println("");
a.hour=int(BlueT.read());
delay(1000);
a.min=int(BlueT.read());
Serial.print("Alarme:");
Serial.print(a.hour);
Serial.print(" h ");
Serial.println(a.min);
return a;
}
  }

  void faireSonnerReveil(){
    Serial.println("STOP");
    }
