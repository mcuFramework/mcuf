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
#include "mcuf/lang/managerment/CoreThread.hpp"

/* ****************************************************************************************
 * Using
 */  
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
CoreThread::CoreThread(Memory& memory, Memory& queueMemory) construct Thread(memory){
  
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
bool CoreThread::execute(Runnable& runnable){
  bool result = this->mExecutor->execute(&runnable);
  this->notify();
  return result;
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::function::Runnable
 */

/**
 *
 */
void CoreThread::run(void){
  this->mStart = true;
  
  while(this->mStart){
    this->mExecutor->actionAll();
    
    if(this->mExecutor->isEmpty())
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
