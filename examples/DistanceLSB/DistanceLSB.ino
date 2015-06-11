/**
 * display distance measured by DIST-Nx every 
 * second in serial monitor
 * 
 * @date 2015/06/11
 * @author Benjamin Sientzoff
 * @version 0.1
 */

// import libraries
#include <I2C.h>
#include <DistNx.h>

int distance;

void setup()
{
    Serial.begin( 9600 );
    I2c.begin();
}

void loop()
{
    // get distance
    get_long_distance( &distance );
    // display distance
    Serial.print( F("Distance = ") );
    Serial.println( distance );
    delay( 1000 );
}
