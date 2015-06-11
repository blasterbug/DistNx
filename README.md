# Dist-Nx

### About

Dist-Nx is a Arduino library to use [Dist-Nx sensor](http://www.mindsensors.com/index.php?module=pagemaster&PAGE_user_op=view_page&PAGE_id=73)

The library is not complete. futher tests are needed, currently I developed the
library using an V2 sensor.

Dist-Nx uses [Arduino I2C master library](http://dsscircuits.com/articles/arduino-i2c-master-library).


### Installation (Unix like systems)

Open a terminal and run :
```bash
$ cd <UserDirectory>/Arduino/libraries
$ git clone https://github.com/blasterbug/Dist-Nx.git
```

Now after (re)starting the Arduino IDE you shloud see Dist-Nx in Arduino 
libraries menu.

### Exemple

Here is an exemple of the minimal code to use the sensor. The programme display
every second the measured distance.

```arduino
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
    get_distance_LSB( &distance );
    // display distance
    Serial.print( F("Distance = ") );
    Serial.print( distance );
    Serial.println( F(" cm") );
    // wait a second
    delay( 1000 );
}
```

### Working

 - LSB distance


### TODO

 - Get distance for all mode
 - Get sensors data
 - Get voltage from sensor
