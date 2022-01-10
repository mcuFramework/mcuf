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
using mcuf::io::OutputStream;
using mcuf::io::PrintStream;
using mcuf::lang::Memory;
using mcuf::lang::System;
using mcuf::lang::Thread;
using mcuf::lang::managerment::ExecutorManager;
using mcuf::lang::managerment::StackerManager;
using mcuf::lang::managerment::TimerManager;
using mcuf::util::Executor;
using mcuf::util::Timer;

/* ****************************************************************************************
 * Global Operator
 */  

/**
 * 
 */
void* operator new(size_t n){
  return System::allocPointer(n);
}

/**
 * 
 */
void * operator new[](size_t n){
  return System::allocPointer(n);
}

/**
 * 
 */
void operator delete (void* ptr) noexcept{
  System::freePointer(ptr);
}

/**
 * 
 */
void operator delete[] (void* ptr) noexcept{
  System::freePointer(ptr);
}

/**
 * 
 */
void operator delete (void* ptr, size_t size){
  System::freePointer(ptr, size);
}

/**
 * 
 */
void operator delete[] (void* ptr, size_t size){
  System::freePointer(ptr, size);
}

/* ****************************************************************************************
 * Static Variable
 */  

StackerManager System::mStackerManager = StackerManager(Resources::CORE_MEMORY, Resources::CORE_MEMORY_SIZE);

PrintStream* System::mPrintStream = nullptr;
ExecutorManager* System::mExecutorManager = nullptr;
TimerManager* System::mTimerManager = nullptr;
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
Memory System::allocMemory(size_t size){
  void* result = nullptr;
  return Memory::nullMemory();
}

/**
 * 
 */
void* System::allocPointer(size_t size){
  void* result = nullptr;
  return result;
}

/**
 *
 */
bool System::execute(Runnable& runnable){
  if(System::mExecutorManager == nullptr)
    THROW_ERROR("System executor not enable.");
  
  return System::mExecutorManager->execute(runnable);
}

/**
 *
 */
Timer& System::getTimer(void){
  if(System::mTimerManager == nullptr)
    THROW_ERROR("System timer not enable.");
  
  return *System::mTimerManager;
}


/**
 * 
 */
void System::freeMemory(mcuf::lang::Memory& memory){
  
  free(memory.mPointer);
  return;
}

/**
 * 
 */
void System::freePointer(void* pointer){

  return;
}

/**
 * 
 */
void System::freePointer(void* pointer, size_t size){

  return;
}

/**
 * 
 */
void System::info(const char* path, const char* message){
  System::mPrintStream->format("INFO: %s - %s\n", path, message);
  return;
}

/**
 * 
 */
bool System::start(Thread& thread, OutputStream* outputStream){
  System::initPrintStream(outputStream);
  System::initMemoryManager();
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
  System::mPrintStream->format("ERROR: %s - %s\n", path, message);
  while(1);
}

/**
 * 
 */
void System::throwSystemWarning(const char* path, const char* message){
  System::mPrintStream->format("WARNING: %s - %s\n", path, message);
  return;
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
  System::initExecutor();
  System::initTimer();
  Thread::entryPoint(attachment);
}

/**
 *
 */
void System::initMemoryManager(void){

  return;  
}

/**
 *
 */
void System::initPrintStream(OutputStream* outputStream){
  void* handleMemory = System::mStackerManager.allocAlignment32(sizeof(PrintStream));
  System::mPrintStream = new(handleMemory) PrintStream(outputStream);
}

/**
 *
 */
void System::initThread(Thread& thread){
  if(System::mThread != nullptr)
    return;
  
  
#ifndef MCUF_CMSISRTOS2_DISABLE  
  osKernelInitialize();
#endif
  
  Memory stackMemory = System::mStackerManager.allocMemoryAlignment64(Resources::SYSTEM_STACK_SIZE);
  
  if(!thread.start(stackMemory, Thread::PRIORITY_ABOVE_NORMAL, System::entryPoint)){
    THROW_ERROR("System thread start fail.");
  }else{
    System::mThread = &thread;
  }
  return;
}

  
/**
 *
 */
void System::initTimer(void){
  Memory taskMemory = System::mStackerManager.allocMemoryAlignment64(Resources::TIMER_TASK_QUANTITY * sizeof(void*));
  void* handleMemory = System::mStackerManager.allocAlignment32(sizeof(TimerManager));
  
  System::mTimerManager = new(handleMemory) TimerManager(taskMemory);
  
  if(!mTimerManager->start(5))
    THROW_ERROR("System timer start fail.");
  
  return;
}
  
/**
 *
 */
void System::initExecutor(void){
  Memory stackMemory = System::mStackerManager.allocMemoryAlignment64(Resources::EXECUTOR_STACK_SIZE);
  Memory taskMemory = System::mStackerManager.allocMemoryAlignment64(Resources::EXECUTOR_TASK_QUANTITY * sizeof(void*));
  void* handleMemory = System::mStackerManager.allocAlignment32(sizeof(ExecutorManager));
  
  System::mExecutorManager = new(handleMemory) ExecutorManager(taskMemory);
  
  if(!System::mExecutorManager->mThreadEvent.start(stackMemory, Thread::PRIORITY_HIGH))
    THROW_ERROR("System executor start fail.");
  
  return;
}
 
/* ****************************************************************************************
 * End of file
 */ 
