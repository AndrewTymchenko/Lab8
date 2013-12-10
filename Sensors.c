/*
 * Sensors.c
 *
 *  Created on: Dec 5, 2013
 *      Author: C15Andrew.Tymchenko
 */

#include "Sensors.h"

void initializeADC10(){ //enable interrupts
	ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE;
	ADC10CTL1 = ADC10DIV_7;

	ADC10AE0 |= BIT3|BIT4|BIT5; //set pins for interrupts
	ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;
}

unsigned int getLeftSensorValue(){
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 &= ~(INCH3|INCH2|INCH1|INCH0);
	ADC10CTL1 |= INCH_3; //set input

	ADC10CTL0 |= ENC + ADC10SC;
	_bis_SR_register(CPUOFF + GIE);

	return ADC10MEM;
}

unsigned int getRightSensorValue(){
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 &= ~(INCH3|INCH2|INCH1|INCH0);
	ADC10CTL1 |= INCH_4;

	ADC10CTL0 |= ENC + ADC10SC;
	_bis_SR_register(CPUOFF + GIE);

	return ADC10MEM;
}

unsigned int getCenterSensorValue(){
	ADC10CTL0 &= ~ENC;
	ADC10CTL1 &= ~(INCH3|INCH2|INCH1|INCH0);
	ADC10CTL1 |= INCH_5;

	ADC10CTL0 |= ENC + ADC10SC;
	_bis_SR_register(CPUOFF + GIE);

	return ADC10MEM;
}
