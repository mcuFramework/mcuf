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


/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace resource{
    namespace config{
      #if (MCUF_DEFINE_MEMORYMANAGER_PAGE_SIZE == 512)
      const uint32_t memoryManagerBlock[] = {8, 16, 24, 32, 48, 64, 96, 128};
      #elif (MCUF_DEFINE_MEMORYMANAGER_PAGE_SIZE == 1024)
      const uint32_t memoryManagerBlock[] = {8, 16, 24, 32, 48, 64, 96, 128, 256};
      #elif (MCUF_DEFINE_MEMORYMANAGER_PAGE_SIZE == 2048)
      const uint32_t memoryManagerBlock[] = {8, 16, 24, 32, 48, 64, 96, 128, 256, 512};
      #elif (MCUF_DEFINE_MEMORYMANAGER_PAGE_SIZE == 4096)
      const uint32_t memoryManagerBlock[] = {8, 16, 24, 32, 48, 64, 96, 128, 256, 512, 1024};
      #elif (MCUF_DEFINE_MEMORYMANAGER_PAGE_SIZE == 8192)
      const uint32_t memoryManagerBlock[] = {8, 16, 24, 32, 48, 64, 96, 128, 256, 512, 1024, 2048};
      #elif (MCUF_DEFINE_MEMORYMANAGER_PAGE_SIZE == 16384)
      const uint32_t memoryManagerBlock[] = {8, 16, 24, 32, 48, 64, 96, 128, 256, 512, 1024, 2048, 4096};
      #elif (MCUF_DEFINE_MEMORYMANAGER_PAGE_SIZE == 32768)
      const uint32_t memoryManagerBlock[] = {8, 16, 24, 32, 48, 64, 96, 128, 256, 512, 1024, 2048, 4096};
      #endif
    }
    
    namespace memory{
      uint64_t coreMemory[HOW_U64(MCUF_DEFINE_CORE_MEMORY_SIZE)];
      uint64_t memoryManager[HOW_U64(MCUF_DEFINE_MEMORYMANAGER_PAGE_SIZE * MCUF_DEFINE_MEMORYMANAGER_PAGE_QUANTITY)];
      uint64_t stringFormat[HOW_U64(MCUF_DEFINE_STRING_FORMAT_SIZE)];
    }
  }
  
}

/* ****************************************************************************************
 * Using
 */  
using mcuf::Resources;


/* ****************************************************************************************
 * Variable <Static>
 */

void* const Resources::CORE_MEMORY = mcuf::resource::memory::coreMemory;
const uint32_t Resources::CORE_MEMORY_SIZE = sizeof(mcuf::resource::memory::coreMemory);

void* const Resources::STRING_FORMAT_MEMORY = mcuf::resource::memory::stringFormat;
const uint32_t Resources::STRING_FORMAT_MEMORY_SIZE = sizeof(mcuf::resource::memory::stringFormat);

void* const Resources::MEMORYMANAGER_MEMORY = mcuf::resource::memory::memoryManager;
const uint32_t Resources::MEMORYMANAGER_MEMORY_SIZE = sizeof(mcuf::resource::memory::memoryManager);




const uint32_t Resources::SYSTEM_STACK_SIZE = MCUF_DEFINE_MAIN_THREAD_STACK_SIZE;
const uint32_t Resources::EXECUTOR_STACK_SIZE = MCUF_DEFINE_EXECUTOR_STACK_SIZE;
const uint32_t Resources::EXECUTOR_TASK_QUANTITY = MCUF_DEFINE_EXECUTOR_TASK_NUMBER;
const uint32_t Resources::TIMER_TASK_QUANTITY = MCUF_DEFINE_TIMER_TASK_NUMBER;

const uint32_t Resources::MEMORYMANAGER_PAGE_SIZE = MCUF_DEFINE_MEMORYMANAGER_PAGE_SIZE;
const uint32_t Resources::MEMORYMANAGER_PAGE_QUANTITY = MCUF_DEFINE_MEMORYMANAGER_PAGE_QUANTITY;

const uint32_t* Resources::MEMORYMANAGER_SUB_BLOCK = mcuf::resource::config::memoryManagerBlock;
const uint32_t Resources::MEMORYMANAGER_SUB_BLOCK_QUANTITY = (sizeof(mcuf::resource::config::memoryManagerBlock) / sizeof(uint32_t));


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
