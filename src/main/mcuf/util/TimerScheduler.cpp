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
#include "mcuf/util/TimerScheduler.h"

/* ****************************************************************************************
 * Macro
 */  
#define TIMER_SCHEDULER_EVENT_TICK   ((uint32_t)0x00000000)
#define TIMER_SCHEDULER_EVENT_PURGE  ((uint32_t)0x00000001)
#define TIMER_SCHEDULER_EVENT_CANCEL ((uint32_t)0x00000002)

/* ****************************************************************************************
 * Using
 */  
using mcuf::util::TimerScheduler;
using mcuf::util::TimerTask;
using mcuf::util::BlockPool;
using mcuf::lang::Memory;


/* ****************************************************************************************
 * Construct Method
 */

/**
 *
 */
TimerScheduler::TimerScheduler(const Memory& memory) construct BlockPool(memory, sizeof(void*)){
  return;
}

/**
 *
 */
TimerScheduler::~TimerScheduler(){
  this->cancel();
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */
 
/* ****************************************************************************************
 * Public Method <Override> - mcuf::function::BiConsumer<mcuf::lang::Memory*, void*>
 */

/**
 *
 */
void TimerScheduler::accept(mcuf::lang::Memory* value, void* attachment){
  TimerTask* timerTask = (TimerTask*)(*((uint32_t*)value->pointer()));
  
  switch(reinterpret_cast<uint32_t>(attachment)){
    case TIMER_SCHEDULER_EVENT_TICK:
      if(timerTask->subDelay(this->mTickMilliSecond)){
        timerTask->run();
        
        if(timerTask->mPeriod)
          timerTask->mDelay = timerTask->mPeriod;
        else
          this->remove(value->pointer());
      }
      
      break;
    
    case TIMER_SCHEDULER_EVENT_CANCEL:
      timerTask->mDelay = 0;
      timerTask->mPeriod = 0;
    
      break;
    
    case TIMER_SCHEDULER_EVENT_PURGE:
      if(!timerTask->isRunning())
        this->remove(value->pointer());
      
      break;
      
    default:
      break;
  }
}

/* ****************************************************************************************
 * Public Method
 */

/**
 * cancel
 */
void TimerScheduler::cancel(void){
  this->forEach(reinterpret_cast<void*>(TIMER_SCHEDULER_EVENT_CANCEL), *this);
  this->clear();
  return;
}

/**
 *
 */
void TimerScheduler::purge(void){
  this->forEach(reinterpret_cast<void*>(TIMER_SCHEDULER_EVENT_PURGE), *this);
}

/**
 * schedule
 */
bool TimerScheduler::schedule(TimerTask& task, uint32_t delay){
    return this->scheduleAtFixedRate(task, delay, 0);
}


/**
 * scheduleAtFixedRate
 */
bool TimerScheduler::scheduleAtFixedRate(TimerTask& task, uint32_t delay, uint32_t period){
  if(task.isRunning())
    return false;
    
  this->purge();
  
  void* pTask = &task;

  void* result = this->add(&pTask);
  if(result == 0x00000000)
    return false;
    
  task.mDelay = delay;
  task.mPeriod = period;
  return true;
}

/**
 * 
 */
void TimerScheduler::tick(uint32_t milliSecont){
  if(this->mTickMilliSecond != 0)
    return;
  
  this->mTickMilliSecond = milliSecont;
  this->forEach(reinterpret_cast<void*>(TIMER_SCHEDULER_EVENT_TICK), *this);
  this->mTickMilliSecond = 0;
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
