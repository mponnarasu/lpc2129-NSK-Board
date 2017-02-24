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

/******************************************************************************
 *
 * Function Name: void SevenSeg_Display(char j)
 *
 * Description:  
 *    This function switches OFF the 7-Segment Display
 *
 * Parameters: 
 *    char j - character to display
 *
 * Returns:
 *    void
 *
 *****************************************************************************/
void SevenSeg_Display(char j)
{
	IOSET0 = (IOSET0) | 0x0001FF00;              
	switch(j)
	{
	   case 0:
			IOCLR0 = SEVENSEG_ZERO;
			break;
	   case 1:
			IOCLR0 = SEVENSEG_ONE;
			break;
	   case 2:
			IOCLR0 = SEVENSEG_TWO;
			break;
	   case 3:
			IOCLR0 = SEVENSEG_THREE;
			break;
	   case 4:
   			IOCLR0 = SEVENSEG_FOUR;
			break;
	   case 5:
   			IOCLR0 = SEVENSEG_FIVE;
			break;
	   case 6:
   			IOCLR0 = SEVENSEG_SIX;
			break;
       case 7:
   			IOCLR0 = SEVENSEG_SEVEN;
			break;
	   case 8:
   			IOCLR0 = SEVENSEG_EIGHT;
			break;
	   case 9:
   			IOCLR0 = SEVENSEG_NINE;
   			break;
	   case 10:
   			IOCLR0 = SEVENSEG_A;
   			break;
	   case 11:
   			IOCLR0 = SEVENSEG_B;
   			break;
	   case 12:
   			IOCLR0 = SEVENSEG_C;
   			break;
	   case 13:
   			IOCLR0 = SEVENSEG_D;
   			break;
	   case 14:
   			IOCLR0 = SEVENSEG_E;
   			break;
	   case 15:
   			IOCLR0 = SEVENSEG_F;
   			break;
	   default:
   			IOCLR0 = SEVENSEG_OFF;
            break;
	}
} 
