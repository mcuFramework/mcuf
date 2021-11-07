/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_ADD5434B_ED19_4DB8_9CDA_378B788B8852
#define MCUF_ADD5434B_ED19_4DB8_9CDA_378B788B8852

/* ****************************************************************************************
 * Include
 */  

#include "stdint.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  class Resources;
}

/* ****************************************************************************************
 * Class Resources
 */  
class mcuf::Resources{

  /* **************************************************************************************
   * Substruct
   */
  
  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */
  
  public: static void* const CORE_MEMORY;
  public: static const uint32_t CORE_MEMORY_SIZE;
  
  public: static void* const MEMORYMANAGER_MEMORY;
  public: static const uint32_t MEMORYMANAGER_MEMORY_SIZE;
  
  public: static void* const STRING_FORMAT_MEMORY;
  public: static const uint32_t STRING_FORMAT_MEMORY_SIZE;
  
  public: static const uint32_t SYSTEM_STACK_SIZE;
  public: static const uint32_t EXECUTOR_STACK_SIZE;
  public: static const uint32_t EXECUTOR_TASK_QUANTITY;
  public: static const uint32_t TIMER_TASK_QUANTITY;
  public: static const uint32_t MEMORYMANAGER_PAGE_SIZE;
  public: static const uint32_t MEMORYMANAGER_PAGE_QUANTITY;  
  public: static const uint32_t* MEMORYMANAGER_SUB_BLOCK;
  public: static const uint32_t MEMORYMANAGER_SUB_BLOCK_QUANTITY;
  
  
  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

  /**
   * Construct.
   */
  private: Resources(void) = default;

  /**
   * Destruct.
   */
  public: virtual ~Resources(void) = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method
   */

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */
   
  /* **************************************************************************************
   * Private Method
   */  

};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_ADD5434B_ED19_4DB8_9CDA_378B788B8852 */
