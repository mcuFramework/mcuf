/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_BBEA45DB_2443_4AD0_8532_619E2BDE4831
#define MCUF_BBEA45DB_2443_4AD0_8532_619E2BDE4831

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"

#include "mcuf/lang/Array.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    class ArrayQueuePrototype;
  }
}

/* ****************************************************************************************
 * Class Object
 */  
class mcuf::util::ArrayQueuePrototype extends mcuf::lang::Array<void*>{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */
  protected: uint16_t mHead;
  protected: uint16_t mTail;
  protected: bool mEmpty;
  
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
  protected: ArrayQueuePrototype(const mcuf::lang::Memory& memory);

  /**
   * Destruct.
   */
  protected: virtual ~ArrayQueuePrototype(void) = default;

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
   * Public Method <Inline>
   */
   
  /**
   * 
   */
  public: inline bool isEmpty(void){
    return this->mEmpty;
  }

  /**
   * 
   */
  public: inline bool isFull(void){
    return ((this->mHead == this->mTail) == !this->mEmpty);
  }
   
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
  protected: void clear(void);

  /**
   * 
   */
  protected: bool offerPointer(void* pointer);

  /**
   * 
   */
  protected: void* pollPointer(void);  
  
  /**
   * 
   */
  protected: void* peekPointer(void);    
  
  /**
   *
   */
  protected: uint32_t size(void);  

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

#endif/* MCUF_BBEA45DB_2443_4AD0_8532_619E2BDE4831 */
