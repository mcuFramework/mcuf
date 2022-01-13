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

/* ****************************************************************************************
 * Namespace
 */  

/* ****************************************************************************************
 * Using
 */  

using mcuf::function::Runnable;
using mcuf::lang::Memory;
using mcuf::lang::System;
using mcuf::lang::Thread;
using mcuf::lang::ThreadEvent;


/* ****************************************************************************************
 * Global Operator
 */  

/* ****************************************************************************************
 * Static Variable
 */  

Thread* System::mCoreThread = nullptr;

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
bool System::start(System::Attachment& attachment){
  if(!System::initCore(attachment))
    return false;

  osKernelInitialize();
  
  if(!System::mCoreThread->start(Thread::PRIORITY_ABOVE_NORMAL)){
    System::mCoreThread = nullptr;
    return false;
  }
    
  osKernelStart();
  
  System::mCoreThread = nullptr;
  return true;
}

/**
 * 
 */
void System::error(Error::Code code){
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
bool System::initCore(System::Attachment& attachment){
  if(System::mCoreThread != nullptr)
    return false;
  
  if(attachment.coreThread == nullptr)
    return false;
  
  if(attachment.coreThreadMemory == nullptr)
    return false;
  
  if(!attachment.coreThreadMemory->isAlignment64Bit())
    return false;
  
  int threadSize = sizeof(ThreadEvent);
  if(threadSize & 0x00000007){
    threadSize &= 0xFFFFFFF8;
    threadSize += 8;
  }
    
  
  Memory coreThreadMemory = attachment.coreThreadMemory->subMemory(0, threadSize);
  Memory coreThreadStackMemory = attachment.coreThreadMemory->subMemory(threadSize);
  
  System::mCoreThread = new(coreThreadMemory) ThreadEvent(coreThreadStackMemory, "CoreThread", *attachment.coreThread);
  
  return true;
}
 
/* ****************************************************************************************
 * End of file
 */ 
