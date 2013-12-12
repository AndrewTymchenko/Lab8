/*
 * Sensors.h
 *
 *  Created on: Dec 5, 2013
 *      Author: C15Andrew.Tymchenko
 */
#include <msp430.h>
#ifndef SENSORS_H_
#define SENSORS_H_
#define threshhold 0x375
#define threshhold1 0x300

void initializeADC10();
unsigned int getLeftSensorValue();
unsigned int getRightSensorValue();
unsigned int getCenterSensorValue();

#endif /* SENSORS_H_ */
