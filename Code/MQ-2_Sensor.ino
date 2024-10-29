// Código básico para leer el sensor MQ-2
int gasSensor = A0;
int gasLevel;

void setup() {
  Serial.begin(9600);
  pinMode(gasSensor, INPUT);
}

void loop() {
  gasLevel = analogRead(gasSensor);
  Serial.print("Nivel de gas: ");
  Serial.println(gasLevel);
  delay(1000);
}
