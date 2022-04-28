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
#include "mcuf/util/Timer.h"

/* ****************************************************************************************
 * Macro
 */  
#define getTimerHandle(TASK)       (*reinterpret_cast<osRtxTimer_t*>(&TASK.mHandler[0]))

/* ****************************************************************************************
 * Using
 */  
using mcuf::util::Timer;
using mcuf::util::TimerTask;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Timer:: Timer object
 * 
 */
Timer::Timer(void){
  return;
}

/**
 * @brief Destroy the Timer:: Timer object
 * 
 */
Timer::~Timer(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method
 */

/**
 * schedule
 */
bool Timer::schedule(TimerTask& task, uint32_t delay){
  return Timer::schedule(task, delay, true);
}


/**
 * scheduleAtFixedRate
 */
bool Timer::scheduleAtFixedRate(TimerTask& task, uint32_t delay){
  return Timer::schedule(task, delay, false);
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

/**
 *
 */
void Timer::entryPoint(void* attachment){
  TimerTask* task = reinterpret_cast<TimerTask*>(attachment);
  if(task == nullptr)
    return;
  
  task->run();
}

/**
 *
 */
bool Timer::schedule(TimerTask& task, uint32_t delay, bool mode){
  if(task.isRunning())
    return false;
  
  if(task.mTimerID){
    if(osTimerDelete(task.mTimerID) != osOK)
      return false;
  }
  
  osTimerAttr_t attr;
  attr.name = "";
  attr.attr_bits = 0;
  attr.cb_mem = &getTimerHandle(task);
  attr.cb_size = sizeof(task.mHandler);
  
  if(mode)
    task.mTimerID = osTimerNew(Timer::entryPoint, osTimerOnce, &task, &attr);
  else
    task.mTimerID = osTimerNew(Timer::entryPoint, osTimerPeriodic, &task, &attr);
  
  if(task.mTimerID == nullptr)
    return false;
  
  return (osTimerStart(task.mTimerID, delay) == osOK);
}

/* ****************************************************************************************
 * End of file
 */ 
