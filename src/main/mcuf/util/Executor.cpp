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
#include "mcuf/util/Executor.hpp"

/* ****************************************************************************************
 * Using
 */  
using mcuf::function::Runnable;
using mcuf::lang::Memory;
using mcuf::util::Executor;
using mcuf::util::BlockingQueue;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
Executor::Executor(Memory& memory) construct BlockingQueue<Runnable>(memory){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */
 
/* ****************************************************************************************
 * Public Method <Override> - mcuf::function::Runnable
 */



/* ****************************************************************************************
 * Public Method
 */

/**
 * 
 */
bool Executor::execute(Runnable* runnable){
  return this->offer(runnable);
}

/**
 * 
 */
void Executor::actionAll(void){
  while(!this->isEmpty()){
    
    Runnable* command = this->poll();
    if(command != nullptr)
      command->run();
  }
}

/**
 * 
 */
bool Executor::actionSingle(void){
  if(this->isEmpty())
    return false;
  
  Runnable* command = this->poll();
  
  if(command != nullptr){
    command->run();
    return true;
  }else{
    return false;
  }
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
 