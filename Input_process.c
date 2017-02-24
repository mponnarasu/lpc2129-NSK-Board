/******************************************************************************
 * Copyright 2016 
 * Author: Ponnarasu M.
 * No guarantees, warrantees, or promises, implied or otherwise.
 * May be used for hobby or commercial purposes provided copyright
 * notice remains intact.
 *
 *****************************************************************************/
#include <lpc21xx.h>
#include "global_data.h"
#include "schedule.h"
unsigned long * StartAddress = 0;

/******************************************************************************
 *
 * Function Name: void Input_dataproc(void)
 *
 * Description:  
 *    Fill input buffer with data to be processed 
 *
 * Parameters: 
 *    void
 *
 * Returns:
 *    void
 *
 *****************************************************************************/
void Input_dataproc(void)
{
	unsigned short temp;
	if((unsigned long)StartAddress == 0x00001000)
	{
	   Stop_Schedule();
	}

	if(input_buffer_status == 0)	
	{	
		do
		{
			input_buffer[input_buffer_insert_idx] = (unsigned long)StartAddress;
			input_buffer[input_buffer_insert_idx+1] = *StartAddress;
			temp = (input_buffer_insert_idx+2) % INPUT_BUFFER_SIZE;
	   		input_buffer_insert_idx = temp; // update insert index
			StartAddress++;
		}while(input_buffer_insert_idx != input_buffer_extract_idx);
		input_buffer_status = 1;
	}
}

