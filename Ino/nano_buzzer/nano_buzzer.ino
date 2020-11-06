
const int buzzer = 7; //buzzer to arduino pin 9


void setup(){
 
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output

}

void loop(){
 
  tone(buzzer, 2000, 500);
  delay(1000);       // ...for 1sec
  
}
