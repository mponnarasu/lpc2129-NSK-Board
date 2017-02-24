/******************************************************************************
 * Copyright 2016 
 * Author: Ponnarasu M.
 * No guarantees, warrantees, or promises, implied or otherwise.
 * May be used for hobby or commercial purposes provided copyright
 * notice remains intact.
 *
 *****************************************************************************/
                  
#include <LPC21xx.H>                       /* LPC21xx definitions  */
#include "Lcd.h"

/******************************************************************************
 *
 * Function Name: void LcdCheckReady(void)
 *
 * Description:  
 *    This function check if LCD is ready
 *
 * Parameters: 
 *    void
 *
 * Returns:
 *    void
 *
 *****************************************************************************/
static void LcdCheckReady(void)
 	 {
		IODIR1=(LCD_D7_PIN_MASK ^ LCD_DATA_PIN_MASK); /* MAKE D7 AS A INPUT PIN & D0-D6 AS OUTPUT PINS  */
	   	IOSET1=LCD_D7_PIN_MASK;				/*MAKE D7=1*/
	   	IOCLR0=LCD_RS_PIN_MASK;	 			/* RS(P0.28)=0  */
		IOSET0=LCD_RW_PIN_MASK;				 /* R/W(P0.29)=1  */
	   	while((IOPIN1&LCD_D7_PIN_MASK)== LCD_D7_PIN_MASK)  /* IF D7 IS HIGH STAY HERE  */
		{		   
			IOCLR0=LCD_EN_PIN_MASK;		  				/* EN(P0.30)=0  */
			IOSET0=LCD_EN_PIN_MASK;			 	 		/* EN(P0.30)=1  */	   
		}
	    IODIR1 =LCD_DATA_PIN_MASK;				/* P1.16..23 defined as Outputs  */	 
	 }
  
/******************************************************************************
 *
 * Function Name: void Lcd_DispChar(void)
 *
 * Description:  
 *    This function is used to write display data into LCD
 *
 * Parameters: 
 *    unsigned char input: ASCII data to be written
 *
 * Returns:
 *    void
 *
 *****************************************************************************/
 void Lcd_DispChar(unsigned char input)
 	{
		LcdCheckReady();	
	 	IOPIN1 = (((unsigned long)input)<<16);
		IOSET0=LCD_RS_PIN_MASK;				/* RS(P0.28)=1  */
	    IOCLR0=LCD_RW_PIN_MASK;				/* R/W(P0.29)=0  */
	    IOSET0=LCD_EN_PIN_MASK;				/* EN=1  */
		IOCLR0=LCD_EN_PIN_MASK;				/* EN=0  */
	 }


/******************************************************************************
 *
 * Function Name: void Lcd_WriteCommand(void)
 *
 * Description:  
 *    This function is used to write command into LCD
 *
 * Parameters: 
 *    unsigned long command: see LCD.h
 *
 * Returns:
 *    void
 *
 *****************************************************************************/
void Lcd_WriteCommand(unsigned long command)
	 {
         LcdCheckReady();
	     IOPIN1=command; 
		 IOCLR0=LCD_RS_PIN_MASK;	   			/* RS(P0.28)=0  */
		 IOCLR0=LCD_RW_PIN_MASK;				/* R/W(P0.29)=0  */
		 IOSET0=LCD_EN_PIN_MASK;				/* EN(P0.30)=1  */
		 IOCLR0=LCD_EN_PIN_MASK;				/* EN(P0.30)=0  */			 
	 }

/******************************************************************************
 *
 * Function Name: void Lcd_Init(void)
 *
 * Description:  
 *    This function initialized LCD
 *
 * Parameters: 
 *    void
 *
 * Returns:
 *    void
 *
 *****************************************************************************/
void Lcd_Init(void)
	{
		Lcd_WriteCommand(LCD_DISP_PROP);
		Lcd_WriteCommand(LCD_DON_COFF);
		Lcd_WriteCommand(LCD_RS_CURS);
		Lcd_WriteCommand(LCD_CLR_DISP);
			   	   
    }
