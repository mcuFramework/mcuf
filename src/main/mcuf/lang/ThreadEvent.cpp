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
 * Construct.
 */
ThreadEvent::ThreadEvent(const Memory& memory, Runnable& runnable) construct Thread(memory){
  this->mRunnable = &runnable;
}

/**
 * Construct.
 */
ThreadEvent::ThreadEvent(uint32_t stackSize, Runnable& runnable) construct Thread(stackSize){
  this->mRunnable = &runnable;
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
