long prevMillis = 0;
long interval = 10;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  if(millis() - prevMillis < interval) return;
  prevMillis = millis();
  int sensorValue = digitalRead(2);
  
  Serial.print(sensorValue);
  delay(10);        // delay in between reads for stability
}
