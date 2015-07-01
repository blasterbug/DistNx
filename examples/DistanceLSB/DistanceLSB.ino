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
  sensor.longDistance( &distance );
  // display distance
  Serial.print( F("long distance = ") );
  Serial.println( distance );
  // wait 1 second
  delay( 1000 );
}