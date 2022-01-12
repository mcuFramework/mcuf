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
  
  /* **************************************************************************************
   * Enum Flag
   */
  
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
  private: uint32_t mLength;

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
  public: Memory(void* pointer, uint32_t length);
  
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
   * Public Method <Override> - mcuf::lang::Pointer
   */

  /**
   * 
   */
  public: virtual int copy(const void* source, uint32_t length) override;

  /**
   * 
   */
  public: virtual int copy(const void* source, uint32_t shift, uint32_t length) override;

  /**
   * 
   */
  public: virtual int copy(const void* source, uint32_t shift, uint32_t start, uint32_t length) override;

  /* **************************************************************************************
   * Public Method
   */

  /**
   * 
   */
  public: Memory& clear(void);
  
  /**
   * 
   */
  public: Memory& clear(uint8_t value);  

  /**
   * 
   * @return copy of number.
   */
  public: int copyMemory(Memory& sourec);

  /**
   * 
   * @return copy of number.
   */
  public: int copyMemory(Memory& sourec, uint32_t shift);

  /**
   * 
   * @return copy of number.
   */
  public: int copyMemory(Memory& sourec, uint32_t shift, uint32_t length);

  /**
   * 
   * @return copy of number.
   */
  public: int copyMemory(Memory& sourec, uint32_t shift, uint32_t start, uint32_t length);

  /**
   *
   */
  public: bool inRange(void* address) const;

  /**
   * 
   */
  public: mcuf::lang::Memory subMemory(uint32_t beginIndex) const;

  /**
   * 
   */
  public: mcuf::lang::Memory subMemory(uint32_t beginIndex, uint32_t length) const;

  /* **************************************************************************************
   * Public Method <Inline>
   */

  /**
   *
   */
  public: inline bool isReadOnly(void) const{
    return ((this->mLength & 0x80000000) == 0x80000000);
  }

  /**
   * 
   */
  public: inline bool isEmpty(void) const{
    return (this->isNull()) | (this->length() == 0);
  }

  /**
   * 
   */
  public: inline uint32_t length(void) const{
    return (this->mLength & 0x7FFFFFFF);
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
