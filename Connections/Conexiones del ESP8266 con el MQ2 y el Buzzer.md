Conexiones del ESP8266 con el MQ2 y el Buzzer
1. Conexión del Sensor de Humo MQ2 al ESP8266:
VCC (MQ2) → 3.3V (ESP8266): El pin de alimentación del sensor MQ2 se conecta a la salida de 3.3V del ESP8266.
GND (MQ2) → GND (ESP8266): El pin de tierra (GND) del sensor se conecta a uno de los pines de GND del ESP8266.
A0 (MQ2) → A0 (ESP8266): El pin de salida analógica del sensor MQ2 se conecta al pin A0 del ESP8266. Este pin se utiliza para leer el valor del sensor de humo.
2. Conexión del Buzzer al ESP8266:
VCC (Buzzer) → 3.3V (ESP8266): El pin de alimentación del buzzer se conecta al pin de 3.3V del ESP8266.
GND (Buzzer) → GND (ESP8266): El pin de tierra del buzzer se conecta a GND del ESP8266.
Pin de control del Buzzer (Buzzer) → D1 (GPIO5): El pin de control del buzzer se conecta al pin D1 (GPIO5) del ESP8266. En el código, este pin se usa para activar el buzzer.
Resumen del esquema de conexiones:
Componente	Pin Sensor MQ2	Pin Buzzer	Pin ESP8266 (GPIO)
MQ2 (Sensor de Humo)	VCC → 3.3V		
GND → GND		
A0 → A0		A0 (Entrada analógica)
Buzzer		VCC → 3.3V	
GND → GND	
Pin de control → D1 (GPIO5)	
Explicación de las conexiones:
Sensor de Humo (MQ2): Este sensor de gas tiene una salida analógica que se conecta al pin A0 del ESP8266. El valor leído desde el pin A0 se utiliza para detectar la presencia de humo. Si el valor es mayor a un umbral (en este caso, 350), se activa el buzzer y se envía un mensaje de alerta.

Buzzer: El buzzer se conecta al pin D1 (GPIO5) del ESP8266. Este pin se utiliza para generar una señal acústica cuando se detecta humo. Si el sensor detecta humo (es decir, si el valor analógico supera el umbral), se activa el buzzer con la función tone(), generando un sonido.

Notas:
El pin A0 en el ESP8266 es un pin analógico, por lo que puedes leer valores de sensores analógicos como el MQ2 a través de este pin.
El pin D1 (GPIO5) es uno de los pines digitales del ESP8266, utilizado aquí para controlar el buzzer.
