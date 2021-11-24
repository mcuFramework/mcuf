/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_D6A75B59_D8E5_4FB2_BAB8_41477CE17D21
#define MCUF_D6A75B59_D8E5_4FB2_BAB8_41477CE17D21

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf\lang\Object.hpp"
#include "mcuf\lang\Pointer.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class Memory;
    class String;
    class System;
  }
}



/* ****************************************************************************************
 * Class Integer
 */  
class mcuf::lang::Memory extends mcuf::lang::Pointer{

  friend String;
  friend System;

  /* **************************************************************************************
   * Enum Flag
   */
  protected: enum MemoryFlag{
    MEMORY_FLAG_HEAP_MEMORY = (0x1<<0U),
    MEMORY_FLAG_CONST       = (0x1<<1U),
    MEMORY_FLAG_RESERVED    = 0xFFFFFFFF  ///< Prevents enum down-size compiler optimization.
  };
  
  /* **************************************************************************************
   * Subclass
   */
  
  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */
  protected: uint32_t mFlag;
  protected: uint32_t mLength;
  protected: Memory* mReference;

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

  public: Memory(void);

  /**
   * 
   */
  public: Memory(const Memory& memory);

  /**
   *
   */
  public: Memory(const void* pointer, uint32_t length);

  /**
   * 
   */  
  public: Memory(void* pointer, size_t length);
  
  /**
   *
   */
  public: Memory(uint32_t size);
  
  /**
   * 
   */  
  public: ~Memory(void);

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */
  
  /**
   * 
   */
  public: static mcuf::lang::Memory nullMemory(void);
  
  /* **************************************************************************************
   * Public Method <Override>
   */

  /**
   * 
   */
  public: virtual Pointer& copy(const void* source, uint32_t length);

  /**
   * 
   */
  public: virtual Pointer& copy(const void* source, uint32_t shift, uint32_t length);

  /**
   * 
   */
  public: virtual Pointer& copy(const void* source, uint32_t shift, uint32_t start, uint32_t length);

  /* **************************************************************************************
   * Public Method
   */

  /**
   * 
   */
  public: Memory& clear(void);

  /**
   * 
   * @return copy of number.
   */
  public: Memory& copyMemory(Memory& sourec);

  /**
   * 
   * @return copy of number.
   */
  public: Memory& copyMemory(Memory& sourec, uint32_t shift);

  /**
   * 
   * @return copy of number.
   */
  public: Memory& copyMemory(Memory& sourec, uint32_t shift, uint32_t length);

  /**
   * 
   * @return copy of number.
   */
  public: Memory& copyMemory(Memory& sourec, uint32_t shift, uint32_t start, uint32_t length);

  /**
   *
   */
  public: bool inRange(void* address);

  /**
   *
   */
  public: bool isReadOnly(void);

  /**
   * 
   */
  public: bool isEmpty(void);

  /**
   * 
   */
  public: uint32_t length(void);

  /**
   * 
   */
  public: mcuf::lang::Memory subMemory(uint32_t beginIndex);

  /**
   * 
   */
  public: mcuf::lang::Memory subMemory(uint32_t beginIndex, uint32_t length);

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
 *  End of file
 */ 


#endif/* MCUF_D6A75B59_D8E5_4FB2_BAB8_41477CE17D21 */
