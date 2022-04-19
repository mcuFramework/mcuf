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
#include "mcuf/lang/managerment/CoreThread.h"
#include "mcuf/lang/ErrorCode.h"

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::ErrorCode;
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
CoreThread::CoreThread(uint32_t stackSize, uint32_t executeQueue, Thread* userThread) : Thread(stackSize)
  ,mExecutor(executeQueue){
  
  this->mStart = false;
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
  
  if(this->mUserThread != nullptr)
    this->mUserThread->start();
  
  while(this->mStart){
    this->mExecutor.actionAll();
    
    if(this->mExecutor.isEmpty())
      this->wait(100);
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
