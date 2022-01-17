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
#include "mcuf/util/Stacker.hpp"

/* ****************************************************************************************
 * Namespace
 */  

/* ****************************************************************************************
 * Using
 */  

using mcuf::function::Runnable;
using mcuf::lang::Math;
using mcuf::lang::Memory;
using mcuf::lang::System;
using mcuf::lang::Thread;
using mcuf::lang::ThreadEvent;
using mcuf::lang::managerment::ExecutorThread;
using mcuf::lang::managerment::TimerManager;
using mcuf::util::Stacker;

/* ****************************************************************************************
 * Global Operator
 */  

/* ****************************************************************************************
 * Static Variable
 */  

Thread* System::mCoreThread = nullptr;
ExecutorThread* System::mExecutorThread = nullptr;
TimerManager* System::mTimerManager = nullptr;

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
void System::start(System::Attachment& attachment){
  osKernelInitialize();  
  
  System::initCore(attachment);
  System::initExecutor(attachment.executorMemory, attachment.executorTaskQuantity);
  System::initTimer(attachment.timerMemory, attachment.timerTaskQuantity);
  
  if(!System::mCoreThread->start(Thread::PRIORITY_ABOVE_NORMAL))
    System::error(__PRETTY_FUNCTION__, Error::SYSTEM_ERROR);
    
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
 
/**
 *
 */
void System::initCore(System::Attachment& attachment){
  if(System::mCoreThread != nullptr)
    System::error(__PRETTY_FUNCTION__, Error::NULL_POINTER);
  
  if(attachment.coreThread == nullptr)
    System::error(__PRETTY_FUNCTION__, Error::NULL_POINTER);
  
  if(attachment.coreThreadMemory == nullptr)
    System::error(__PRETTY_FUNCTION__, Error::NULL_POINTER);
  
  if(!attachment.coreThreadMemory->isAlignment64Bit())
    System::error(__PRETTY_FUNCTION__, Error::MEMORY_NOT_ALIGNMENT_64BIT);
  
  int threadSize = Math::align64bit(sizeof(ThreadEvent));
    
  
  Memory coreThreadMemory = attachment.coreThreadMemory->subMemory(0, threadSize);
  Memory coreThreadStackMemory = attachment.coreThreadMemory->subMemory(threadSize);
  
  System::mCoreThread = new(coreThreadMemory) ThreadEvent(coreThreadStackMemory, "CoreThread", *attachment.coreThread);
  
  return;
}

/**
 *
 */
void System::initExecutor(Memory* memory, uint32_t quantity){
  if(memory == nullptr)
    System::error(__PRETTY_FUNCTION__, Error::NULL_POINTER);
  
  if(memory->isReadOnly())
    System::error(__PRETTY_FUNCTION__, Error::WRITE_TO_READONLY_MEMORY);
  
  if(!memory->isAlignment64Bit())
    System::error(__PRETTY_FUNCTION__, Error::MEMORY_NOT_ALIGNMENT_64BIT);
  
  if(quantity == 0)
    System::error(__PRETTY_FUNCTION__, Error::ILLEGAL_ARGUMENT);
  
  
  
  Stacker stacker = Stacker(*memory);
  
  void* classMemory = stacker.allocMemoryAlignment64(sizeof(ExecutorThread));
  
  if(classMemory == nullptr)
    System::error(__PRETTY_FUNCTION__, Error::ILLEGAL_ARGUMENT);
  
  Memory taskMemroy = stacker.allocMemoryAlignment64(sizeof(void*) * quantity);
  if(taskMemroy.isEmpty())
    System::error(__PRETTY_FUNCTION__, Error::OUT_OF_MEMORY);
    
  Memory stackMemory = stacker.allocMemory(stacker.getFree());
  if(stackMemory.isEmpty())
    System::error(__PRETTY_FUNCTION__, Error::OUT_OF_MEMORY);
  
  if(stackMemory.length() < 128)
    System::error(__PRETTY_FUNCTION__, Error::OUT_OF_MEMORY);
  
  System::mExecutorThread = new(classMemory) ExecutorThread(stackMemory, taskMemroy);
  
  return;
}

/**
 *
 */
void System::initTimer(Memory* memory, uint32_t quantity){
  if(memory == nullptr)
    System::error(__PRETTY_FUNCTION__, Error::NULL_POINTER);
  
  if(memory->isReadOnly())
    System::error(__PRETTY_FUNCTION__, Error::WRITE_TO_READONLY_MEMORY);
  
  if(!memory->isAlignment64Bit())
    System::error(__PRETTY_FUNCTION__, Error::MEMORY_NOT_ALIGNMENT_64BIT);
  
  if(quantity == 0)
    System::error(__PRETTY_FUNCTION__, Error::ILLEGAL_ARGUMENT);
  
  Stacker stacker = Stacker(*memory);
  void* classMemory = stacker.allocMemoryAlignment64(sizeof(TimerManager));
  
  if(classMemory == nullptr)
    System::error(__PRETTY_FUNCTION__, Error::ILLEGAL_ARGUMENT);
  
  Memory taskMemroy = stacker.allocMemoryAlignment64(sizeof(void*) * quantity);
  if(taskMemroy.isEmpty())
    System::error(__PRETTY_FUNCTION__, Error::OUT_OF_MEMORY);  
}

/* ****************************************************************************************
 * End of file
 */ 
