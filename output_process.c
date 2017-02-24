/******************************************************************************
 * Copyright 2016 
 * Author: Ponnarasu M.
 * No guarantees, warrantees, or promises, implied or otherwise.
 * May be used for hobby or commercial purposes provided copyright
 * notice remains intact.
 *
 *****************************************************************************/

#include <lpc21xx.h>
#include "Lcd.h"
#include "global_data.h"
#include "SevenSeg.h"

static unsigned long line_command = LCD_CUR_BEG2L;
 
static void delay(unsigned long delay)
 {
  do{
 	   delay--;
    }while(delay>0);

 }


/******************************************************************************
 *
 * Function Name: void Output_dataproc(void)
 *
 * Description:  
 *    Display buffer when data is full
 *
 * Parameters: 
 *    void
 *
 * Returns:
 *    void
 *
 *****************************************************************************/
void Output_dataproc(void)
{
  int c=0; // counter
  unsigned char *p;
   static unsigned char Seg_count;
  if(output_buffer_status == 1)
  {
     Lcd_WriteCommand(LCD_CLR_DISP);
	 if(line_command == LCD_CUR_BEG2L)
	 {
		line_command = LCD_CUR_BEG1L;
		p = output_buffer1;
		if(Seg_count >= 15)
		{
		  Seg_count = 0;	
		}
	    else
		{
		  Seg_count ++;          		
		}
	  	SevenSeg_Display(Seg_count);
	 }else
	 {
		  line_command = LCD_CUR_BEG2L;
		  p = output_buffer2;
		  output_buffer_status = 0;
	 }
	 for(c=0;c<16;c++)
	 {
		  Lcd_DispChar(p[c]);
		  delay(500);
	 }
	  Lcd_WriteCommand(LCD_CUR_BEG1L);
  }
}
