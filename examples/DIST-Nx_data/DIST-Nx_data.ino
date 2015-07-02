/**
* Display few data about the DIST-Nx sensor
*
* @date 2015/06/29
* @author Benjamin Sientzoff
* @version 1.0
*/

// import libraries
#include <I2C.h>
#include <DistNx.h>

String soft_version;
String vendor_id;
String device_id;

DistNx sensor;

void setup()
{
  // start serial communcation
  Serial.begin( 9600 );
  // join I2C bus
  I2c.begin();

  // read software version
  sv = sensor.softwareVersion();
  // read vendor ID
  vendor_id = sensor.vendorId();
  // read Device ID
  device_id =sensor.deviceId();

  // display device ID
  Serial.println( device_id );
  // display vendor ID
  Serial.println( vendor_id );
  // display software version
  Serial.println( soft_version );
}

void loop()
{
  // do nothing
}