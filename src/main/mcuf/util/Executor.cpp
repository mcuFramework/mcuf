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
using mcuf::function::Runnable;
using mcuf::lang::Memory;
using mcuf::util::Executor;
using mcuf::util::Fifo;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
Executor::Executor(Memory& memory) construct Fifo(memory, 4){
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
bool Executor::execute(Runnable& runnable){
  uint32_t addr = reinterpret_cast<uint32_t>(&runnable);
  return this->insertHead(&addr);
}

/**
 * 
 */
void Executor::actionAll(void){
  uint32_t addr;
  while(!this->isEmpty()){
    this->popTail(&addr);
    Runnable* command = reinterpret_cast<Runnable*>(addr);
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
  
  uint32_t addr;
  this->popTail(&addr);
  Runnable* command = reinterpret_cast<Runnable*>(addr);
  
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
 