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
#include "mcuf.h"

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
TimerScheduler::TimerScheduler(Memory& memory) construct BlockPool(memory, sizeof(void*)){
  return;
}

/**
 *
 */
TimerScheduler::~TimerScheduler(){
  this->cancel();
  return;
}

/**
 *
 */
TimerScheduler::ConsumerTick::ConsumerTick(TimerScheduler* base){
  this->base = base;
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

/**
 * cancel
 */
void TimerScheduler::cancel(void){
  this->forEach(this->consumerClear);
  return;
}


/**
 * purge
 */
uint32_t TimerScheduler::purge(void){
  this->consumerPurge.clear();
  this->forEach(this->consumerPurge);
  return this->consumerPurge.get();
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
  if(TimerTask::Viewer::isTimerTaskRunning(task))
    return false;
    
  void* pTask = &task;

  void* result = this->add(&pTask);
  if(result == 0x00000000)
    return false;
    
  TimerTask::Viewer::setTimerTaskDelayPeriod(task, delay, period);
  return true;
}

/* ****************************************************************************************
 * Public Method
 */

/**
 * 
 */
void TimerScheduler::tick(uint32_t milliSecont){
  this->consumerTick.setTickMilliSecond(milliSecont);
  this->forEach(this->consumerTick);
}

/* ****************************************************************************************
 * Public Method - Class ConsumerClear
 */

/**
 * 
 */
void TimerScheduler::ConsumerClear::accept(Memory& t){
  TimerTask* timerTask = (TimerTask*)(*((uint32_t*)t.pointer()));
  TimerTask::Viewer::setTimerTaskDelayPeriod(*timerTask, 0, 0);
}


/* ****************************************************************************************
 * Public Method - Class ConsumerPurge
 */

/**
 * 
 */
void TimerScheduler::ConsumerPurge::accept(Memory& t){
  TimerTask* timerTask = (TimerTask*)(*((uint32_t*)t.pointer()));

  if(!TimerTask::Viewer::isTimerTaskRunning(*timerTask)){
    this->purge++;
    this->base->remove(t.pointer());
  }
}


/**
 * 
 */
void TimerScheduler::ConsumerPurge::clear(void){
  this->purge = 0;
}


/**
 * 
 */
uint32_t TimerScheduler::ConsumerPurge::get(void){
  return this->purge;
}


/* ****************************************************************************************
 * Public Method - Class ConsumerTick
 */

/**
 * 
 */
void TimerScheduler::ConsumerTick::accept(Memory& t){
  TimerTask* timerTask = (TimerTask*)(*((uint32_t*)t.pointer()));
      
  if(TimerTask::Viewer::subTimerTaskDelay(*timerTask, this->tickMilliSecond)){
    timerTask->run();
    uint32_t period = TimerTask::Viewer::getTimerTaskPeriod(*timerTask);

    if(period)
      TimerTask::Viewer::setTimerTaskDelay(*timerTask, period);
    else
      this->base->remove(t.pointer());
  }
}


/**
 * 
 */
uint32_t TimerScheduler::ConsumerTick::getTickMilliSecond(void){
  return this->tickMilliSecond;
}


/**
 * 
 */
void TimerScheduler::ConsumerTick::setTickMilliSecond(uint32_t milliSecond){
  this->tickMilliSecond = milliSecond;
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
