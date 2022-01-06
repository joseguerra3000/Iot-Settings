/**
 * @file IotSettings.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "IotSettings.hpp"

#define DEFAULT_WIFI_SSID               "MiFibra-6FF1"
#define DEFAULT_WIFI_PASS               "Ftpxb2QY"
#define DEFAULT_NTP_SERVER              "pool.ntp.org"
#define DEFAULT_TIME_ZONE               "CET-1CEST,M3.5.0,M10.5.0/3" // Zona horaria Madrid
#define DEFAULT_ACCESS_PASSWORD         "12345678"
#define DEFAULT_PROVISION_DEVICE_KEY    "j2tgn1nznwzun9gqbvoi"
#define DEFAULT_PROVISION_DEVICE_SECRET "xu8vjdr18m1i75tvabd7"

#define DEFAULT_CONNECTION_TIMEOUT      3000

#ifndef DEFAULT_HOST
# define DEFAULT_HOST                    "thingsboard.cloud"
#endif

#ifndef DEFAULT_PORT 
# define DEFAULT_PORT                    1883
#endif

#ifndef IOT_SETTINGS_STRING_MAXLEN
# define IOT_SETTINGS_STRING_MAXLEN 64
#endif

// Identificadores para los parametros utilizados por la clase IotSettings
#define WIFI_SSID_ID              "wifi_ssid"
#define WIFI_PASS_ID              "wifi_pass"
#define ADJUSTMENT_PASSWORD_ID    "password"
#define AP_CONNECTION_TIMEOUT_ID  "APConnTimeout"
#define RECALIBRATION_NEED_ID     "recalibration"
#define CLOUD_HOST_ID             "CloudHost"
#define CLOUD_PORT_ID             "CloudPort"
#define TIME_ZONE_ID              "TZone"
#define NTP_SERVER_ID             "NTP_Host"

size_t IotSettings::setWifiSSID( const char *ssid ){
  return putString( WIFI_SSID_ID, ssid );
}

size_t IotSettings::getWifiSSID( char *ssid ){
  return getString( WIFI_SSID_ID, ssid, IOT_SETTINGS_STRING_MAXLEN );
}

size_t IotSettings::getWifiPassword( char *pass ){
  return getString(WIFI_PASS_ID, pass, IOT_SETTINGS_STRING_MAXLEN );    
}


size_t IotSettings::setWifiPassword( const char *pass ){
  return putString( WIFI_PASS_ID, pass );
}

size_t IotSettings::getAdjustmentPassword( char *pass ){
  return getString(ADJUSTMENT_PASSWORD_ID, pass, IOT_SETTINGS_STRING_MAXLEN );    
}

size_t IotSettings::setAdjustmentPassword( const char *pass ){
  return putString(ADJUSTMENT_PASSWORD_ID, pass );    
}

void IotSettings::setAccessPointConnectionTimeout( int32_t timeout ){
  putInt( AP_CONNECTION_TIMEOUT_ID, timeout );
}

int32_t IotSettings::getAccessPointConnectionTimeout(){
  return getInt(AP_CONNECTION_TIMEOUT_ID, DEFAULT_CONNECTION_TIMEOUT);
}

void IotSettings::setRecalibrationNeed( bool recal){
  putBool( RECALIBRATION_NEED_ID, recal );
}

bool IotSettings::getRecalibrationNeed(){
  return getBool( RECALIBRATION_NEED_ID, false );
}

void IotSettings::setCloudHost( const char *host, uint16_t port  ){
  putString( CLOUD_HOST_ID, host );
  if( port != 0 )
    setCloudPort(port);
};

size_t IotSettings::getCloudHost( char *host ){
  return getString( CLOUD_HOST_ID, host, IOT_SETTINGS_STRING_MAXLEN );
}

size_t IotSettings::setCloudCredential( const char *credential_id, const char *credential ) {
  return putString( credential_id, credential );
}

size_t IotSettings::getCloudCredential( const char *credential_id, char *credential ) {
  getString( credential_id, credential, IOT_SETTINGS_STRING_MAXLEN );
}

void IotSettings::setCloudPort( uint16_t port ){
  putUShort(CLOUD_PORT_ID, port);
}

uint16_t IotSettings::getCloudPort(){
  return getUShort( CLOUD_PORT_ID, DEFAULT_PORT);
}

void IotSettings::setTimeZone( const char* time_zone ){
  putString( TIME_ZONE_ID, time_zone );
}

size_t IotSettings::getTimeZone( char *time_zone ){
  return getString( TIME_ZONE_ID, time_zone, 64 );
}

void IotSettings::setSensorTransmitionPeriod( const char* sensor_name, uint32_t period ){
  putUInt( sensor_name, period );
}

uint32_t IotSettings::getSensorTransmitionPeriod( const char* sensor_name ){
  return getUInt( sensor_name, 1000*60 );
}

void IotSettings::setNTPServer( const char *ntp ){
  putString( NTP_SERVER_ID, ntp );
}

size_t IotSettings::getNTPServer( char *ntp ){
  return getString(NTP_SERVER_ID, ntp, IOT_SETTINGS_STRING_MAXLEN);
}

void IotSettings::setDefault(){
  clear();
  setWifiSSID( DEFAULT_WIFI_SSID );
  setWifiPassword( DEFAULT_WIFI_PASS );
  setNTPServer( DEFAULT_NTP_SERVER );
  setTimeZone( DEFAULT_TIME_ZONE );
  setAccessPassword(DEFAULT_ACCESS_PASSWORD);
  setCloudHost( DEFAULT_HOST );
  setCloudPort( DEFAULT_PORT );
  /// TODO: verificar el puerto por default y poner que se ejecute Settings.setDefault()
}
