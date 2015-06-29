/**
 * Display several data about the DIST-Nx sensor
 * 
 * @date 2015/06/29
 * @author Benjamin Sientzoff
 * @version 0.1
 */

// import libraries
#include <I2C.h>
#include <DistNx.h>

int distance;
char soft_v[8];
char vendor_id[8];

void setup()
{
  Serial.begin( 9600 );
  I2c.begin();
}

void loop()
{
  get_long_distance( &distance );
  // display distance
  Serial.print( F("long distance = ") );
  Serial.println( distance );
  delay( 1000 );
}
