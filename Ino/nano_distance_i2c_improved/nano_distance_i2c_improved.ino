#include <NewPing.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define trigPin  3
#define echoPin  2
#define MAX_DISTANCE 350
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
NewPing sonar(trigPin, echoPin, MAX_DISTANCE);
float duration, distance;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Distance = ");
  lcd.setCursor(14,1);
  lcd.print("cm");
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int iterations = 10;
  duration = sonar.ping_median(iterations);
  distance = (duration / 2) * 0.0343;
  lcd.setCursor(11,0);
  lcd.print(distance); 
}
