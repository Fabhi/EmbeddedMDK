int temppin=7;
float input, Volt, mVolt, temp;

void setup(){
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){
//  temp=analogRead(temppin); // Reading data from the sensor. This voltage is stored as a 10bit number
//  temp=(5.0*temp*1000.0)/(1024*10);
  input = analogRead(temppin);
  Volt = 5*input/1024;
  mVolt = Volt*1000;
  temp = mVolt/10;
  /* 5*temp/1024 is to convert the 10 bit number to a voltage reading.
  This is multiplied by 1000 to convert it to millivolt.
  We then divide it by 10 beacuse each degree rise results in a 10 millivolt increase.
  */
  Serial.println(temp);
  digitalWrite(LED_BUILTIN, (millis() / 1000) % 2);
//  delay(500); // This is because we dont want a continuous stream of data
}
