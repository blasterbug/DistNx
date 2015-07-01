/**
* Display few data about the DIST-Nx sensor
*
* @date 2015/06/29
* @author Benjamin Sientzoff
* @version 0.1
*/

// import libraries
#include <I2C.h>
#include <DistNx.h>

char soft_v[9];
char vendor_id[9];
char device_id[9];

DistNx sensor;

void setup()
{
  // start serial communcation
  Serial.begin( 9600 );
  // join I2C bus
  I2c.begin();

  // read software version
  sensor.softwareVersion( soft_v );
  // read vendor ID
  sensor.vendorId( vendor_id );
  // read Device ID
  sensor.deviceId( device_id );

  // display device ID
  Serial.println( device_id );
  // display vendor ID
  Serial.println( vendor_id );
  // display software version
  Serial.println( soft_v );
}

void loop()
{
  // do nothing
}
