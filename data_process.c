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
unsigned long process_address;
unsigned long process_data;

/******************************************************************************
 *
 * Function Name: void Data_process(void)
 *
 * Description:  
 *    Process data, find branch instructions in the input stream and process 
 *    data and fill in output buffer 
 *
 * Parameters: 
 *    void
 *
 * Returns:
 *    void
 *
 *****************************************************************************/

void Data_process(void)
{
unsigned long address_temp;
long temporary_adr;
int i;
unsigned short temp;
unsigned char decode_addr_temp, condition;

	 while((output_buffer_status == 0) && (input_buffer_status == 1) )
	 {
	   	process_address = input_buffer[input_buffer_extract_idx];
		process_data = input_buffer[input_buffer_extract_idx+1];
		temp = (input_buffer_extract_idx+2) % INPUT_BUFFER_SIZE;
		input_buffer_extract_idx = temp; // update extract index
		if(input_buffer_extract_idx == input_buffer_insert_idx)
		{
		   input_buffer_status = 0;
		}
		/* Check for Branch instructions */
		if((process_data & 0x0a000000) == 0x0A000000)
		{
			
			output_buffer1[0] = ' ';
			output_buffer1[1] = ' ';
			output_buffer1[2] = 'A';
			output_buffer1[3] = 'D';
			output_buffer1[4] = 'D';
			output_buffer1[5] = 'R';
			output_buffer1[6] = '=';
			temporary_adr = (signed long)process_address;
			for(i=7;i<15;i++)
			{
				decode_addr_temp = (unsigned char)(process_address >> 28); 
		
			 	if(decode_addr_temp <= 9)
				{
				  output_buffer1[i]= (decode_addr_temp + 48);
				}else
				{
				  output_buffer1[i]= (decode_addr_temp + 55);
				} 
				process_address = process_address << 4;
			}
			output_buffer1[15] = ' ';
			/* Process Data  */
			condition = (unsigned char)(process_data >> 28); 
			output_buffer2[0] = ' ';
			output_buffer2[1] = ' ';
			if(process_data & 0x01000000)
			{
				output_buffer2[2] = 'B';
				output_buffer2[3] = 'L';
			}
			else
			{
				output_buffer2[2] = ' ';
				output_buffer2[3] = 'B';
	
			}
		    switch(condition)
			{
			   case 0:
					output_buffer2[4] = 'E';
					output_buffer2[5] = 'Q';
					break;
			   case 1:
					output_buffer2[4] = 'N';
					output_buffer2[5] = 'E';
					break;
			   case 2:
					output_buffer2[4] = 'C';
					output_buffer2[5] = 'S';
					break;
			   case 3:
					output_buffer2[4] = 'C';
					output_buffer2[5] = 'C';
					break;
			   case 4:
					output_buffer2[4] = 'M';
					output_buffer2[5] = 'I';
					break;
			   case 5:
					output_buffer2[4] = 'P';
					output_buffer2[5] = 'L';
					break;
			   case 6:
					output_buffer2[4] = 'V';
					output_buffer2[5] = 'S';
					break;
		       case 7:
					output_buffer2[4] = 'V';
					output_buffer2[5] = 'C';
					break;
			   case 8:
					output_buffer2[4] = 'H';
					output_buffer2[5] = 'I';
					break;
			   case 9:
					output_buffer2[4] = 'L';
					output_buffer2[5] = 'S';
		   			break;
			   case 10:
					output_buffer2[4] = 'G';
					output_buffer2[5] = 'E';
		   			break;
			   case 11:
					output_buffer2[4] = 'L';
					output_buffer2[5] = 'T';
		   			break;
			   case 12:
					output_buffer2[4] = 'G';
					output_buffer2[5] = 'T';
		   			break;
			   case 13:
					output_buffer2[4] = 'L';
					output_buffer2[5] = 'E';
		   			break;
			   case 14:
					output_buffer2[4] = ' ';
					output_buffer2[5] = ' ';
		   			break;
			   case 15:
					output_buffer2[4] = 'T';
					output_buffer2[5] = 'H';
		   			break;
			   default:
		            break;
			}
			output_buffer2[6] = ' ';
			address_temp = (process_data & 0x00FFFFFF);
			if(address_temp & 0x0080000)
			{
				address_temp |= 0xff000000;
			}
			address_temp = address_temp << 2;
			temporary_adr +=8;
			address_temp = temporary_adr + address_temp ;
			for(i=7;i<15;i++)
			{
				decode_addr_temp = (unsigned char)(address_temp >> 28); 
		
			 	if(decode_addr_temp <= 9)
				{
				  output_buffer2[i]= (decode_addr_temp + 48);
				}else
				{
				  output_buffer2[i]= (decode_addr_temp + 55);
				} 
				address_temp = address_temp << 4;
			}
			   output_buffer2[i] = ' ';
			output_buffer_status = 1;
		}
	 };
}
