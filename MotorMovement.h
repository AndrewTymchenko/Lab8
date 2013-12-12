/*
 * MotorMovement.h
 *
 *  Created on: Nov 19, 2013
 *      Author: C15Andrew.Tymchenko
 */
#include <msp430.h>
#ifndef MOTORMOVEMENT_H_
#define MOTORMOVEMENT_H_

void initializePWM();

void smallLeft();

void smallRight();

void largeLeft();

void largeRight();

void moveForward();

void moveBackwards();

void slowLeftMotor();

void slowRightMotor();



#endif /* MOTORMOVEMENT_H_ */
