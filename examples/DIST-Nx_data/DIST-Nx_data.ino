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

int distance;

void setup()
{
  // start serial communcation
  Serial.begin( 9600 );
  // join I2C bus
  I2c.begin();
  // read software version
  dist_nx_soft_version( soft_v );
  // read vendor ID
  dist_nx_vendor_id( vendor_id );
  // read Device ID
  dist_nx_device_id( device_id );

  // display device ID
  Serial.println( device_id );
  // display vendor ID
  Serial.println( vendor_id );
  // display software version
  Serial.println( soft_v );
}

void loop()
{
  // get long distance
  get_long_distance( &distance );
  // display distance
  Serial.print( F("long distance = ") );
  Serial.println( distance );
  // wait 1 second
  delay( 1000 );
}
