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
#include "cmsis_rtos/rtx_os.h"
#include "mcuf_base.h"
#include "mcuf_macro.h"
#include "mcuf/lang/System.hpp"
#include "mcuf/lang/Thread.hpp"

/* ****************************************************************************************
 * Macro
 */  
#define GET_MEMORY() ((osRtxThread_t*)(&this->mThreadMemory[0]))

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
Thread::Thread(void){
  memset(this->mThreadMemory, 0x00, sizeof(this->mThreadMemory));
  this->mThreadID = nullptr;
}

/**
 *
 */
Thread::Thread(const char* name){
  memset(this->mThreadMemory, 0x00, sizeof(this->mThreadMemory));
  this->mThreadID = nullptr;
  GET_MEMORY()->name = name;
}

/**
 *
 */
Thread::~Thread(void){
  if(this->mThreadID){
    THROW_ERROR("System try to destruct runnable thread.");
  }
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
const char* Thread::getName(void){
  return GET_MEMORY()->name;
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
bool Thread::start(uint32_t stackSize){
  return this->start(stackSize, PRIORITY_NORMAL);
}

/**
 *
 */
bool Thread::start(uint32_t stackSize, Priority priority){
  Memory memory = System::allocMemory(stackSize);
  return this->start(memory, priority, Thread::entryPoint);
}

/**
 *
 */
bool Thread::start(Memory& memory){
  return this->start(memory, PRIORITY_NORMAL, Thread::entryPoint);
}

/**
 *
 */
bool Thread::start(Memory& memory, Priority priority){
  return this->start(memory, priority, Thread::entryPoint);
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
  if(attachment == nullptr){
    THROW_WARNING("Thread entryPoint attachment is nullptr.");
    return;
  }
  
  Thread* thread = static_cast<Thread*>(attachment);
  thread->run();
  thread->mThreadID = nullptr;
  osThreadExit();
  return;
}

/* ****************************************************************************************
 * Private Method
 */

/** 
 *
 */
bool Thread::start(mcuf::lang::Memory& memory, Priority priority, void(*entryPoint)(void* attachment)){
  if(this->mThreadID)
    return false;
  
  if(memory.length() < 128)
    return false;
  
  osThreadAttr_t attr;
  attr.stack_mem = memory.pointer();
  attr.stack_size = memory.length();
  
  if(attr.stack_mem == nullptr)
    return false;
  
  attr.cb_mem = &this->mThreadMemory[0];
  attr.cb_size = sizeof(this->mThreadMemory);
  attr.name = GET_MEMORY()->name;
  attr.attr_bits = osThreadDetached;
  attr.priority = static_cast<osPriority_t>(priority);
  attr.reserved = 0;
  
  this->mThreadID = osThreadNew(entryPoint, this, &attr);
  
  return this->mThreadID;
}

/* ****************************************************************************************
 * End of file
 */ 
