/*
 * MotorMovement.c
 *
 *  Created on: Nov 19, 2013
 *      Author: C15Andrew.Tymchenko
 */

#include "MotorMovement.h"

void LeftMotorForward();

void RightMotorForward();

void stopLeftMotor();

void stopRightMotor();

void initializePWM(){
	 	 	P1DIR |= BIT2;
	        P1SEL |= BIT2;
	        P2DIR |= BIT1|BIT4|BIT5;
	        P2SEL |= BIT1|BIT4|BIT5;

	        TA0CTL &= ~(MC1|MC0); //stop timer A0
	        TA1CTL &= ~(MC1|MC0);

	        TA0CTL |= TACLR; //clear timer A0
	        TA1CTL |= TACLR;

	        TA0CTL |= TASSEL1; //configure for SMCLK
	        TA1CTL |= TASSEL1;

	        TA1CCR0 = 100; //signal period 100 clock cycles
	        TA0CCR0 = 100;
	        TA0CCR1 = 0;  //FRONT LEFT is TA0.1
	        TA1CCR1 = 0;  //FRONT RIGHT is TA1.1
	        TA1CCR2 = 0;  //BACK WHEELS is TA1.2

	        TA0CCTL1 |= OUTMOD_7; //TACCTL1 to RESET/SET mode
	        TA1CCTL1 |= OUTMOD_7;
	        TA1CCTL2 |= OUTMOD_7;


	        TA0CTL |= MC0; //count up
	        TA1CTL |= MC0;
	}

	void LeftMotorForward(){
	        TA0CCR1 = 55; //C2C Mossing explained simplicity of this part
	        TA1CCR2 = 0;
	}

	void RightMotorForward(){
	        TA1CCR1 = 55;
	        TA1CCR2 = 0;
	}

	void stopLeftMotor(){
	        TA0CCR1 = 0;
	        TA1CCR2 = 0;
	}

	void stopRightMotor(){
	        TA1CCR1 = 0;
	        TA1CCR2 = 0;
	}

	void moveBackwards(){
	        stopLeftMotor();
	        stopRightMotor();
	        TA1CCR2 = 70;
	}
	void slowLeftMotor(){
		 TA0CCR1 = 30;

	}
	void smallLeft(){
	        slowLeftMotor();
	        RightMotorForward();
	}
	void slowRightMotor(){
			TA1CCR1 = 30;
	}
	void smallRight(){
	        slowRightMotor();
	        LeftMotorForward();
	}

	void largeLeft(){
	        stopLeftMotor();
	        __delay_cycles(1500000);
	        LeftMotorForward();
	}

	void largeRight(){
			LeftMotorForward();
	        stopRightMotor();
	        __delay_cycles(100000);
	        RightMotorForward();
	}

	void moveForward(){
	        LeftMotorForward();
	        RightMotorForward();
	}








