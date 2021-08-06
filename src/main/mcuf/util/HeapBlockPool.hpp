/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_AE8AC2E3_7638_40EB_9A6C_0BE931CC58A1
#define MCUF_AE8AC2E3_7638_40EB_9A6C_0BE931CC58A1

/* ****************************************************************************************
 * Include
 */  
#include "../util/BlockPool.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    class HeapBlockPool;
  }
}



/* ****************************************************************************************
 * Class HeapBlockPool
 */  
class mcuf::util::HeapBlockPool:
    public mcuf::util::BlockPool{
  
  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */

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
   * 
   * @param uint32_t-elementSize element size.
   * @param uint32_t-capacity capacity.
   */
  public: HeapBlockPool(uint32_t elementSize, uint32_t capacity);

  /**
   * Disconstruct.
   */
  public: ~HeapBlockPool();
  
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

  /**
   * 
   */
  private: void* allocFlag(uint32_t capacity) const;

  /**
   * 
   */
  private: void* allocPointer(uint32_t elementSize, uint32_t capacity) const;

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


#endif/* MCUF_AE8AC2E3_7638_40EB_9A6C_0BE931CC58A1 */
