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

//-----------------------------------------------------------------------------------------
#include "mcuf/util/Timer.h"

/* ****************************************************************************************
 * Macro
 */  

/* ****************************************************************************************
 * Using
 */  
using mcuf::util::Timer;
using mcuf::util::TimerTask;

/* ****************************************************************************************
 * Static Variable
 */  
mcuf::lang::rtos::InterfaceTimer* Timer::sInterfaceTimer;

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
    if(Timer::sInterfaceTimer->timerFree(task) == false)
      return false;
  }
  
  task.mTimerID = Timer::sInterfaceTimer->timerAlloc(task);

  
  if(task.mTimerID == 0x00000000)
    return false;
  
  return Timer::sInterfaceTimer->timerStart(task, delay, mode);
}

/* ****************************************************************************************
 * End of file
 */ 
