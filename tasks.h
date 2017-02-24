/*
 * tasks.h
 *
 *  Created on: Dec 17, 2008
 *
 */

#ifndef TASKS_H_
#define TASKS_H_

#ifndef NULL_PTR
 #define NULL_PTR  ((void *)0)
#endif


extern void Output_dataproc(void);
extern void Lcd_Init(void);
extern void Board_Init(void);
extern void Global_data_init(void);
extern void Input_dataproc(void);
extern void Data_process(void);
//extern void SevenSeg_driver(void);
//extern void Keypad_detection(void);
//extern void UART0Init(void);
//extern void Uart_Driver(void);

#define Task1000 {		\
Input_dataproc,	    \
Data_process,            \
Output_dataproc            \
}

#define Task100 {	    \
NULL_PTR,	        	\
NULL_PTR				\
}

#define Task10 {		\
NULL_PTR		\
}

#define Task200 {		\
NULL_PTR,				\
NULL_PTR				\
}


#define Bg_Task {		\
NULL_PTR,  		\
NULL_PTR				\
}

#define Init_Task {		\
Board_Init,           \
Lcd_Init,           \
Global_data_init		        \
}

#define Term_Task {		\
NULL_PTR,   			\
NULL_PTR				\
}




#endif /* TASKS_H_ */
