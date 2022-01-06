/**
 * @file IotSettings.h
 * @author José Guerra Carmenate, <joseguerracarmenate@gmail.com>
 * @brief La clase IotSettings puede ser utilizada para almacenar en memoria no volatil
 * una serie de parametros o configuraciones típicos en dispositivos IoT.
 *  
 * @version 0.1
 * @date 2022-01-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef _IOT_SETTINGS_H_
#define _IOT_SETTINGS_H_

#include <Preferences.h>



class IotSettings: public Preferences{
  public: 
  NonVolatileSettings():Preferences(){};

  ~NonVolatileSettings(){};

  /**
   * @brief Recupera el nombre de la WiFi a la que se conectará el dispositivo
   * 
   * @param[out] ssid cadena de caracteres donde se almacenará el SSID de la WiFi
   * @return size_t Longitud del SSID recuperado
   */
  size_t getWifiSSID( char *ssid );

  /**
   * @brief Almacena el nombre de la WiFi a la que se conecta el dispositivo
   * 
   * @param[in] ssid cadena de caracteres donde se encuentra el SSID de la WiFi 
   * @return size_t Longitud del SSID almacenado
   */
  size_t setWifiSSID( const char *ssid );

  /**
   * @brief Recupera la contraseña de la WiFi a la que se conectará el dispositivo
   * 
   * @param[out] pass Cadena de caracteres donde se almacenará la contraseña de la WiFi  
   * @return size_t Longitud de la contraseña recuperada
   */
  size_t getWifiPassword( char *pass );

  /**
   * @brief Almacena la contraseña de la WiFi a la que se conectará el dispositivo
   * 
   * @param[out] pass Cadena de caracteres donde se encuentra la contraseña de la WiFi  
   * @return size_t Longitud de la contraseña almacenada
   */
  size_t setWifiPassword( const char *pass );

  /**
   * @brief Permite obtener la contraseña de acceso a la configuración
   * 
   * @param[out] pass cadena de caracteres donde se almacenará la contraseña. 
   * @return size_t Longitud de la contraseña almacenada.
   */
  size_t getAdjustmentPassword( char *pass );
  
  /**
   * @brief Establece la contraseña de acceso a la configuración
   * 
   * @param[in] pass cadena de caracteres con la contraseña a establecer.
   * @return size_t Longitud de la contraseña almacenada
   */
  size_t setAdjustmentPassword( const char *pass );

  /**
   * @brief Establece el tiempo de espera para conexión al punto de acceso inalámbrico.
   * 
   * @param timeout Tiempo de espera de conexión.
   */
  void setAccessPointConnectionTimeout( int32_t timeout );

  /**
   * @brief Recupera el tiempo de espera establecido para la conexión al punto de acceso inalámbrico. 
   * 
   * @return int32_t 
   */
  int32_t getAccessPointConnectionTimeout();

  /**
   * @brief Permite especificar si es necesario recalibrar los sensores
   * 
   * @param[in] recal true establece que está pendiente de calibración; 
   *                  false que ya están calibrados los sensores 
   */
  void setRecalibrationNeed( bool recal);

  /**
   * @brief Permite comprobar si es necesario recalibrar los sensores
   * 
   * @param[in] recal true indica que está pendiente de calibración; 
   *                  false que ya están calibrados los sensores 
   */
  bool getRecalibrationNeed();

  /**
   * @brief Establece el servidor en nube al que se debe conectar el dispositivo
   * 
   * @param[in] host Cadena de caracteres con la URL de la nube
   * @param[in] port Puerto de comunicaciones a emplear
   * 
   */
  void setCloudHost( const char *host, uint16_t port = 0 );

  /**
   * @brief Obtiene el servidor en nube al que se conecta el dispositivo  
   * 
   * @param host Cadena de caracteres con la URL de la nube
   * @return size_t Longitud de la URL del host
   */
  size_t getCloudHost( char *host );

  /**
   * @brief Establece el puerto de comunicaciones utilizado para acceder al servidor
   * 
   * @param[in] port puerto de comunicaciones utilizado para acceder al servidor
   */
  void setCloudPort( uint16_t port );

  /**
   * @brief Recupera el puerto de comunicaciones utilizado para acceder al servidor
   * 
   * @return uint16_t puerto de comunicaciones utilizado para acceder al servidor
   */
  uint16_t getCloudPort();

  /**
   * @brief Establece una credencial de acceso para el servidor
   * 
   * @param[in] credential_id Identificador de la credencial a almacenar 
   * @param[in] credential Cadena de caracteres con el valor de la credencial a almacenar 
   * 
   * @return size_t Cantidad de caracteres almacenados. Puede ser utilizado para validar que se almacenaron todos
   * caracteres de la credencial
   */
  size_t setCloudCredential( const char *credential_id, const char *credential );

  /**
   * @brief Recupera una credencial de acceso para el servidor
   * 
   * @param[in] credential_id Identificador de la credencial a recuperar 
   * @param[out] credential Cadena de caracteres donde se almacenará el valor de la credencial a almacenar 
   * 
   * @return size_t Cantidad de caracteres de la credencial recuperada 
   */
  size_t getCloudCredentials( const char *credential_id, char *credential);

  /**
   * @brief Especifica la Zona horaria 
   * 
   * @param time_zone cadena de caracteres especificando la zona horaria
   */
  void setTimeZone( const char* time_zone );

  /**
   * @brief Recupera la zona horaria en uso
   * 
   * @param time_zone cadena de caracteres con la zona horaria
   * @return size_t Longitud de la cadena de caracteres recuperada
   */
  size_t getTimeZone( char *time_zone );

  /**
   * @brief Especifica el periodo de transmision de un sensor
   * 
   * @param[in] sensor_name cadena de caracteres con el nombre del sensor en cuestión 
   * @param[in] period Periodo de transmision en segundos 
   */
  void setSensorTransmitionPeriod( const char* sensor_name, uint32_t period );

  /**
   * @brief Recupera el periodo de transmision utilizado para un sensor
   * 
   * @param[in] sensor_name cadena de caracteres con el nombre del sensor
   * @return uint32_t Periodo de transmision en segundos
   */
  uint32_t getSensorTransmitionPeriod( const char* sensor_name );


  /**
   * @brief Especifica el servidor NTP utilizado para sincronizar el RTC del dispositivo
   * 
   * @param[in] ntp servidor NTP
   */
  void setNTPServer( const char *ntp );

  /**
   * @brief Recupera el servidor NTP utilizado para sincronizar el RTC del dispositivo
   * 
   * @param[out] ntp cadena de caracteres donde se almacena la direccion del servidor NTP. 
   * @return size_t cantidad de caracteres recuperados
   */
  size_t getNTPServer( char *ntp );

  /**
   * @brief Establece los parametros predeterminados
   * 
   */
  void setDefault();

};

extern IotSettings DeviceSettings;

#endif
