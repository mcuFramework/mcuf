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

#include "cmsis_rtos/rtx_os.h"

#include "mcuf/lang/Math.hpp"
#include "mcuf/lang/System.hpp"
#include "mcuf/lang/ThreadEvent.hpp"
#include "mcuf/lang/managerment/CoreThread.hpp"
#include "mcuf/util/Stacker.hpp"

/* ****************************************************************************************
 * Namespace
 */  

/* ****************************************************************************************
 * Extern
 */  
extern void* const mcufCoreThreadMemory;
extern const uint32_t mcufCoreThreadMemorySize;

extern void* const mcufCoreStackMemory;
extern const uint32_t mcufCoreStackMemorySize;

extern void* const mcufCoreEcecutorMemory;
extern const uint32_t mcufCoreEcecutorMemorySize;

extern void* const mcufTimerTaskMemory;
extern const uint32_t mcufTimerTaskMemorySize;
extern const uint32_t mcufTimerTick;

/* ****************************************************************************************
 * Using
 */  

using mcuf::function::Runnable;
using mcuf::lang::Math;
using mcuf::lang::Memory;
using mcuf::lang::System;
using mcuf::lang::managerment::CoreThread;
using mcuf::lang::ThreadEvent;
using mcuf::util::Stacker;

/* ****************************************************************************************
 * Global Operator
 */  

/* ****************************************************************************************
 * Static Variable
 */  

CoreThread* System::mCoreThread = nullptr;
void (*System::mErrorHandler)(const void* address, Error::Code code);

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
void System::start(mcuf::lang::Thread* userThread){
  osKernelInitialize();  
  
  if(1){
    ASSERT(mcufCoreThreadMemory, __CLASSPATH__, Error::NULL_POINTER);
    
    Memory stack = Memory(mcufCoreStackMemory, mcufCoreStackMemorySize);
    Memory executor = Memory(mcufCoreEcecutorMemory, mcufCoreEcecutorMemorySize);
    Memory timer = Memory(mcufTimerTaskMemory, mcufTimerTaskMemorySize);
    
    CoreThread::Attachment attachment;
    attachment.stack = &stack;
    attachment.executor = &executor;
    attachment.timer = &timer;
    attachment.timerTick = mcufTimerTick;
    attachment.userThread = userThread;
    
    System::mCoreThread = new(mcufCoreThreadMemory) CoreThread(attachment);
  }
  
  System::mCoreThread->start();
  osKernelStart();
  
  System::mCoreThread = nullptr;
  return;
}

/**
 * 
 */
void System::error(const void* address, Error::Code code){
  if(System::mErrorHandler != nullptr)
    System::mErrorHandler(address, code);
  
  while(1);
}

/**
 *
 */
void System::registorErrorHandler(void (*handler)(const void* address, Error::Code code)){
  System::mErrorHandler = handler;
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
 
/* ****************************************************************************************
 * End of file
 */ 
