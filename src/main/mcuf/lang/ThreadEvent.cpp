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
#include "mcuf/lang/ThreadEvent.h"

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::ThreadEvent;
using mcuf::function::Runnable;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Thread Event:: Thread Event object
 * 
 * @param stackSize 
 * @param runnable 
 */
ThreadEvent::ThreadEvent(Runnable& runnable) : Thread(){
  this->mRunnable = &runnable;
  return;
}

/**
 * @brief Destroy the Thread Event object
 * 
 */
ThreadEvent::~ThreadEvent(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */
 
/* ****************************************************************************************
 * Public Method <Override> - mcuf::lang::Thread
 */

/**
 *
 */
void ThreadEvent::run(void){
  this->mRunnable->run();
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
