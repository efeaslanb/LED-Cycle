 const int buttonPin = 4;
const int ledPins[] = {9, 10, 11};
int ledIndex = 0;
int lastButtonState = HIGH;
bool buttonPressed = false;

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  // Detect rising edge: button goes from HIGH to LOW
  if (buttonState == LOW && lastButtonState == HIGH && !buttonPressed) {
    buttonPressed = true;
    // Turn off all LEDs
    for (int i = 0; i < 3; i++) {
      digitalWrite(ledPins[i], LOW);
    }
    // Move to next LED
    ledIndex = (ledIndex + 1) % 3;
    digitalWrite(ledPins[ledIndex], HIGH);
  }

  // Reset buttonPressed when released
  if (buttonState == HIGH && buttonPressed) {
    buttonPressed = false;
  }

  lastButtonState = buttonState;
}


