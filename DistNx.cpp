/**
 * @file DistNx.cpp
 *
 * @section desc File description
 *
 * Communicate and get te distance from DIST-Nx mindsensor
 *  (The code above should work with all version of DIST-Nx)
 *
 * @section copyright Copyright
 *
 * (c) IRCCyN 2005-2015
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @section infos File informations
 *
 * @date 2015/07/02
 * @author Benjamin Sientzoff <benjamin.sientzof@yahoo.fr>
 *
 * \page info About ADPA
 *
 * This sensor supports Auto Detecting Parallel Architecture (ADPA) for sensors. 
 * This means that DIST-Nx can coexist with LEGO or third party digital sensors
 * on a single I2C bus. This enables user to employ several sensors on the same 
 * bus without the need of external sensor multiplexer, reducing the overall 
 * size and cost. By default, the ADPA mode is disabled.
 *
 */

#ifndef _DISTNX_CPP_
#define _DISTNX_CPP_

#include "Arduino.h"
#include "DistNx.h"
#include "I2C.h"

/**
 * Create a new sensor object with the dafult I2C address (`0x1`).
 */
DistNx::DistNx( ) : __i2c_address( DIST_DEFAULT_ADDR ) {};

/**
 * Use a new distance sensor with a custom I2C address.
 * @param address custom I2C address for the new sensor.
 */
DistNx::DistNx( const uint8_t address ) : __i2c_address( address ) {};

/**
 * Switch on DIST-Nx sensor (by default, the sensor is on).
 *
 * You should wait 40ms after that.
 */
void DistNx::switchOn( )
{
    I2c.write( __i2c_address, DIST_CMD_ENERGIZED, 1 );
}

/**
 * Switch off DIST-Nx sensor.
 */
void DistNx::switchOff( )
{
    I2c.write( __i2c_address, DIST_CMD_DEENERGIZED, 1 );
}

/**
 * Disable ADPA mode
 */
void DistNx::disableAdpa( )
{
    I2c.write( __i2c_address, DIST_CMD_ADPA_OFF, 1 );
}

/**
 * Enable ADPA mode
 */
void DistNx::enableAdpa( )
{
    I2c.write( __i2c_address, DIST_CMD_ADPA_ON, 1 );
}

/**
 * Set a custom I2C address for the sensor.
 *
 * **Be careful !** This new address is effective immediately. Please note down 
 * your address carefully for future reference.
 * I2C addresses are 7 bits long. So you can set addresses from `0x1` (1) to
 * `0x7F` (7). `0x0` is reserved to I2C master (the Arduino ).
 * @param new_address The new I2C address for the sensor.
 */
void DistNx::setAddress( const uint8_t new_address)
{
    I2c.write( __i2c_address, DIST_REG_CMD, 0xA0 );
    delay( 100 );
    I2c.write( __i2c_address, DIST_REG_CMD, 0xAA );
    delay( 100 );
    I2c.write( __i2c_address, DIST_REG_CMD, 0xA5 );
    delay( 100 );
    I2c.write( __i2c_address, DIST_REG_CMD, new_address );
    delay( 100 );
    __i2c_address = new_address;
}

/**
 * Get software version.
 * @return Software version in a String.
 */
String DistNx::softwareVersion( )
{
    char sv[9];
    I2c.write( __i2c_address, DIST_REG_CMD, DIST_REG_VERSION );
    I2c.read( __i2c_address, DIST_REG_VERSION, 8, (uint8_t*)sv );
    // append null-terminated string
    sv[8] = '\0';
    return String( sv );
}

/**
 * Get Vendor ID.
 * @return Vendor ID in a String.
 */
String DistNx::vendorId( )
{
    char vendor_id[9];
    I2c.write( __i2c_address, DIST_REG_CMD, DIST_REG_VENDORID );
    I2c.read( __i2c_address, DIST_REG_VENDORID, 8, (uint8_t*)vendor_id);
    // append null-terminated string
    vendor_id[8] = '\0';
    return String( vendor_id );
}

/**
 * Get device ID.
 * @return Device ID in a String.
 */
String DistNx::deviceId( )
{
    char device_id[9];
    I2c.write( __i2c_address, DIST_REG_CMD, DIST_REG_DEVICEID );
    I2c.read( __i2c_address, DIST_REG_DEVICEID, 8, (uint8_t*)device_id );
    // append null-terminated string
    device_id[8] = '\0';
    return String( device_id );
}



/**
 * Get long distance from DIST-Nx.
 *
 * Longue distance values from 30 to 140 cm with highest 
 * precision in zone 40 cm to 90 cm for V2 and 30 cm to 100 cm for V3.
 * @return Long distance in millimeters
 */
int DistNx::longDistance( void )
{
    int distance;
    I2c.write( __i2c_address, DIST_REG_CMD, DIST_REG_DIST_LSB );
    I2c.read( __i2c_address, DIST_REG_DIST_LSB, 2, (uint8_t*)&distance );
    return distance;
}

/**
 * Get medium distance from DIST-Nx.
 *
 * Medium distance values from 10 to 80 cm with highest 
 * precision in zone 10 cm to 40 cm for V2 and 10 cm to 40 cm for V3.
 * @return Medium distance in millimeters
 */
int DistNx::mediumDistance( void )
{
    int distance;
    I2c.write( __i2c_address, DIST_REG_CMD, DIST_REG_DIST_MSB );
    I2c.read( __i2c_address, DIST_REG_DIST_MSB, 2, (uint8_t*)&distance );
    return (int)distance;
}

/**
 * Get long distance voltage from DIST-Nx.
 * @return Voltage for long distance in millivolts.
 */
int DistNx::longVoltage( void )
{
    int measure;
    I2c.write( __i2c_address, DIST_REG_CMD, DIST_REG_VOLT_LSB );
    I2c.read( __i2c_address, DIST_REG_VOLT_LSB, 2, (uint8_t*)&measure );
    return measure;
}

/**
 * Get medium distance voltage from DIST-Nx.
 * @return Voltage for medium distance in millivolts.
 */
int DistNx::mediumVoltage( void )
{
    int measure;
    I2c.write( __i2c_address, DIST_REG_CMD, DIST_REG_VOLT_LSB );
    I2c.read( __i2c_address, DIST_REG_VOLT_MSB, 2, (uint8_t*)&measure );
    return measure;
}

#endif
