/******************************************************************************
 * Copyright 2016 
 * Author: Ponnarasu M.
 * No guarantees, warrantees, or promises, implied or otherwise.
 * May be used for hobby or commercial purposes provided copyright
 * notice remains intact.
 *
 *****************************************************************************/

#include "tasks.h"
#include "schedule.h"
#include <LPC21XX.H>                           // LPC21XX Peripheral Registers

#define  Sched_Init_size        (sizeof(Sched_Init)/sizeof(Sched_funcPtr))
#define  Sched_Bg_size          (sizeof(Sched_Bg)/sizeof(Sched_funcPtr))
#define  Sched_Task10ms_size    (sizeof(Sched_Task10ms)/sizeof(Sched_funcPtr))
#define  Sched_Task100ms_size   (sizeof(Sched_Task100ms)/sizeof(Sched_funcPtr))
#define  Sched_Task1000ms_size  (sizeof(Sched_Task1000ms)/sizeof(Sched_funcPtr))
#define  Sched_Term_size        (sizeof(Sched_Term)/sizeof(Sched_funcPtr))
#define SCHEDULE_MAX 1000

typedef void (*Sched_funcPtr)(void);
typedef const Sched_funcPtr Sched_FuncPtrTab[];
typedef const Sched_FuncPtrTab* Sched_TablePtr;

typedef const struct
{
	const Sched_TablePtr task_ptr;
	unsigned long period;
	unsigned long size;
} TimeTable_Type;

const Sched_funcPtr Sched_Init[] = Init_Task;
const Sched_funcPtr Sched_Bg[] = Bg_Task;
const Sched_funcPtr Sched_Task10ms[] = Task10;
const Sched_funcPtr Sched_Task100ms[] = Task100;
const Sched_funcPtr Sched_Task1000ms[] = Task1000;
const Sched_funcPtr Sched_Term[] = Term_Task;

TimeTable_Type TimeTable[] = { 
 { &Sched_Task10ms, 10UL,Sched_Task10ms_size },
 { &Sched_Task100ms, 100UL, Sched_Task100ms_size},
 { &Sched_Task1000ms, 1000UL, Sched_Task1000ms_size}
  };

unsigned long TimeTable_size = sizeof(TimeTable) / sizeof(TimeTable_Type);

long volatile Sched_Counter;
static long volatile Sched_Counter_old;
static unsigned char Sched_ShtDwn_req;

/* Timer Counter 0 Interrupt executes each 1ms @ 60 MHz CPU Clock */
__irq void tc0 (void) {
  Sched_Counter++;
  T0IR = 1;                                    // Clear interrupt flag
  VICVectAddr = 0;                             // Acknowledge Interrupt
}

/* Setup the Timer Counter 0 Interrupt */
/* Pclk = 60Mhz, PR = 3 (i.e. div by 4) */
void init_timer (void) {
  T0PR = 3;
  T0MR0 = 14999;                               // 1mSec = 15000-1 counts
  T0MCR = 3;                                   // Interrupt and Reset on MR0
  T0TCR = 1;                                   // Timer0 Enable
  VICVectAddr0 = (unsigned long)tc0;           // set interrupt vector in 0
  VICVectCntl0 = 0x20 | 4;                     // use it for Timer 0 Interrupt
  VICIntEnable = 0x00000010;                   // Enable Timer0 Interrupt
}

/******************************************************************************
 *
 * Function Name: void Schedule(void)
 *
 * Description:  
 *    The function schedules functions based on timetable configured 
 *
 * Parameters: 
 *    void
 *
 * Returns:
 *    void
 *
 *****************************************************************************/
void Schedule(void)
	{
		unsigned long i, j;
		Sched_funcPtr p;
		Sched_TablePtr q;

		while (!Sched_ShtDwn_req)
		{
			if (Sched_Counter != Sched_Counter_old)
			{
				for (i = 0; (i < TimeTable_size); i++)

				{
					if ((Sched_Counter % TimeTable[i].period) == 0)
					{
						q = TimeTable[i].task_ptr;
						for (j = 0; j < TimeTable[i].size; j++)
						{

							p = *(*q)[j];

							if (NULL_PTR != p) p();

						}
					}
				}
				if (Sched_Counter > SCHEDULE_MAX)
				{
					Sched_Counter = 0;
				}
				Sched_Counter_old = Sched_Counter;
			}
			for (j = 0; j < Sched_Bg_size; j++)
			{
				if (Sched_Counter != Sched_Counter_old)
				{
					j = Sched_Bg_size;
				}
				else
				{
					p = Sched_Bg[j];
					if (NULL_PTR != p) p();
				}

			}

		}
	}


/******************************************************************************
 *
 * Function Name: void Start_Schedule(void)
 *
 * Description:  
 *    The function starts the scheduler  
 *
 * Parameters: 
 *    void
 *
 * Returns:
 *    void
 *
 *****************************************************************************/

void Start_Schedule(void)
	{

		Sched_funcPtr p;

		unsigned long i;

		Sched_Counter = 0;
		Sched_ShtDwn_req = 0;
		Sched_IntDis();
		for (i = 0; i < Sched_Init_size; i++)
		{
			p = (*Sched_Init[i]);
			if (p != NULL_PTR) p();

		}
		Sched_IntEn();
		init_timer();
		Schedule();
	}

/******************************************************************************
 *
 * Function Name: void Stop_Schedule(void)
 *
 * Description:  
 *    The function stops the scheduler  
 *
 * Parameters: 
 *    void
 *
 * Returns:
 *    void
 *
 *****************************************************************************/
void Stop_Schedule(void)
	{
		Sched_funcPtr p;
		unsigned long i;

		Sched_Counter = 0;

		for (i = 0; i < Sched_Term_size; i++)
		{
			p = (*Sched_Term[i]);
			if (p != NULL_PTR) p();

		}

		Sched_ShtDwn_req = 0xFF;
	}

	
