/**
* Display long distance measured by DIST-Nx sensor
* every second
*
* @date 2015/06/29
* @author Benjamin Sientzoff
* @version 1.0
*/

// import libraries
#include <I2C.h>
#include <DistNx.h>

DistNx sensor;
int distance;

void setup()
{
  // start serial communication
  Serial.begin( 9600 );
  // join I2C bus
  I2c.begin();
}

void loop()
{
  // get long distance
  distance = sensor.longDistance();
  // display distance
  Serial.print( F("long distance = ") );
  Serial.print( distance );
  Serial.println( F(" mm") );
  // wait 1 second
  delay( 1000 );
}