# Dist-Nx

### About

Dist-Nx is a Arduino library to use [Dist-Nx sensors].

The library is not complete, further tests are needed, currently 
I developed the library using a DIST-Nx V2 sensor.

you need  [Arduino I2C master library] to use the library. The Wire 
library issued with the Arduino IDE does not support the whole 
I2C protocol as _repeat start_.

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

### Features

 - [x] LSB distance
 - [ ] Get distance for all mode
 - [ ] Get sensors data
 - [ ] Get voltage from sensor
 

[Dist-Nx sensors]: http://www.mindsensors.com/index.php?module=pagemaster&PAGE_user_op=view_page&PAGE_id=73
[Arduino I2C master library]: http://dsscircuits.com/articles/arduino-i2c-master-library
 

