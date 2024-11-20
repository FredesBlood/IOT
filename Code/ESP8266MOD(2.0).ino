//en la version 2.0 la alarma deja de sonar cuando deja de detectar gas.

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <UrlEncode.h>

const char* ssid = "A35";             // Nombre de la red WiFi
const char* password = "12345678";    // Contraseña de la red WiFi

// +código_internacional + número de teléfono
String phoneNumber = "56932754071";   // Número de teléfono (incluyendo código de país)
String apiKey = "8367518";            // API key para CallMeBot

int mq2 = A0;                         // El sensor de humo está conectado al pin analógico A0
int buzzer = 5;                       // Pin del Buzzer (D1 es GPIO5)
int data = 0;                         // Variable para almacenar el valor del sensor
bool gasDetected = false;             // Estado del gas detectado

void sendMessage(String message) {
  String url = "http://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&apikey=" + apiKey + "&text=" + urlEncode(message);
  WiFiClient client;
  HTTPClient http;
  http.begin(client, url);

  int httpResponseCode = http.POST(url);
  if (httpResponseCode == 200) {
    Serial.println("Mensaje enviado con éxito.");
  } else {
    Serial.println("Error al enviar el mensaje.");
    Serial.print("Código de respuesta HTTP: ");
    Serial.println(httpResponseCode);
  }

  http.end();
}

void setup() {
  Serial.begin(115200);
  pinMode(buzzer, OUTPUT);             // Configura el pin del buzzer como salida

  // Conexión WiFi
  WiFi.begin(ssid, password);
  Serial.println("Conectando a WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Conectado a la red WiFi con IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  data = analogRead(mq2);
  Serial.print("Valor del sensor de humo: ");
  Serial.println(data);

  if (data > 350) { // Si se detecta gas
    if (!gasDetected) { // Solo envía un mensaje la primera vez
      sendMessage("¡ALERTA! Se ha detectado humo o gas.");
      gasDetected = true; // Cambia el estado a gas detectado
    }
    tone(buzzer, 600); // El buzzer sigue sonando
  } else { // Si no se detecta gas
    noTone(buzzer);     // Apaga el buzzer
    gasDetected = false; // Reinicia el estado
  }

  delay(1000); // Intervalo de muestreo
}
