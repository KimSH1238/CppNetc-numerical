/*
  This file is part of the Arduino_Qtouch library.
  Copyright (c) 2019 Arduino SA. All rights reserved.
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <Arduino_Qtouch.h>

QtouchClass::QtouchClass()
{

}


QtouchClass::~QtouchClass()
{

}

/*******************************************************************************
 * Function Name  : begin
 * Description    : Initializes Qtouch sensors
 * Input          : NONE
 * Return         : false on Error, true on Success
 *******************************************************************************/
bool QtouchClass::begin() {
  // touch sensors init
  if (touch_sensors_init()){
    return false;
  }
    // set starting measure time to 0 and chenge the analog resolution to 10
  touch_time.current_time_ms = 0;
  analogReadResolution(10);
  return true;
}

/*******************************************************************************
 * Function Name  : available
 * Description    : Checks for new values availability
 * Input          : NONE
 * Return         : 0 on no data, 1 on measure availability
 *******************************************************************************/
int QtouchClass::available() {
  // check if a measure is done
  if ((p_selfcap_measure_data->measurement_done_touch == 1u)) {
        p_selfcap_measure_data->measurement_done_touch == 0u;
        return 1;
  }
  return 0;
}
/*******************************************************************************
 * Function Name  : poll
 * Description    : Polls the qotuch sensors for new measure
 * Input          : NONE
 * Return         : NONE
 *******************************************************************************/
void QtouchClass::poll() {
    // set time flag to 1 and starting time millis()
    touch_time.time_to_measure_touch = 1;
    touch_time.current_time_ms = touch_time.current_time_ms + millis();

    // trigger a new measure
    touch_sensors_measure(); 
}

/*******************************************************************************
 * Function Name  : read
 * Description    : Querys the Qtouch and returns new touch measure
 * Input          : sensor_id - Sensor identificator
 * Return         : -1 on Error, touch measure state on Success
 *******************************************************************************/
int QtouchClass::read(int sensor_id) {
  // checks if sensor_id exists
  if( sensor_id < DEF_SELFCAP_NUM_SENSORS) {
    // returns the updated sensor's state and shift it in order to be 0 or 1
    return (GET_SELFCAP_SENSOR_STATE(sensor_id)) >> sensor_id;
  }
  return -1;
}

/*******************************************************************************
 * Function Name  : setSensorsSensitivity
 * Description    : Sets the sensors sensitivity value
 * Input          : newSens - new configure Sensitivity value
 * Return         : NONE
 *******************************************************************************/
void QtouchClass::setSensorsSensitivity(unsigned int newSens) {
  setSensitivity(newSens);
}

/*******************************************************************************
 * Function Name  : setSensorsHysteresis
 * Description    : Set the sensors hysteresis value
 * Input          : newHyst - new configure hysteresis value, could be:
 *                  -	HYST_50
	                  - HYST_25
	                  - HYST_12_5
	                  - HYST_6_25
	                  - MAX_HYST
 * Return         : NONE
 *******************************************************************************/
void QtouchClass::setSensorsHysteresis(hysteresis_t newHyst) {
  setHysteresis(newHyst);
}

/*******************************************************************************
 * Function Name  : getSensorsSensitivity
 * Description    : Querys the Qtouch and returns the configured Sensitivity
 *                  value
 * Input          : NONE
 * Return         : The Sensitivity value
 *******************************************************************************/
unsigned int QtouchClass::getSensorsSensitivity() {
  return getSensitivity();
}

/*******************************************************************************
 * Function Name  : getSensorsHysteresis
 * Description    : Querys the Qtouch and returns the configured hysteresis
 *                  value
 * Input          : NONE
 * Return         : The hysteresis value
 *******************************************************************************/
hysteresis_t QtouchClass::getSensorsHysteresis() {
  return getHysteresis();
}

QtouchClass TOUCH;
