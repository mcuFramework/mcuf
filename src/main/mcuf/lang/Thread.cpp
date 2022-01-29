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

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/**
 *
 */
Thread::Thread(const Memory& memory) construct Memory(memory){
  ASSERT(this->isAlignment64Bit(), __CLASSPATH__, Error::MEMORY_NOT_ALIGNMENT_64BIT);
  ASSERT(!(this->length() < (getRtxMemorySize() + 128)), __CLASSPATH__, Error::INSUFFICIENT_MEMORY);
  ASSERT(!this->isReadOnly(), __CLASSPATH__, Error::WRITE_TO_READONLY_MEMORY);
  
  memset(this->pointer(), 0x00, getRtxMemorySize());
  this->mThreadID = nullptr;
  return;
}

/**
 *
 */
Thread::Thread(const Memory& memory, const char* name) construct Thread(memory){
  getRtxMemory()->name = name;
  return;
}

/**
 *
 */
Thread::~Thread(void){
  if(this->mThreadID)
    System::error(__CLASSPATH__, Error::NULL_POINTER);
  
  return;
}

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
const char* Thread::getName(void) const{
  return getRtxMemory()->name;
}

/**
 *
 */
Thread::Priority Thread::getPriority(void){
  return static_cast<Priority>(osThreadGetPriority(this->mThreadID));
}

/**
 *
 */
Thread::State Thread::getState(void){
  return static_cast<State>(osThreadGetState(this->mThreadID));
}

/**
 *
 */
bool Thread::start(void){
  return this->start(PRIORITY_NORMAL);
}

/**
 *
 */
bool Thread::start(Priority priority){
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
void Thread::notify(void){
  osThreadFlagsSet(this->mThreadID, 0x00000001U);
}
  
/**
 *
 */
bool Thread::setPriority(Priority priority){
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
  ASSERT(attachment, __CLASSPATH__, Error::NULL_POINTER);
  
  Thread* thread = static_cast<Thread*>(attachment);
  thread->run();
  thread->mThreadID = nullptr;
  osThreadExit();
  return;
}

/* ****************************************************************************************
 * Private Method
 */

/* ****************************************************************************************
 * End of file
 */ 
