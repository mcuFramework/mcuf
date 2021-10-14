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

#define HOW_U32(x) (((x)+((4)-1))/(4))
#define HOW_U64(x) (((x)+((8)-1))/(8))
#define MEMORY(position) {static_cast<void*>(resourcesMemory.position), sizeof(resourcesMemory.position)}

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  struct ResourcesMemory{
    struct{
      uint64_t stack[HOW_U64(MCUF_DEFINE_SYSTEM_THREAD_STACK_SIZE)];
      uint64_t string[HOW_U64(MCUF_DEFINE_SYSTEM_STRING_SIZE)];
    }system;
    
    struct{
      uint64_t handle[HOW_U64(sizeof(mcuf::lang::managerment::ExecutorManager))];
      uint64_t stack[HOW_U64(MCUF_DEFINE_EXECUTOR_STACK_SIZE)];
      uint64_t task[HOW_U64(MCUF_DEFINE_EXECUTOR_TASK_NUMBER*4)];
    }executor;
    
    struct{
      uint64_t handle[HOW_U64(sizeof(mcuf::lang::managerment::TimerManager))];
      uint64_t task[HOW_U64(MCUF_DEFINE_TIMER_TASK_NUMBER*4)];
    }timer;
    
    struct{
      uint64_t handle[HOW_U64(sizeof(mcuf::lang::managerment::MemoryManager))];
      uint64_t memory[HOW_U64(MCUF_DEFINE_MEMORYMANAGER_PAGE_SIZE * MCUF_DEFINE_MEMORYMANAGER_PAGE_QUANTITY)];
    }memoryManager;    
  }static resourcesMemory;
}

/* ****************************************************************************************
 * Using
 */  
using mcuf::Resources;
using mcuf::ResourcesMemory;


/* ****************************************************************************************
 * Variable <Static>
 */

const Resources::System Resources::system = {
  MEMORY(system.stack),
  MEMORY(system.string),
};

const Resources::Executor Resources::executor = {
  MEMORY(executor.handle),
  MEMORY(executor.stack),
  MEMORY(executor.task),
};

const Resources::Timer Resources::timer = {
  MEMORY(timer.handle),
  MEMORY(timer.task),
};

const Resources::MemoryManager Resources::memoryManager = {
  MEMORY(memoryManager.handle),
  MEMORY(memoryManager.memory),
};


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
