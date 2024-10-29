// Código básico para controlar el buzzer
int buzzer = 11;
int threshold = 500;

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int gasLevel = analogRead(A0);
  
  if (gasLevel >= threshold) {
    tone(buzzer, 1000); // Sonido de 1000 Hz
  } else {
    noTone(buzzer);
  }
  delay(1000);
}
