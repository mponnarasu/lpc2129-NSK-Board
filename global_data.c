/******************************************************************************
 * Copyright 2016 
 * Author: Ponnarasu M.
 * No guarantees, warrantees, or promises, implied or otherwise.
 * May be used for hobby or commercial purposes provided copyright
 * notice remains intact.
 *
 *****************************************************************************/
#include "LPC21xx.h"
#include "global_data.h"

unsigned char output_buffer1[OUTPUT_BUFFER_SIZE] = { 'H','e','l','l','o',' ','!','!','M','S','R','U','A','S','!','\0' };
unsigned char output_buffer2[OUTPUT_BUFFER_SIZE] = { 'P','T','1','6',' ',' ','P','o','n','n','a','r','a','s','u','\0' };

//unsigned char  output_buffer[OUTPUT_BUFFER_SIZE];
//unsigned short output_buffer_insert_idx, output_buffer_extract_idx;
unsigned char output_buffer_status;

//unsigned char  input_buffer[INPUT_BUFFER_SIZE];
unsigned long  input_buffer[INPUT_BUFFER_SIZE];
unsigned short input_buffer_insert_idx, input_buffer_extract_idx;
unsigned char input_buffer_status;

/******************************************************************************
 *
 * Function Name: void Global_data_init(void)
 *
 * Description:  
 *    Initialize Global data
 *
 * Parameters: 
 *    void
 *
 * Returns:
 *    void
 *
 *****************************************************************************/

void Global_data_init(void)
{
    output_buffer_status = 0;
	input_buffer_status = 0;
    input_buffer_insert_idx = 0;
    input_buffer_extract_idx = 0;
	
}
