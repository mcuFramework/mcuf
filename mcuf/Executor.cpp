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
#include "mcuf\Executor.h"

/* ****************************************************************************************
 * Using
 */  
using mcuf::function::Runnable;
using mcuf::Memory;
using mcuf::Executor;
using mcuf::ArrayQueue;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Executor:: Executor object
 * 
 * @param memory 
 */
Executor::Executor(const Memory& memory) : ArrayQueue<Runnable>(memory){
  return;
}

/**
 * @brief Construct a new Executor:: Executor object
 * 
 * @param size 
 */
Executor::Executor(uint32_t size) : ArrayQueue<Runnable>(size){
  return;
}

/**
 * @brief Destroy the Executor:: Executor object
 * 
 */
Executor::~Executor(void){
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
