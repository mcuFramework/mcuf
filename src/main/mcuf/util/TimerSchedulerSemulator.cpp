/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "TimerSchedulerSemulator.hpp"


/* ****************************************************************************************
 * Using
 */  
using mcuf::util::TimerSchedulerSemulator;
using mcuf::util::TimerTask;
using mcuf::lang::Memory;

/* ****************************************************************************************
 * Construct Method
 */

TimerSchedulerSemulator::TimerSchedulerSemulator(mcuf::util::Pool* pool){
  this->pool = pool;
  return;
}

TimerSchedulerSemulator::~TimerSchedulerSemulator(){
  this->cancel();
  return;
}

TimerSchedulerSemulator::ConsumerTick::ConsumerTick(TimerSchedulerSemulator* base){
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

void TimerSchedulerSemulator::cancel(void){
  this->pool->forEach(this->consumerClear);
  return;
}


/**
 * purge
 */

uint32_t TimerSchedulerSemulator::purge(void){
  this->consumerPurge.clear();
  this->pool->forEach(this->consumerPurge);
  return this->consumerPurge.get();
}


/**
 * schedule
 */

bool TimerSchedulerSemulator::schedule(TimerTask& task, uint32_t delay){
    return this->scheduleAtFixedRate(task, delay, 0);
  }


/**
 * scheduleAtFixedRate
 */

bool TimerSchedulerSemulator::scheduleAtFixedRate(TimerTask& task, uint32_t delay, uint32_t period){
  if(TimerTask::Viewer::isTimerTaskRunning(task))
    return false;
    
  void* pTask = &task;

  void* result = this->pool->add(&pTask);
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

void TimerSchedulerSemulator::tick(uint32_t milliSecont){
  this->consumerTick.setTickMilliSecond(milliSecont);
  this->pool->forEach(this->consumerTick);
}

/* ****************************************************************************************
 * Public Method - Class ConsumerClear
 */

/**
 * 
 */

void TimerSchedulerSemulator::ConsumerClear::accept(Memory& t){
  TimerTask* timerTask = (TimerTask*)(*((uint32_t*)t.pointer()));
  TimerTask::Viewer::setTimerTaskDelayPeriod(*timerTask, 0, 0);
}


/* ****************************************************************************************
 * Public Method - Class ConsumerPurge
 */

/**
 * 
 */

void TimerSchedulerSemulator::ConsumerPurge::accept(Memory& t){
  TimerTask* timerTask = (TimerTask*)(*((uint32_t*)t.pointer()));

  if(!TimerTask::Viewer::isTimerTaskRunning(*timerTask)){
    this->purge++;
    this->base->pool->remove(t.pointer());
  }
}


/**
 * 
 */

void TimerSchedulerSemulator::ConsumerPurge::clear(void){
  this->purge = 0;
}


/**
 * 
 */

uint32_t TimerSchedulerSemulator::ConsumerPurge::get(void){
  return this->purge;
}


/* ****************************************************************************************
 * Public Method - Class ConsumerTick
 */

/**
 * 
 */

void TimerSchedulerSemulator::ConsumerTick::accept(Memory& t){
  TimerTask* timerTask = (TimerTask*)(*((uint32_t*)t.pointer()));
      
  if(TimerTask::Viewer::subTimerTaskDelay(*timerTask, this->tickMilliSecond)){
    timerTask->run();
    uint32_t period = TimerTask::Viewer::getTimerTaskPeriod(*timerTask);

    if(period)
      TimerTask::Viewer::setTimerTaskDelay(*timerTask, period);
    else
      this->base->pool->remove(t.pointer());
  }
}


/**
 * 
 */

uint32_t TimerSchedulerSemulator::ConsumerTick::getTickMilliSecond(void){
  return this->tickMilliSecond;
}


/**
 * 
 */

void TimerSchedulerSemulator::ConsumerTick::setTickMilliSecond(uint32_t milliSecond){
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
