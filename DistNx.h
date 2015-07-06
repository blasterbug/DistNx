/**
 * @file DistNx.h
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
 */
#ifndef _DISTNX_H_
#define _DISTNX_H_

// DIST-Nx Commands
#define DIST_CMD_ENERGIZED     0x45
#define DIST_CMD_DEENERGIZED   0x44
#define DIST_CMD_ADPA_ON       0x4E
#define DIST_CMD_ADPA_OFF      0x4F

// DIST-Nx Registers
#define DIST_REG_VERSION       0x00
#define DIST_REG_VENDORID      0x08
#define DIST_REG_DEVICEID      0x10
#define DIST_REG_CMD           0x41
#define DIST_REG_DIST_LSB      0x42
#define DIST_REG_DIST_MSB      0x43
#define DIST_REG_VOLT_LSB      0x44
#define DIST_REG_VOLT_MSB      0x45
#define DIST_REG_MODULE_TYPE   0x50
#define DIST_REG_NUM_POINTS    0x51
#define DIST_REG_DIST_MIN_LSB  0x52
#define DIST_REG_DIST_MIN_MSB  0x53
#define DIST_REG_DIST_MAX_LSB  0x54
#define DIST_REG_DIST_MAX_MSB  0x55
#define DIST_REG_VOLT1_LSB     0x56
#define DIST_REG_VOLT1_MSB     0x57
#define DIST_REG_DIST1_LSB     0x58
#define DIST_REG_DIST1_MSB     0x59

//DIST-Nx default I2C Address
#define DIST_DEFAULT_ADDR 0x1

/** 
 * DIST-Nx class to encapsulate sensor behavior
 *
 */

class DistNx {
    
    public:
    
    /**
     * Create a new sensor object with the dafult I2C address (`0x1`).
     */
    DistNx( );
    
    /**
     * Use a new distance sensor with a custom I2C address.
     * @param address custom I2C address for the new sensor.
     */
    DistNx( const uint8_t address );
    
    /**
     * Switch on DIST-Nx sensor (by default, the sensor is on).
     *
     * You should wait 40ms after that.
     */
    void switchOn( );    
    /**
     * Switch off DIST-Nx sensor.
     */
    void switchOff( );    
    /**
     * Disable ADPA mode
     */
    void disableAdpa( );    
    /**
     * Enable ADPA mode
     */
    void enableAdpa( );
    
    /**
     * Set a custom I2C address for the sensor.
     *
     * **Be careful !** This new address is effective immediately. Please note down 
     * your address carefully for future reference.
     * I2C addresses are 7 bits long. So you can set addresses from `0x1` (1) to
     * `0x7F` (7). `0x0` is reserved to I2C master (the Arduino ).
     * @param new_address The new I2C address for the sensor.
     */
    void setAddress( const uint8_t new_address);
    
    /**
     * Get software version.
     * @return Software version in a String.
     */
    String softwareVersion( );    
    
    /**
     * Get Vendor ID.
     * @return Vendor ID in a String.
     */
    String vendorId( );  
    
    /**
     * Get device ID.
     * @return Device ID in a String.
     */
    String deviceId( );    
    
    /**
     * Get long distance from DIST-Nx.
     *
     * Longue distance values from 30 to 140 cm with highest 
     * precision in zone 40 cm to 90 cm for V2 and 30 cm to 100 cm for V3.
     * @return Long distance in millimeters
     */
    int longDistance( void );
    
    /**
     * Get medium distance from DIST-Nx.
     *
     * Medium distance values from 10 to 80 cm with highest 
     * precision in zone 10 cm to 40 cm for V2 and 10 cm to 40 cm for V3.
     * @return Medium distance in millimeters
     */
    int mediumDistance( void );
    
    /**
     * Get long distance voltage from DIST-Nx.
     * @return Voltage for long distance in millivolts.
     */
    int longVoltage( void );
    
    /**
     * Get medium distance voltage from DIST-Nx.
     * @return Voltage for medium distance in millivolts.
     */
    int mediumVoltage( void );
    
    private:
    uint8_t __i2c_address;
};

#endif

