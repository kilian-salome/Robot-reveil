#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


static const unsigned char PROGMEM bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };
  
void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  //afficherHeure(12,15);
  
}

void loop() {
   afficherHeure(12,15);

  
  
}

void afficherHeure(int a, int b){
  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D); //initalisation du premier écran
  display.clearDisplay();
  display.display();
  display.setTextSize(5);
  display.setTextColor(WHITE);
  display.setCursor(30,0);
  display.print(a);
  display.println("h");
  display.display();


  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //initialisation du second écran
  display.clearDisplay();
  display.display();
  display.setTextSize(5);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println(b);
  display.display();
}
  
