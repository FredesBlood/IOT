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
int data = 0;                         // Variable para almacenar el valor del sensor
int buzzer = 5;                       // Pin del Buzzer (D1 es GPIO5)

void sendMessage(String message) {
  // URL de la solicitud HTTP POST
  String url = "http://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&apikey=" + apiKey + "&text=" + urlEncode(message);
  WiFiClient client;
  HTTPClient http;
  http.begin(client, url);

  // Especifica el tipo de contenido
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  // Envío de la solicitud HTTP POST
  int httpResponseCode = http.POST(url);
  if (httpResponseCode == 200) {
    Serial.println("Message sent successfully");
  } else {
    Serial.println("Error sending the message");
    Serial.print("HTTP response code: ");
    Serial.println(httpResponseCode);
  }

  // Libera recursos
  http.end();
}

void setup() {
  Serial.begin(115200);
  pinMode(buzzer, OUTPUT);             // Configura el pin del buzzer como salida

  // Conexión WiFi
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Lee el valor del sensor de humo
  data = analogRead(mq2);
  Serial.print("SMOKE: ");
  Serial.println(data);

  // Verifica si el sensor supera el umbral
  if (data > 350) {
    tone(buzzer, 6000, 500);           // Activa el buzzer
    sendMessage("Alerta: Se ha detectado humo!");  // Envía mensaje si se detecta humo
    delay(10000);                      // Espera 10 segundos antes de la siguiente lectura
  } else {
    digitalWrite(buzzer, LOW);        // Apaga el buzzer
  }

  delay(1000); // Intervalo de muestreo
}
