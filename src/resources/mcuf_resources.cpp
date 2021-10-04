/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "cmsis_rtos/rtx_os.h"
#include "mcuf_resources.h"
#include "mcuf.h"

/* ****************************************************************************************
 * Macro
 */  

#define howmany_u32(x) (((x)+((4)-1))/(4))
#define howmany_u64(x) (((x)+((8)-1))/(8))

/* ****************************************************************************************
 * Using
 */  
using mcuf::Resources;
using mcuf::lang::managerment::MemoryManager;
using mcuf::lang::managerment::TimerManager;
using mcuf::lang::managerment::ExecutorManager;

/* ****************************************************************************************
 * Variable <Static>
 */
volatile static struct{
  //Fixed
  uint64_t systemThreadStack[howmany_u64(MCUF_DEFINE_SYSTEM_THREAD_STACK_SIZE)];
  uint64_t stringMemroy[howmany_u64(MCUF_DEFINE_SYSTEM_STRING_SIZE)];
  
  //Executor
#if MCUF_DEFINE_EXECUTOR_ENABLE
  struct{
    uint64_t handle[howmany_u64(sizeof(ExecutorManager))];
    uint64_t stack[howmany_u64(MCUF_DEFINE_EXECUTOR_STACK_SIZE)];
    uint64_t task[howmany_u64(MCUF_DEFINE_EXECUTOR_TASK_NUMBER*4)];
  }executor;
#endif

  //Timer
#if MCUF_DEFINE_TIMER_ENABLE
  struct{
    uint64_t handle[howmany_u64(sizeof(TimerManager))];
    uint64_t task[howmany_u64(MCUF_DEFINE_TIMER_TASK_NUMBER*4)];
  }timer;
#endif
  
  //Memory Manager
#if MCUF_DEFINE_MEMORYMANAGER_ENABLE
  struct{
    uint64_t handle[howmany_u64(sizeof(MemoryManager))];
    uint64_t memory[howmany_u64(MCUF_DEFINE_MEMORYMANAGER_SIZE * 1024)];
  }memoryManager;
#endif


}mcuf_resource_memory_entity;

/**
 * Fixed
 */
void* const Resources::systemStack = (void*)&mcuf_resource_memory_entity.systemThreadStack[0];
const uint32_t Resources::systemStackSize = sizeof(mcuf_resource_memory_entity.systemThreadStack);

void* const Resources::stringMemroy = (void*)&mcuf_resource_memory_entity.stringMemroy[0];
const uint32_t Resources::stringMemroySize = sizeof(mcuf_resource_memory_entity.stringMemroy);


/**
 * Executor
 */
#if MCUF_DEFINE_EXECUTOR_ENABLE
void* const Resources::executorHandle = (void*)&mcuf_resource_memory_entity.executor.handle[0];
const uint32_t Resources::executorHandleSize = sizeof(mcuf_resource_memory_entity.executor.handle);
  
void* const Resources::executorStack = (void*)&mcuf_resource_memory_entity.executor.stack[0];
const uint32_t Resources::executorStackSize = sizeof(mcuf_resource_memory_entity.executor.stack);
  
void* const Resources::executorTaskMemory = (void*)&mcuf_resource_memory_entity.executor.task[0];
const uint32_t Resources::executorTaskMemorySize = sizeof(mcuf_resource_memory_entity.executor.task);
#else
void* const Resources::executorClass = nullptr;
const uint32_t Resources::executorClassSize = 0;

void* const Resources::executorHandle = nullptr;
const uint32_t Resources::executorHandleSize = 0;
  
void* const Resources::executorStack = nullptr;
const uint32_t Resources::executorStackSize = 0;
  
void* const Resources::executorTaskMemory = nullptr;
const uint32_t Resources::executorTaskMemorySize = 0;
#endif

/**
 * Timer
 */
#if MCUF_DEFINE_TIMER_ENABLE
void* const Resources::timerHandle = (void*)&mcuf_resource_memory_entity.timer.handle[0];
const uint32_t Resources::timerHandleSize = sizeof(mcuf_resource_memory_entity.timer.handle);
  
void* const Resources::timerTaskMemory = (void*)&mcuf_resource_memory_entity.timer.task[0];
const uint32_t Resources::timerTaskMemorySize = sizeof(mcuf_resource_memory_entity.timer.task);
#else
void* const Resources::timerClass = nullptr;
const uint32_t Resources::timerClassSize = 0;

void* const Resources::timerHandle = nullptr;
const uint32_t Resources::timerHandleSize = 0;
  
void* const Resources::timerStack = nullptr;
const uint32_t Resources::timerStackSize = 0;
  
void* const Resources::timerTaskMemory = nullptr;
const uint32_t Resources::timerTaskMemorySize = 0;
#endif

/**
 * Memory Manager
 */
#if MCUF_DEFINE_MEMORYMANAGER_ENABLE
//handle
void* const Resources::memoryManagerHandle = (void*)&mcuf_resource_memory_entity.memoryManager.handle[0];
const uint32_t Resources::memoryManagerHandleSize = sizeof(mcuf_resource_memory_entity.memoryManager.handle);

//memory
void* const Resources::memoryManagerBuffer = (void*)&mcuf_resource_memory_entity.memoryManager.memory[0];
const uint32_t Resources::memoryManagerBufferSize = sizeof(mcuf_resource_memory_entity.memoryManager.memory);
#else
//handle
void* const Resources::systemHandleMemory = nullptr;
const uint32_t Resources::systemHandleMemorySize = 0;

//memory
void* const Resources::systemMemory = nullptr;
const uint32_t Resources::systemMemorySize = 0;
#endif

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */
 
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
