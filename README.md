# Dist-Nx

### About

Dist-Nx is a Arduino library to use [Dist-Nx sensors].

Distance registers provide Distance information in millimeters.  
Voltage registers provide the raw voltage in milli-volts.

### Requirements

You need  [Arduino I2C master library] to use the library because the Wire 
library issued with the Arduino IDE does not support the whole 
I2C protocol, for instance *repeat start*.

### Features

- [x] LSB distance (long distance)
- [x] LSB voltage
- [x] MSB distance (medium distance)
- [x] MSD voltage
- [x] ADPA mode
- [x] Get sensors data
- [x] Switch off/on sensor
- [x] Connect to an I2C customized Address
- [x] Change I2C address
- [ ] Calibration
- [ ] Data point measures

### Installation (Unix like systems)

Open a terminal and run :
```bash
$ cd <UserDirectory>/Arduino/libraries
$ git clone https://github.com/blasterbug/Dist-Nx.git
```

Or if you prefer, download the zip (of the last release) and directly unzip it in the `Arduino/libraries` folder.

Now after (re)starting the Arduino IDE you should see Dist-Nx in Arduino 
libraries menu. Two exemples are provided with the library.

Get more details on [Arduino libraries installation guide].

### Example

Here is an exemple of the minimal code to use the sensor. The programme display
every second the measured long distance.

```arduino
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
```

### Documentation

Read the documentation on the repository wiki [here](https://github.com/blasterbug/DistNx/wiki) or you can generate it with Doxygen as follow.

```bash
$ doxygen Doxyfile
```
After printing some ouput, you should get a `html` folder. Then open 
`index.html`in your favorite web browser. Of course, source code is commented.

### About ADPA

This sensor supports Auto Detecting Parallel Architecture (ADPA) for sensors. This means that DIST-Nx can coexist with LEGO or third party digital sensors on a single I2C bus. This enables user to employ several sensors on the same bus without the need of external sensor multiplexer, reducing the overall size and cost. By default, the ADPA mode is disabled.

[Dist-Nx sensors]: http://www.mindsensors.com/index.php?module=pagemaster&PAGE_user_op=view_page&PAGE_id=73
[Arduino I2C master library]: http://dsscircuits.com/articles/arduino-i2c-master-library
[DIST-Nx wiki]: https://github.com/blasterbug/DistNx/wiki
[Arduino libraries installation guide]: https://www.arduino.cc/en/Reference/APIStyleGuide