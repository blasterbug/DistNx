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
 * @date 2015/04/26
 * @author Benjamin Sientzoff <benjamin.sientzof@yahoo.fr>
 *
 */

#ifndef _DISTNX_CPP_
#define _DISTNX_CPP_

#include "DistNx.h"
#include "I2C.h"

/*
 * Switch on DIST-Nx sensor. (By default, the sensor is on.)
 * you should wait 40ms after that.
 */
void init_distnx()
{

    I2c.write( DIST_ADDR, DIST_CMD_ENERGIZED, 1 );
}

/*
 * Switch on DIST-Nx sensor. (by default, the sensor is on.)
 * you should wait at least 40ms after that.
 */
void get_distance_LSB( int* distance )
{
    //unsigned int distance = 0;
    I2c.write( DIST_ADDR, DIST_REG_CMD, DIST_REG_DIST_LSB );
    //I2c.read( DIST_ADDR, DIST_REG_DIST_LSB, 2 );
    //(*distance) = I2c.receive() ;
    //(*distance) |= I2c.receive() << 8;
    I2c.read( DIST_ADDR, DIST_REG_DIST_LSB, 2, (uint8_t*)distance );
}

#endif
