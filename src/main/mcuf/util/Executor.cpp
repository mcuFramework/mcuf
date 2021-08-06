/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "Executor.hpp"

/* ****************************************************************************************
 * Using
 */  
using mcuf::util::Executor;
using mcuf::util::Queue;
using mcuf::function::Runnable;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
Executor::Executor(Queue<Runnable*>* queue){
  this->queue = queue;
  this->queue->clear();
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

/* ****************************************************************************************
 * Public Method
 */

/**
 * 
 */
void Executor::execute(mcuf::function::Runnable* command){
  this->queue->offer(command);
}

/**
 * 
 */
void Executor::action(void){
  if(!this->queue->isEmpty())
    this->queue->poll()->run();
}

/**
 * 
 */
void Executor::run(void){
  while(!this->queue->isEmpty())
    this->queue->poll()->run();
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
 