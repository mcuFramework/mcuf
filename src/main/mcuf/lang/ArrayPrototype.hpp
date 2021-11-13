/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_EC5AD114_2891_41FA_8DE3_9D5FAD422A07
#define MCUF_EC5AD114_2891_41FA_8DE3_9D5FAD422A07

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf/lang/Memory.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class ArrayPrototype;
  }
}

/* ****************************************************************************************
 * Class Object
 */  
class mcuf::lang::ArrayPrototype extends mcuf::lang::Memory{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /**
   *  
   */
  protected: uint32_t mElementSize;
  protected: uint32_t mElementLength;

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
  public: ArrayPrototype(mcuf::lang::Memory& memory, uint32_t elementSize);
  
  /**
   * Construct.
   */
  public: ArrayPrototype(void* pointer, uint32_t size, uint32_t elementSize);
  
  /**
   * Construct.
   */
  public: ArrayPrototype(const void* pointer, uint32_t size, uint32_t elementSize);  

  /**
   * Destruct.
   */
  public: virtual ~ArrayPrototype(void) = default;

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

  /**
   *
   */
  public: uint32_t getElementLength(void);

  /**
   *
   */
  public: uint32_t getElementSize(void);

  /**
   *
   */
  public: int indexOf(const void* element) const;

  /**
   *  
   */
  public: void set(const void* src, uint32_t shift);

  /**
   * 
   */
  public: void* get(uint32_t shift);

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

#endif/* MCUF_EC5AD114_2891_41FA_8DE3_9D5FAD422A07 */
