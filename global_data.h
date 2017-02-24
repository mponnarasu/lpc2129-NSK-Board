/******************************************************************************
 * Copyright 2016 
 * Author: Ponnarasu M.
 * No guarantees, warrantees, or promises, implied or otherwise.
 * May be used for hobby or commercial purposes provided copyright
 * notice remains intact.
 *
 *****************************************************************************/
#ifndef GLOBAL_H
#define GLOBAL_H

/* code is optimized for power of 2 buffer sizes (16, 32, 64, 128, ...) */
#define OUTPUT_BUFFER_SIZE 16         // output buffer size (multiple of 2)
#define INPUT_BUFFER_SIZE 64        // input buffer buffer size (multiple of 2)

extern unsigned char  output_buffer1[OUTPUT_BUFFER_SIZE];
extern unsigned char  output_buffer2[OUTPUT_BUFFER_SIZE];
//extern unsigned short output_buffer_insert_idx, output_buffer_extract_idx;
extern unsigned char output_buffer_status;

//extern unsigned char  input_buffer[INPUT_BUFFER_SIZE];
extern unsigned long  input_buffer[INPUT_BUFFER_SIZE];
extern unsigned short input_buffer_insert_idx, input_buffer_extract_idx;
extern unsigned char input_buffer_status;

#endif
