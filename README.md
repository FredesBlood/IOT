# Sistema de Alerta de Humo con Notificación por WhatsApp

Este proyecto utiliza un **sensor de humo MQ-2**, un **ESP8266** y la API de **CallMeBot** para enviar alertas de humo a través de WhatsApp. El dispositivo monitorea constantemente la presencia de humo y, si detecta niveles altos, activa un **buzzer** y envía un mensaje de alerta a un número de teléfono preconfigurado.

## Requisitos

Antes de comenzar, asegúrate de tener los siguientes componentes y configuraciones:

### Hardware
- **ESP8266** (ej. NodeMCU o Wemos D1 mini)
- **Sensor de humo MQ-2**
- **Buzzer** (activo o pasivo)
- Cables de conexión

### Software
- **Arduino IDE**: Para programar el ESP8266.
- **Bibliotecas de Arduino**:
  - `ESP8266WiFi`
  - `ESP8266HTTPClient`
  - `WiFiClient`
  - `UrlEncode` (puedes instalarla desde el Administrador de Bibliotecas en el Arduino IDE)

### API de CallMeBot
- Una **API Key** de CallMeBot (es necesario registrarse en [CallMeBot](https://www.callmebot.com/) para obtener una clave API).
- **Número de teléfono** en formato internacional (ej. `+56932754071` para Chile).

## Instalación

### 1. Configura el entorno en el Arduino IDE:
- Abre el **Arduino IDE** y agrega el soporte para el **ESP8266** si no lo has hecho antes. 
- Ve a **Archivo** > **Preferencias**, y en el campo "Gestor de URLs de tarjetas adicionales", agrega:  
  `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
- Luego, ve a **Herramientas** > **Placa** > **Gestor de tarjetas** y busca **ESP8266** para instalarlo.

### 2. Instala las bibliotecas necesarias:
Ve a **Programa** > **Incluir Librería** > **Gestionar Bibliotecas** y busca las siguientes bibliotecas para instalar:
- **ESP8266WiFi**
- **ESP8266HTTPClient**
- **WiFiClient**
- **UrlEncode**

### 3. Configura el código:
Edita el código en el archivo `.ino` con tus configuraciones:
- **SSID y Contraseña** de tu red Wi-Fi:
  ```cpp
  const char* ssid = "A35";             // Nombre de la red WiFi
  const char* password = "12345678";    // Contraseña de la red WiFi


Número de teléfono (con código internacional) y API key de CallMeBot:

String phoneNumber = "56932754071";   // Número de teléfono (incluyendo código de país)
String apiKey = "8367518";            // API key para CallMeBot


Pin de conexión del buzzer: Si el buzzer está conectado a un pin diferente, actualiza el valor de buzzer:
int buzzer = 5;  // D1 es GPIO5, cambia si usas otro pin


4. Carga el código al ESP8266:
Conecta tu ESP8266 al computador mediante un cable USB, selecciona la placa correcta en Herramientas > Placa y carga el código.

Funcionamiento
El sistema se conecta automáticamente a tu red Wi-Fi al iniciar.
El sensor MQ-2 monitorea la concentración de humo en el aire. Si detecta un valor superior al umbral (350 en este caso), activa el buzzer y envía un mensaje de alerta a través de WhatsApp al número configurado.
La alerta será enviada utilizando la API de CallMeBot y se incluirá un mensaje como: "Alerta: Se ha detectado humo!".
El buzzer se apagará una vez que el nivel de humo baje por debajo del umbral, pero el sistema continuará monitoreando constantemente.

Ajustes del umbral:
Si deseas cambiar el umbral de detección de humo, ajusta el valor en la siguiente línea:

if (data > 350) {

Sube o baja el valor según tus necesidades.


Contribuciones
Si deseas contribuir a este proyecto, por favor abre un pull request con tus mejoras o correcciones. También puedes reportar issues si encuentras algún error o tienes sugerencias.

Licencia
Este proyecto está bajo la Licencia MIT. Puedes modificarlo y redistribuirlo de acuerdo con los términos de dicha licencia.

Problemas comunes
No puedo enviar el mensaje de WhatsApp: Asegúrate de que tu API Key y el número de teléfono están correctos. Si el número de teléfono tiene un formato incorrecto, CallMeBot no podrá enviar el mensaje.
El ESP8266 no se conecta a Wi-Fi: Revisa que el nombre de la red Wi-Fi (SSID) y la contraseña sean correctos.
El buzzer no suena: Asegúrate de que el buzzer esté correctamente conectado al pin especificado en el código.








