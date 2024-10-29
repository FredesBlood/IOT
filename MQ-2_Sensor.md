# MQ-2 Gas Sensor

## Descripción
El sensor de gas MQ-2 es un dispositivo que detecta la presencia de gases inflamables y humo. 
Utiliza un pin analógico para la lectura de los niveles de gas y un pin digital para indicar si se ha alcanzado un nivel crítico.

## Conexiones
| Pin MQ-2 | Conexión Arduino |
|----------|-------------------|
| A0       | Pin A0           |
| D0       | Pin Digital (configurable) |
| GND      | GND              |
| VCC      | 5V               |

## Instrucciones de Conexión
1. Conecta el pin **A0** del sensor MQ-2 al pin **A0** del Arduino.
2. Conecta el pin **D0** a un pin digital (por ejemplo, D8) para detectar niveles críticos.
3. Conecta **GND** a **GND** en el Arduino.
4. Conecta **VCC** al pin de **5V** del Arduino.

