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
#include "mcuf/CoreThread.h"
#include "mcuf/ErrorCode.h"
#include "mcuf/Timer.h"

/* ****************************************************************************************
 * Using
 */  
using mcuf::ErrorCode;
using mcuf::Memory;
using mcuf::Thread;
using mcuf::CoreThread;
using mcuf::Executor;
using mcuf::Timer;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 *
 */
CoreThread::CoreThread(uint32_t executeQueue, uint32_t tickQueue, uint32_t tickBase, Thread* userThread) : 
Thread(1024),
mCoreTick(tickQueue, tickBase),
mExecutor(executeQueue){
  
  this->mStart = false;
  this->mOnWait = false;
  this->mUserThread = userThread;
  return;
}

/**
 * @brief Destroy the Core Thread object
 * 
 */
CoreThread::~CoreThread(void){
  return;
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
  
  if(this->mOnWait)
    this->notify();
  
  return result;
}

/** 
 *
 */
void CoreThread::stop(void){
  this->mStart = false;
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::function::Runnable
 */

/**
 *
 */
void CoreThread::run(void){
  this->mStart = true;
  
  Timer::scheduleAtFixedRate(this->mCoreTick, static_cast<uint32_t>(this->mCoreTick.getTickBase()));
  
  if(this->mUserThread != nullptr)
    this->mUserThread->start();
  
  while(this->mStart){
    this->mExecutor.actionAll();
    
    if(this->mExecutor.isEmpty()){
      this->mOnWait = true;
      this->wait();
      this->mOnWait = false;
    }
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

/* ****************************************************************************************
 * End of file
 */ 
