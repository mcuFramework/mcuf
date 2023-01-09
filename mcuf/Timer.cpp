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
#include "mcuf\Timer.h"

/* ****************************************************************************************
 * Macro
 */  

/* ****************************************************************************************
 * Using
 */  
using mcuf::Timer;
using mcuf::TimerTask;

/* ****************************************************************************************
 * Static Variable
 */  
mcuf::InterfaceTimer* Timer::sInterfaceTimer;

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
 * @brief Set the Interface Timer object
 * 
 * @param imterfaceTimer 
 */
void Timer::setInterfaceTimer(mcuf::InterfaceTimer& interfaceTimer){
  Timer::sInterfaceTimer = &interfaceTimer;
}

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
  
  return Timer::sInterfaceTimer->timerStart(task.mHandlerMemory, delay, mode, task);
}

/* ****************************************************************************************
 * End of file
 */ 
