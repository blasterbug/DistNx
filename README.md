# Dist-Nx

### About

Dist-Nx is a Arduino library to use [Dist-Nx sensors].

The library is not complete, further tests are needed, currently 
I developed the library using a DIST-Nx V2 sensor.

### Requirements

You need  [Arduino I2C master library] to use the library because the Wire 
library issued with the Arduino IDE does not support the whole 
I2C protocol, for instance *repeat start*.

### Features

- [x] LSB distance (long distance)
- [x] LSB voltage
- [x] MSB distance (medium distance)
- [x] MSD voltage
- [ ] Get sensors data
- [ ] Calibration
- [ ] Change I2C Bus address
- [ ] Switch off/on sensor

### Installation (Unix like systems)

Open a terminal and run :
```bash
$ cd <UserDirectory>/Arduino/libraries
$ git clone https://github.com/blasterbug/Dist-Nx.git
```

Or if you prefer, download the zip or the last release and directly unzip it in the `Arduino/libraries` folder.

Now after (re)starting the Arduino IDE you shloud see Dist-Nx in Arduino 
libraries menu.

### Example

Here is an exemple of the minimal code to use the sensor. The programme display
every second the measured long distance.

```arduino
// import libraries
#include <I2C.h>
#include <DistNx.h>

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
  get_long_distance( &distance );
  // display distance
  Serial.print( F("long distance = ") );
  Serial.println( distance );
  // wait 1 second
  delay( 1000 );
}
```
 

[Dist-Nx sensors]: http://www.mindsensors.com/index.php?module=pagemaster&PAGE_user_op=view_page&PAGE_id=73
[Arduino I2C master library]: http://dsscircuits.com/articles/arduino-i2c-master-library
 

