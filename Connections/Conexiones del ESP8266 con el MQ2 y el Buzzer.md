# Esquema de Conexiones: ESP8266, Sensor de Humo MQ2 y Buzzer

Este es el esquema de conexiones para el proyecto que utiliza un ESP8266, un sensor de humo MQ2 y un buzzer para enviar una alerta por WhatsApp cuando se detecte humo.

## Componentes:
- **ESP8266** (NodeMCU o similar)
- **MQ2** (Sensor de Humo)
- **Buzzer** (Alarma sonora)
- **Cables de conexión**

## Conexiones:

### 1. Conexión del Sensor de Humo MQ2 al ESP8266:
- **VCC (MQ2)** → **3.3V (ESP8266)**: El pin de alimentación del sensor MQ2 se conecta a la salida de 3.3V del ESP8266.
- **GND (MQ2)** → **GND (ESP8266)**: El pin de tierra (GND) del sensor se conecta a uno de los pines de GND del ESP8266.
- **A0 (MQ2)** → **A0 (ESP8266)**: El pin de salida analógica del sensor MQ2 se conecta al pin **A0** del ESP8266. Este pin se utiliza para leer el valor del sensor de humo.

### 2. Conexión del Buzzer al ESP8266:
- **VCC (Buzzer)** → **3.3V (ESP8266)**: El pin de alimentación del buzzer se conecta al pin de 3.3V del ESP8266.
- **GND (Buzzer)** → **GND (ESP8266)**: El pin de tierra del buzzer se conecta a **GND** del ESP8266.
- **Pin de control del Buzzer (Buzzer)** → **D1 (GPIO5)**: El pin de control del buzzer se conecta al pin **D1 (GPIO5)** del ESP8266. Este pin se usa para activar el buzzer.

---

## Resumen del Esquema de Conexiones:

| Componente             | Pin Sensor MQ2  | Pin Buzzer   | Pin ESP8266 (GPIO) |
|------------------------|-----------------|--------------|--------------------|
| **MQ2 (Sensor de Humo)**| VCC → 3.3V      |              |                    |
|                        | GND → GND       |              |                    |
|                        | A0 → A0         |              | A0 (Entrada analógica) |
| **Buzzer**              |                 | VCC → 3.3V   |                    |
|                        |                 | GND → GND    |                    |
|                        |                 | Pin de control → D1 (GPIO5) |                    |

---

## Explicación de las Conexiones:

1. **Sensor de Humo (MQ2)**: El sensor MQ2 tiene una salida analógica que se conecta al pin **A0** del ESP8266. El valor de este pin se lee en el código y se utiliza para detectar la presencia de humo. Si el valor es mayor a un umbral (350 en este caso), se activa el buzzer y se envía un mensaje de alerta.

2. **Buzzer**: El buzzer se conecta al pin **D1 (GPIO5)** del ESP8266. Este pin genera una señal para activar el buzzer cuando se detecta humo. Si el sensor de humo supera el umbral, se activa el buzzer utilizando la función `tone()`.

---

### Notas:
- El pin **A0** en el ESP8266 es un pin analógico que permite leer valores de sensores analógicos como el MQ2.
- El pin **D1 (GPIO5)** es un pin digital utilizado para controlar el buzzer.

Este esquema te permitirá conectar los componentes correctamente y hacer funcionar el sistema de detección de humo y alerta a través de WhatsApp con el ESP8266.
