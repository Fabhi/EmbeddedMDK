// include the SoftwareSerial library so you can use its functions:
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>

#define rxPin 2
#define txPin 3

// set up a new serial port
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);

void setup()  {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  mySerial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.clear();
  lcd.print("Charging.");
  while(mySerial.available()>0){
      mySerial.read(); 
      delay(14);   
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Connection ");
  lcd.setCursor(0,1);
  lcd.print("Loose!");
  delay(1000);
}
