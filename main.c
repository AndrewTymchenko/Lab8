#include <msp430.h> 
#include "MotorMovement.h"
#include "Sensors.h"

int leftSensorValue, rightSensorValue, centerSensorValue;

/*
 * main.c
 */

int main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
      initializePWM();
      initializeADC10();
      P1DIR |= BIT0; //Set P1.0 and P1.6 to output
      P1DIR |= BIT6;
 for(;;){
//    	  leftSensorValue = getLeftSensorValue();
//    	  rightSensorValue = getRightSensorValue();
//    	  centerSensorValue = getCenterSensorValue();


    	  if(getLeftSensorValue() < threshhold){
    		  P1OUT &= ~BIT0;
    		  smallLeft();
    		  __delay_cycles(10000);
    	  }
    	  else{
    	    		  smallRight();
    	    		  __delay_cycles(10000);
    	    		  P1OUT |=BIT0;
    	    		      	  }
       	  if(getCenterSensorValue() > threshhold1){
       		  moveBackwards();
       		  __delay_cycles(30000);
    		  P1OUT &= ~BIT0;
    		  largeRight();
    		  //__delay_cycles(20000);
    	  }




    	  //if(rightSensorValue > threshhold){
    		  //P1OUT &= ~BIT6;
    		  //smallRight();
    		  //__delay_cycles(10000);
    	  //}
    	  //else{
    		  //P1OUT |= BIT6;
    		  //moveForward();
    		  //__delay_cycles(10000);
    	  //}
      }

      return 0;
    }

#pragma vector = ADC10_VECTOR //ADC10 interrupt service routine
__interrupt void ADC10_ISR(void){
	__bic_SR_register_on_exit(CPUOFF);
}

