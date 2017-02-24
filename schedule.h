/******************************************************************************
 * Copyright 2016 
 * Author: Ponnarasu M.
 * No guarantees, warrantees, or promises, implied or otherwise.
 * May be used for hobby or commercial purposes provided copyright
 * notice remains intact.
 *
 *****************************************************************************/
#ifndef _SCHEDULE_H_
#define _SCHEDULE_H_

/* defines dependent on compiler  */
#define Sched_IntDis()
#define Sched_IntEn()


/* Schedule counter */
extern long volatile Sched_Counter;

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
void Start_Schedule(void);

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
void Stop_Schedule(void);

#endif /* _SCHEDULE_H_ */
