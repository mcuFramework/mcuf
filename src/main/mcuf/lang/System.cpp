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
#include "mcuf.h"

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
using mcuf::lang::managerment::MemoryManager;
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
PrintStream System::out = PrintStream(nullptr);

StackerManager System::mStackerManager = StackerManager(Resources::CORE_MEMORY, Resources::CORE_MEMORY_SIZE);
MemoryManager* System::mMemoryManager = nullptr;
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

  if(System::mMemoryManager == nullptr){
    THROW_WARNING("System MemoryManagerment is empty.");

    result = malloc(size);

    ASSERT_THROW_WARNING(result, "System heap memory is empty.");
    
    return Memory(result, size);
  }
  
  return System::mMemoryManager->allocMemory(size);
}

/**
 * 
 */
void* System::allocPointer(size_t size){
  void* result = nullptr;

  if(System::mMemoryManager == nullptr){
    THROW_WARNING("System MemoryManagerment is empty.");

    result = malloc(size);

    ASSERT_THROW_WARNING(result, "System heap memory is empty.");
    
    return result;
  }
    

  result = System::mMemoryManager->alloc(size);

  if(result != nullptr)
    return result;

  THROW_WARNING("System MemoryManagerment is full.");
  
  result = malloc(size);

  ASSERT_THROW_WARNING(result, "System heap memory is empty.");
  
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
  
  if(System::mMemoryManager == nullptr){
    free(memory.mPointer);
    return;
  }
    
  if(System::mMemoryManager->freeMemory(memory))
    return;

  free(memory.mPointer);
  return;
}

/**
 * 
 */
void System::freePointer(void* pointer){
  if(System::memoryManager() != nullptr){
    if(System::memoryManager()->free(pointer))
      return;
  }

  free(pointer);
  return;
}

/**
 * 
 */
void System::freePointer(void* pointer, size_t size){
  if(System::memoryManager() != nullptr){
    if(System::memoryManager()->free(pointer, size))
      return;
  }

  free(pointer);
  return;
}

/**
 * 
 */
void System::info(const char* path, const char* message){
  System::out.format("INFO: %s - %s\n", path, message);
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
MemoryManager* System::memoryManager(void){
  return System::mMemoryManager;
}

/**
 * 
 */
void System::throwSystemError(const char* path, const char* message){
  System::out.format("ERROR: %s - %s\n", path, message);
  while(1);
}

/**
 * 
 */
void System::throwSystemWarning(const char* path, const char* message){
  System::out.format("WARNING: %s - %s\n", path, message);
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
  Memory pageMemory = Memory(Resources::MEMORYMANAGER_MEMORY, Resources::MEMORYMANAGER_MEMORY_SIZE);
  Memory flagMemory = System::mStackerManager.allocMemoryAlignment32(Math::ceil(Resources::MEMORYMANAGER_PAGE_QUANTITY, 8U));
  void* handleMemory = System::mStackerManager.allocAlignment32(sizeof(MemoryManager));
  Array<uint32_t> blockSizeList = Array<uint32_t>(Resources::MEMORYMANAGER_SUB_BLOCK, Resources::MEMORYMANAGER_SUB_BLOCK_QUANTITY);  
  
  MemoryManager::Parameter param;
  param.mPageMemory = &pageMemory;
  param.mFlagMemory = &flagMemory;
  param.mPageSize = Resources::MEMORYMANAGER_PAGE_SIZE;
  param.mStackManager = &System::mStackerManager;
  param.mBlockSizeList = &blockSizeList;
  
  System::mMemoryManager = new(handleMemory) MemoryManager(param);
  return;  
}

/**
 *
 */
void System::initPrintStream(OutputStream* outputStream){
  if(outputStream != nullptr){
    System::out = PrintStream(outputStream);
  }
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
