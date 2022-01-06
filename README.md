# IoT Settings Library

La clase IotSettings permite gestionar un grupo de parámetros y configuraciones típicas de dispositivos IoT. 
Está pensada para ser utilizadas en firmware basados en chips ESP32 ya que hereda de la clase Preference para utilizar la memoria no volátil del SoC.

## Parámetros que permite almacenar

### WiFi
 - SSID y Clave de la WiFi a la que se conecta.
 - Tiempo de espera para conexión
 - Clave de acceso a la configuración

### Servidor
 - Puerto TCP y Dirección IP o URL del servidor al que está vinculado el dispositivo 
 - Credenciales de acceso al servidor

### Sensores
  - Necesidad de calibrar los sensores
  - Periodo de transmisión de los sensores

### Otros
  - Zona horaria
  - Servidor NTP