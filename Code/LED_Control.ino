// Código básico para controlar LEDs
int greenLED = 9;
int redLED = 10;
int threshold = 500;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
}

void loop() {
  int gasLevel = analogRead(A0);
  
  if (gasLevel < threshold) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);
  } else {
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
  }
  delay(1000);
}
