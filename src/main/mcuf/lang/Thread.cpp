/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  

#include <string.h>
//-----------------------------------------------------------------------------------------
#ifndef MCUF_CMSISRTOS2_DISABLE
#include "cmsis_rtos/rtx_os.h"
#endif

#include "mcuf_base.h"
#include "mcuf/lang/Math.h"
#include "mcuf/lang/System.h"
#include "mcuf/lang/Thread.h"

/* ****************************************************************************************
 * Macro
 */  
#define getRtxMemory()         (static_cast<osRtxThread_t*>(this->pointer()))
#define getRtxMemorySize()     (mcuf::lang::Math::align64bit(osRtxThreadCbSize))
#define getStackMemory()       (this->pointer(getRtxMemorySize()))
#define getStackMemorySize()   (this->length() - getRtxMemorySize())

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::Memory;
using mcuf::lang::Thread;
using mcuf::lang::ThreadPriority;
using mcuf::lang::ThreadState;

/* ****************************************************************************************
 * Variable <Static>
 */
Thread* Thread::threadNodeHead = nullptr;

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/**
 *
 */
Thread::Thread(const Memory& memory) : Memory(memory){
  if(this->isReadOnly())
    mcuf::lang::System::error(__CLASSPATH__, ErrorCode::WRITE_TO_READONLY_MEMORY);
  
  if(this->length() < (getRtxMemorySize() + 128))
    mcuf::lang::System::error(__CLASSPATH__, ErrorCode::INSUFFICIENT_MEMORY);

  memset(this->pointer(), 0x00, getRtxMemorySize());
  this->mThreadID = nullptr;
  this->mNextNode = nullptr;
  
  Thread::nodeAdd(this);
  return;
}

/**
 *
 */
Thread::Thread(uint32_t stackSize) : Thread(Memory(stackSize)){
  return;
}

/**
 *
 */
Thread::~Thread(void){
  if(this->mThreadID)
    System::error(__CLASSPATH__, ErrorCode::NULL_POINTER);
  
  Thread::nodeRemove(this);
  return;
}

/* ****************************************************************************************
 * Public Method <Static>
 */

/**
 *
 */
Thread* Thread::getThread(uint32_t threadID){
  if(threadID == 0)
    return nullptr;
  
  Thread* next = Thread::threadNodeHead;
  if(next == nullptr){
    return nullptr;
  }
  
  while(true){
    if(reinterpret_cast<uint32_t>(next->mThreadID) == threadID)
      return next;
    
    next = next->mNextNode;
    if(next == nullptr)
      break;
  }
  
  return nullptr;
}

/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

/**
 *
 */
uint32_t Thread::getID(void) const{
  return reinterpret_cast<uint32_t>(this->mThreadID);
}

/**
 *
 */
void Thread::setName(const char* name){
  getRtxMemory()->name = name;
}

/** 
 *
 */
const char* Thread::getName(void) const{
  return getRtxMemory()->name;
}

/**
 *
 */
ThreadPriority Thread::getPriority(void){
  return static_cast<ThreadPriority>(osThreadGetPriority(this->mThreadID));
}

/**
 *
 */
ThreadState Thread::getState(void){
  return static_cast<ThreadState>(osThreadGetState(this->mThreadID));
}

/**
 *
 */
uint32_t Thread::getStackSize(void){
  return osThreadGetStackSize(this->mThreadID);
}

/**
 *
 */
void Thread::notify(void){
  osThreadFlagsSet(this->mThreadID, 0x00000001U);
}

/**
 *
 */
bool Thread::start(void){
  return this->start(ThreadPriority::NORMAL);
}

/**
 *
 */
bool Thread::start(ThreadPriority priority){
  if(this->mThreadID)
    return false;
  
  if(getStackMemorySize() < 128)
    return false;
  
  osThreadAttr_t attr;
  
  attr.stack_mem = getStackMemory();
  attr.stack_size = getStackMemorySize();
  
  attr.cb_mem = getRtxMemory();
  attr.cb_size = getRtxMemorySize();
  
  attr.name = getRtxMemory()->name;
  attr.attr_bits = osThreadDetached;
  attr.priority = static_cast<osPriority_t>(priority);
  attr.reserved = 0;
  
  this->mThreadID = osThreadNew(Thread::entryPoint, this, &attr);
  
  return this->mThreadID;
}

/**
 *
 */
bool Thread::setPriority(ThreadPriority priority){
  if(osThreadSetPriority(this->mThreadID, static_cast<osPriority_t>(priority)) == osOK)
    return true;
  
  else
    return false;
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
 * Private Method <Static>
 */

/**
 *
 */
void Thread::entryPoint(void* attachment){
  ASSERT(attachment, __CLASSPATH__, ErrorCode::NULL_POINTER);
  
  Thread* thread = static_cast<Thread*>(attachment);
  thread->run();
  thread->mThreadID = nullptr;
  osThreadExit();
  return;
}

/**
 *
 */
bool Thread::nodeAdd(Thread* thread){
  if(thread == nullptr)
    return false;
  
  if(Thread::threadNodeHead == nullptr){
    Thread::threadNodeHead = thread;
    return true;
  }
  
  Thread* next = Thread::threadNodeHead;
  
  while(true){
    if(next == thread)
      return false;
    
    if(next->mNextNode == nullptr){
      next->mNextNode = thread;
      break;
    }
    
    next = next->mNextNode;
  }
    
  return true;
}

/**
 *
 */
bool Thread::nodeRemove(Thread* thread){
  if(thread == nullptr)
    return false;
  
  if(Thread::threadNodeHead == nullptr)
    return false;
  
  Thread* next = Thread::threadNodeHead;
  
  while(true){
    if(next == nullptr)
      return false;
    
    if(next->mNextNode == thread){
      next->mNextNode = next->mNextNode->mNextNode;
      break;
    }
    
    next = next->mNextNode;
  }
  
  return true;
}

/* ****************************************************************************************
 * Private Method
 */

/* ****************************************************************************************
 * End of file
 */ 
