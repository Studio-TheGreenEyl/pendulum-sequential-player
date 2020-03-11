// sending less data: only changes
// 

const int switchPin = 2;

int ledState = HIGH;
int inputState;
int lastInputState = LOW;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

void setup() {
  Serial.begin(9600);
  pinMode(switchPin, INPUT_PULLUP);
}

void loop() {
  int sensorValue = digitalRead(switchPin);
  
  if (sensorValue!= lastInputState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the input state has changed:
    if (sensorValue != inputState) {
      inputState = sensorValue;
      Serial.print(sensorValue);
    }
  }

  lastInputState = sensorValue;
}
