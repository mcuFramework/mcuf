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
#include "mcuf/lang/managerment/ExecutorThread.hpp"

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::Memory;
using mcuf::lang::Thread;
using mcuf::lang::managerment::ExecutorThread;
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
ExecutorThread::ExecutorThread(Memory& memory, Memory& queueMemory) construct Thread(memory), 
  mExecutor(queueMemory){
  
  this->mStart = false;
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
bool ExecutorThread::execute(Runnable& runnable){
  bool result = this->mExecutor.execute(&runnable);
  this->notify();
  return result;
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::function::Runnable
 */

/**
 *
 */
void ExecutorThread::run(void){
  this->mStart = true;
  
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
 
/* ****************************************************************************************
 * End of file
 */ 
