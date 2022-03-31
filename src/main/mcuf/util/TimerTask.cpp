/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#ifndef MCUF_CMSISRTOS2_DISABLE
#include "cmsis_rtos/rtx_os.h"
#endif

//-----------------------------------------------------------------------------------------
#include "mcuf/util/TimerTask.h"

/* ****************************************************************************************
 * Using
 */  
using mcuf::util::TimerTask;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Timer Task object
 * 
 */
TimerTask::TimerTask(void){
  this->mTimerID = nullptr;
}
    
/**
 * @brief Destroy the Timer Task object
 * 
 */
TimerTask::~TimerTask(void){
  if(this->mTimerID == nullptr)
    return;
  
  if(this->isRunning())
    osTimerStop(this->mTimerID);
  
  osTimerDelete(this->mTimerID);
  this->mTimerID = nullptr;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

/**
 * Cancels this timer task. If the task has been scheduled for one-time execution and has 
 * not yet run, or has not yet been scheduled, it will never run. If the task has been 
 * scheduled for repeated execution, it will never run again. (If the task is running 
 * when this call occurs, the task will run to completion, but will never run again.)
 *
 * Note that calling this method from within the run method of a repeating timer task
 *  absolutely guarantees that the timer task will not run again.
 *
 * This method may be called repeatedly; the second and subsequent calls have no effect.
 *
 * @return true if this task is scheduled for one-time execution and has not yet run, 
 *         or this task is scheduled for repeated execution. Returns false if the task 
 *         was scheduled for one-time execution and has already run, or if the task was 
 *         never scheduled, or if the task was already cancelled. (Loosely speaking, this 
 *         method returns true if it prevents one or more scheduled executions from taking 
 *         place.)
 */
bool TimerTask::cancel(void){
  if(!this->isRunning())
    return false;
  
  return (osTimerStop(this->mTimerID) == osOK);
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool TimerTask::isRunning(void){
  if(this->mTimerID == nullptr)
    return false;
  
  return osTimerIsRunning(this->mTimerID);
}

/* ****************************************************************************************
 * Protected Method <Static>
 */
 
/* ****************************************************************************************
 * Protected Method <Override>
 */ 

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */
 
/* ****************************************************************************************
 * End of file
 */ 
