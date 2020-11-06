#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define echoPin 2 //Digital Pins 
#define trigPin 3

// defines variables
long duration; 
int distance;
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Distance = ");
}
void loop() {
  delay(100);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; 
  lcd.setCursor(11,0);
  lcd.print(distance); 
  lcd.print(" cm  ");
}
