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
  struct Buffer{
    void* const point;
    const uint32_t size;
  };
  
  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */
  
  public: struct System{
    Buffer stack;
    Buffer string;
  }static const system; 
  
  public: struct Executor{
    Buffer handle;
    Buffer stack;
    Buffer task;
  }static const executor;
  
  public: struct Timer{
    Buffer handle;
    Buffer task;
  }static const timer;
  
  public: struct MemoryManager{
    Buffer handle;
    Buffer memory;
    struct{
      const uint32_t pageSize;
      const uint32_t* subPageList;
      const uint32_t subPageListLength;
    }config;

  }static const memoryManager;

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
   
  /**
   *
   */
  public: static bool inline checkMemory(const Buffer& buffer, uint32_t size){
    if(buffer.point == nullptr)
      return false;
    
    if(buffer.size < 0)
      return false;
    
    return true;
  }

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
