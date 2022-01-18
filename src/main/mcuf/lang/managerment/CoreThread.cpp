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
#include "cmsis_rtos/rtx_os.h"
#include "mcuf/lang/managerment/CoreThread.hpp"
#include "mcuf/lang/Error.hpp"

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::Error;
using mcuf::lang::Memory;
using mcuf::lang::Thread;
using mcuf::lang::managerment::CoreThread;
using mcuf::util::Executor;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 *
 */
CoreThread::CoreThread(CoreThread::Attachment& attachment) construct Thread(*attachment.stack)
  ,mExecutor(*attachment.executor), mTimerScheduler(*attachment.timer){
  
  this->mTimerID = nullptr;
  this->mStart = false;
  this->mTimerTick = attachment.timerTick;
  this->mUserThread = attachment.userThread;
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
 *
 */
bool CoreThread::execute(Runnable& runnable){
  bool result = this->mExecutor.execute(&runnable);
  this->notify();
  return result;
}

/** 
 *
 */
void CoreThread::stop(void){
  if(this->mTimerID != nullptr){
    osTimerStop(this->mTimerID);
    osTimerDelete(this->mTimerID);
    this->mTimerID = nullptr;
    this->mTimerTick = 0;
  }
  
  if(this->mStart){
    this->mStart = false;
  }
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::function::Runnable
 */

/**
 *
 */
void CoreThread::run(void){
  this->mStart = true;
  
  if(true){
    osTimerAttr_t attr;
    attr.attr_bits = 0;
    attr.name = "TimerManager";
    attr.cb_mem = this->mTimerMemory;
    attr.cb_size = sizeof(this->mTimerMemory);
    this->mTimerID = osTimerNew(CoreThread::entryPoint, osTimerPeriodic, this, &attr);
    osTimerStart(this->mTimerID, this->mTimerTick);
  }
  
  
  if(this->mUserThread != nullptr)
    this->mUserThread->start();
  
  while(this->mStart){
    this->mExecutor.actionAll();
    
    if(this->mExecutor.isEmpty())
      this->wait();
  }
}

/* ****************************************************************************************
 * Public Method
 */

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

void CoreThread::entryPoint(void* attachment){
  CoreThread* coreThread = static_cast<CoreThread*>(attachment);
  coreThread->mTimerScheduler.tick(coreThread->mTimerTick);
}

/* ****************************************************************************************
 * End of file
 */ 
