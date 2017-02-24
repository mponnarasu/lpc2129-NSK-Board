/******************************************************************************
 * Copyright 2016 
 * Author: Ponnarasu M.
 * No guarantees, warrantees, or promises, implied or otherwise.
 * May be used for hobby or commercial purposes provided copyright
 * notice remains intact.
 *
 *****************************************************************************/
#include <lpc21xx.h>
#include "SevenSeg.h"
/* Choose either UART or Keypad */
/* P0.0 & P0.1  UART0 (alt 1) 0x00000003  */
/* P0.0 to P0.7  KEYPAD(alt 0) 0x00000000 */
/* P0.8 to P0.15 7Seg Data */

#define SELPIN_0_VAL 0x00000005

/* P0.16 to P0.19 7 seg sel line          */ 
/* P0.20 EINT3  (alt2) 0x3                */
/* P0.21 unused (can be used for PWM or timer input) */
/* P0.22 to P0.24 CAN alt 1 0x1 */
/* P0.25 (can be used for T0 Capture/match)*/
/* P0.26 reserved */
/* P0.27 ADC */
/* P0.28 - P0.30 LCD DIO (alt 0)  */
/* P0.31 Reserved */
/* ADC, CAN, EINT3 */
//	  SELPIN_1_VAL 0x00415300;  
/* ADC, CAN */
//	  SELPIN_1_VAL 0x00415000;  
 /* EINT */
//	  SELPIN_1_VAL 0x00000300; 
 /* ADC + DIO */
#define SELPIN_1_VAL 0x00000000

/* P1.16 to P1.25 LCD Data (Alt 0)  */
/* P1.26 to P1.31 Debug interface Alt 1 */
/* Debug + LCD */
//	  SELPIN_2_VAL 0x55500000;  

#define SELPIN_2_VAL 0x00000000

#define PORT0DIR_VAL 0x710FFFF0

#define PORT1DIR_VAL 0x01FF0000
extern void Reset_Handler(void);

/******************************************************************************
 *
 * Function Name: void Board_Init(void)
 *
 * Description:  
 *    Initialized port and i/O base on board usage 
 *
 * Parameters: 
 *    void
 *
 * Returns:
 *    void
 *
 *****************************************************************************/

void Board_Init(void)
{

	  PINSEL0=SELPIN_0_VAL;

	  PINSEL1=SELPIN_1_VAL;  

	  IO0DIR =PORT0DIR_VAL; 

	  PINSEL2=SELPIN_2_VAL;  /* LCD  */

	  IO1DIR =PORT1DIR_VAL; 

      VICIntEnClr = 0xFFFFFFFF;           // clear all interrupts
      VICIntSelect = 0x00000000;            // clear all FIQ selections
      VICDefVectAddr = (unsigned long)Reset_Handler;     // point unvectored IRQs to reset()
	  SevenSeg_Display(16); // switch off Seven Segment Display

}


