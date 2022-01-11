/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  

#include <stdlib.h>

//-----------------------------------------------------------------------------------------
#ifndef MCUF_CMSISRTOS2_DISABLE
#include "cmsis_rtos/rtx_os.h"
#endif
#include "mcuf_macro.h"
#include "mcuf/lang/Math.hpp"
#include "mcuf/lang/System.hpp"
#include "mcuf/Resources.hpp"

/* ****************************************************************************************
 * Namespace
 */  

/* ****************************************************************************************
 * Using
 */  
using mcuf::Resources;
using mcuf::function::Runnable;
using mcuf::lang::Memory;
using mcuf::lang::System;
using mcuf::lang::Thread;


/* ****************************************************************************************
 * Global Operator
 */  

/* ****************************************************************************************
 * Static Variable
 */  

Thread* System::mThread = nullptr;

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/**
 * 
 */
bool System::start(Thread& thread){
#ifndef MCUF_CMSISRTOS2_DISABLE
  System::initThread(thread);
  osKernelStart();
#endif
  return true;
}

/**
 * 
 */
void System::throwSystemError(const char* path, const char* message){
  while(1);
}

/* ****************************************************************************************
 * Public Method <Override>
 */

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

/**
 *
 */
void System::entryPoint(void* attachment){
  Thread::entryPoint(attachment);
}

/**
 *
 */
void System::initThread(Thread& thread){
  if(System::mThread != nullptr)
    return;
  
  osKernelInitialize();

  return;
}
 
/* ****************************************************************************************
 * End of file
 */ 
