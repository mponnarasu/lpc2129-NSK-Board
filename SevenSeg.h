/******************************************************************************
 * Copyright 2016 
 * Author: Ponnarasu M.
 * No guarantees, warrantees, or promises, implied or otherwise.
 * May be used for hobby or commercial purposes provided copyright
 * notice remains intact.
 *
 *****************************************************************************/
#ifndef SEVEN_SEG_H
#define SEVEN_SEG_H


/*  bits and segment leds
           a
          ----
         |    |
        f|  g | b
          ----
         |    |
        e| d  | c
          ----
   dot (P0.15)
   a-h P0.8,P0.16 
 */
/* MCAROS defined for LPC2129 port config mentioned above, used for IOCLR0 */
#define SEVENSEG_OFF    0x0000FF00 
#define SEVENSEG_ZERO	0x0000c000
#define SEVENSEG_ONE	0x0000cF00
#define SEVENSEG_TWO	0X0000a400
#define SEVENSEG_THREE	0x0000b000
#define SEVENSEG_FOUR   0x00009900
#define SEVENSEG_FIVE	0x00009200
#define SEVENSEG_SIX	0x00008200
#define SEVENSEG_SEVEN	0x0000f800
#define SEVENSEG_EIGHT  0x00008000
#define SEVENSEG_NINE	0x00009000
#define SEVENSEG_A		0x00000800
#define SEVENSEG_B		0x00000000
#define SEVENSEG_C		0x00004600
#define SEVENSEG_D		0x00004000
#define SEVENSEG_E	    0x00000600
#define SEVENSEG_F	    0x00000E00

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
void SevenSeg_Display(char j);

#endif
