// Código básico para conectar el ESP8266 a WiFi
#include <ESP8266WiFi.h>

const char* ssid = "Tu_SSID";
const char* password = "Tu_Contraseña";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }
  
  Serial.println("Conectado a WiFi");
}

void loop() {
  // Lógica para enviar notificación o datos al servidor
}
