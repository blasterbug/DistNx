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
 * @date 2015/07/01
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
 * Create a new sensor object with the dafult I2C address (0x1)
 */
DistNx::DistNx( ) : __i2c_address( DIST_DEFAULT_ADDR ) {};

/**
 * Use a new distance sensor with a custom I2C address
 * @param address custom I2C address for the new sensor
 */
DistNx::DistNx( uint8_t address ) : __i2c_address( address ) {};

/**
 * Switch on DIST-Nx sensor. (By default, the sensor is on.)
 * you should wait 40ms after that.
 */
void DistNx::switchOn()
{
    I2c.write( __i2c_address, DIST_CMD_ENERGIZED, 1 );
}

/**
 * Switch off DIST-Nx sensor.
 */
void DistNx::switchOff()
{
    I2c.write( __i2c_address, DIST_CMD_DEENERGIZED, 1 );
}

/**
 * Disable ADPA mode
 */
void DistNx::disableAdpa()
{
    I2c.write( __i2c_address, DIST_CMD_ADPA_OFF, 1 );
}

/**
 * Enable ADPA mode
 */
void DistNx::enableAdpa()
{
    I2c.write( __i2c_address, DIST_CMD_ADPA_ON, 1 );
}

/**
 * Get software version
 * @param[out] sv Software version, should at least be 9 char long
 */
void DistNx::softwareVersion( char* sv )
{
    I2c.write( __i2c_address, DIST_REG_CMD, DIST_REG_VERSION );
    I2c.read( __i2c_address, DIST_REG_VERSION, 8, (uint8_t*)sv );
    // append null-terminated string
    sv[8] = '\0';
}

/**
 * Get Vendor ID
 * @param[out] vendor_id Vendor ID, should at least be 9 char long
 */
void DistNx::vendorId( char* vendor_id )
{
    I2c.write( __i2c_address, DIST_REG_CMD, DIST_REG_VENDORID );
    I2c.read( __i2c_address, DIST_REG_VENDORID, 8, (uint8_t*)vendor_id);
    // append null-terminated string
    vendor_id[8] = '\0';
}

/**
 * Get device ID
 * @param[out] device_id device ID, should at least be 9 char long
 */
void DistNx::deviceId( char* device_id )
{
    I2c.write( __i2c_address, DIST_REG_CMD, DIST_REG_DEVICEID );
    I2c.read( __i2c_address, DIST_REG_DEVICEID, 8, (uint8_t*)device_id );
    // append null-terminated string
    device_id[8] = '\0';
}



/**
 * Ask for long distance from DIST-Nx
 * Longue distance values from 30 to 140 cm (with highest 
 * precision in zone 40 cm to 90 cm for V2 and 30 cm to 100 cm for V3)
 * @param[out] distance Long distance
 */
void DistNx::longDistance( int* distance )
{
    //unsigned int distance = 0;
    I2c.write( __i2c_address, DIST_REG_CMD, DIST_REG_DIST_LSB );
    //I2c.read( __i2c_address, DIST_REG_DIST_LSB, 2 );
    //(*distance) = I2c.receive();
    //(*distance) |= I2c.receive() << 8;
    I2c.read( __i2c_address, DIST_REG_DIST_LSB, 2, (uint8_t*)distance );
}

/**
 * Ask for medium distance from DIST-Nx
 * Medium distance values from 10 to 80 cm (with highest 
 * precision in zone 10 cm to 40 cm for V2 and 10 cm to 40 cm for V3)
 * @param[out] distance medium distance
 */
void DistNx::mediumDistance( int* distance )
{
    //unsigned int distance = 0;
    I2c.write( __i2c_address, DIST_REG_CMD, DIST_REG_DIST_MSB );
    I2c.read( __i2c_address, DIST_REG_DIST_MSB, 2, (uint8_t*)distance );
    //I2c.read( __i2c_address, DIST_REG_DIST_MSB, 2 );
    //(*distance) = I2c.receive();
    //(*distance) |= I2c.receive() << 8;
}

/**
 * Ask for long voltage from DIST-Nx
 * @param[out] measure voltage for long distance
 */
void DistNx::longVoltage( int* measure )
{
    I2c.write( __i2c_address, DIST_REG_CMD, DIST_REG_VOLT_LSB );
    I2c.read( __i2c_address, DIST_REG_VOLT_LSB, 2, (uint8_t*)measure );
}

/**
 * Ask for medium voltage from DIST-Nx
 * @param[out] measure voltage for medium distance
 */
void DistNx::mediumVoltage( int* measure )
{
    I2c.write( __i2c_address, DIST_REG_CMD, DIST_REG_VOLT_MSB );
    I2c.read( __i2c_address, DIST_REG_VOLT_MSB, 2, (uint8_t*)measure );
}

#endif
