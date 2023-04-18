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
#include "./../sys/package-info.h"

//-----------------------------------------------------------------------------------------
#include "./package-info.h"

/* ****************************************************************************************
 * Using
 */  
using sys::ErrorCode;
using mcuf::Memory;
using sys::Thread;
using mcuf::CoreThread;
using sys::Executor;
using sys::Timer;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 *
 */
CoreThread::CoreThread(uint32_t executeQueue, Thread* userThread) : 
Thread(1024), 
mExecutor(executeQueue){
  
  mcuf::ArrayQueuePrototype ss2 = mcuf::ArrayQueuePrototype(16);
  
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
 * Public Method <Override> - func::Runnable
 */

/**
 *
 */
void CoreThread::run(void){
  
  this->mStart = true;
  
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
