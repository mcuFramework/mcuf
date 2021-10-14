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
void operator delete (void* ptr){
  System::freePointer(ptr);
}

/**
 * 
 */
void operator delete[] (void* ptr){
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
  System::initThread(thread);
  osKernelStart();
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
  if(Resources::checkMemory(Resources::memoryManager.handle, sizeof(MemoryManager)))
    return;
  
  if(Resources::checkMemory(Resources::memoryManager.memory, 16384))
    return;
  
  Memory memory = Memory(Resources::memoryManager.memory.point, Resources::memoryManager.memory.size);
  System::mMemoryManager = new(Resources::memoryManager.handle.point) MemoryManager(memory);
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
  
  if(Resources::system.stack.point == nullptr)
    return;
  
  if(Resources::system.stack.size < 256)
    return;
  
  osKernelInitialize();
  
  Memory stackMemory = Memory(Resources::system.stack.point, Resources::system.stack.size);
  
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
  if(Resources::checkMemory(Resources::timer.handle, sizeof(TimerManager)))
    return;  
  
  if(Resources::checkMemory(Resources::timer.task, 64))
    return;  
  
  Memory taskMemory = Memory(Resources::timer.task.point, Resources::timer.task.size);
  System::mTimerManager = new(Resources::timer.handle.point) TimerManager(taskMemory);
  
  if(!mTimerManager->start(5))
    THROW_ERROR("System timer start fail.");
  
  return;
}
  
/**
 *
 */
void System::initExecutor(void){
  if(Resources::checkMemory(Resources::executor.handle, sizeof(ExecutorManager)))
    return;
  
  if(Resources::checkMemory(Resources::executor.stack, 256))
    return;
  
  if(Resources::checkMemory(Resources::executor.task, 64))
    return;
  
  Memory stackMemory = Memory(Resources::executor.stack.point, Resources::executor.stack.size);
  Memory taskMemory = Memory(Resources::executor.task.point, Resources::executor.task.size);
  
  System::mExecutorManager = new(Resources::executor.handle.point) ExecutorManager(taskMemory);
  
  if(!System::mExecutorManager->mThreadEvent.start(stackMemory, Thread::PRIORITY_HIGH))
    THROW_ERROR("System executor start fail.");
  
  return;
}
 
/* ****************************************************************************************
 * End of file
 */ 
