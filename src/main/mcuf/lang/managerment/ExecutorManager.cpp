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
#include "mcuf/lang/managerment/ExecutorManager.hpp"

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::Memory;
using mcuf::lang::Thread;
using mcuf::lang::managerment::ExecutorManager;
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
ExecutorManager::ExecutorManager(Memory& memory) construct Executor(memory), 
  mThreadEvent(*this, "ExecutorManager"){
  
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
bool ExecutorManager::execute(Runnable& runnable){
  bool result = Executor::execute(&runnable);
  this->mThreadEvent.notify();
  return result;
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::function::Runnable
 */

/**
 *
 */
void ExecutorManager::run(void){
  this->mStart = true;
  
  while(this->mStart){
    this->actionAll();
    
    if(this->isEmpty())
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
