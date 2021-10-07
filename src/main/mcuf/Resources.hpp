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
  
  /**
   * System
   */
  public: static void* const systemStack;
  public: static const uint32_t systemStackSize;
  
  public: static void* const stringMemroy;
  public: static const uint32_t stringMemroySize;
  
  /**
   * Executor
   */
  public: static void* const executorHandle;
  public: static const uint32_t executorHandleSize;
  
  public: static void* const executorStack;
  public: static const uint32_t executorStackSize;  
  
  public: static void* const executorTaskMemory;
  public: static const uint32_t executorTaskMemorySize;
  
  /**
   * Timer
   */
  public: static void* const timerHandle;
  public: static const uint32_t timerHandleSize;
  
  public: static void* const timerTaskMemory;
  public: static const uint32_t timerTaskMemorySize;
  
  /**
   * Memory manager
   */
  public: static void* const memoryManagerHandle;
  public: static const uint32_t memoryManagerHandleSize;
  
  public: static void* const memoryManagerBuffer;
  public: static const uint32_t memoryManagerBufferSize;
  

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
