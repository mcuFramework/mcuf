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
#include "mcuf/lang/Object.h"
#include "mcuf/lang/Pointer.h"

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
 * Class/Interface/Struct
 */  
class mcuf::lang::Memory extends mcuf::lang::Pointer{

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  private: 
    int mLength;

  /* **************************************************************************************
   * Abstract method <Public>
   */
   
  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  public:

    /**
     * @brief Construct a new Memory object
     * 
     * @param memory 
     */
    Memory(const Memory& memory);

    /**
     * @brief Construct a new Memory object
     * 
     * @param pointer 
     * @param length 
     */
    Memory(const void* pointer, uint32_t length);

    /**
     * @brief Construct a new Memory object
     * 
     * @param pointer 
     * @param length 
     */
    Memory(void* pointer, uint32_t length);
    
    /**
     * @brief Destroy the Memory object
     * 
     */
    ~Memory(void);

  /* **************************************************************************************
   * Operator Method
   */
    
  /* **************************************************************************************
   * Public Method <Static>
   */
  public:
  
    /**
     * @brief 
     * 
     * @return mcuf::lang::Memory 
     */
    static mcuf::lang::Memory nullMemory(void);
  
  /* **************************************************************************************
   * Public Method <Override> - mcuf::lang::Pointer
   */
  public:
  
    virtual int copy(const void* source, uint32_t length) override;

    virtual int copy(const void* source, uint32_t shift, uint32_t length) override;

    virtual int copy(const void* source, uint32_t shift, uint32_t start, uint32_t length) override;

  /* **************************************************************************************
   * Public Method <Inline>
   */
  public: 

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    inline bool isReadOnly(void) const{
      return (this->mLength <= 0);
    }

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    inline bool isEmpty(void) const{
      return (this->isNull()) | (this->length() == 0);
    }

    /**
     * @brief 
     * 
     * @return uint32_t 
     */
    inline int length(void) const{
      return ((this->mLength <= 0) ? ((~this->mLength) + 1) : this->mLength);
    }  
  
  /* **************************************************************************************
   * Public Method
   */
  public: 
  
    /**
     * @brief 
     * 
     * @return Memory& 
     */
    Memory& clear(void);
    
    /**
     * @brief 
     * 
     * @param value 
     * @return Memory& 
     */
    Memory& clear(uint8_t value);  

    /**
     * @brief 
     * 
     * @param sourec 
     * @return int copy of number.
     */
    int copyMemory(Memory& sourec);

    /**
     * @brief 
     * 
     * @param sourec 
     * @param shift 
     * @return int int copy of number.
     */
    int copyMemory(Memory& sourec, uint32_t shift);

    /**
     * @brief 
     * 
     * @param sourec 
     * @param shift 
     * @param length 
     * @return int copy of number. 
     */
    int copyMemory(Memory& sourec, uint32_t shift, uint32_t length);

    /**
     * @brief 
     * 
     * @param sourec 
     * @param shift 
     * @param start 
     * @param length 
     * @return int copy of number. 
     */
    int copyMemory(Memory& sourec, uint32_t shift, uint32_t start, uint32_t length);

    /**
     * @brief 
     * 
     * @param address 
     * @return true in range.
     * @return false isn't range.
     */
    bool inRange(void* address) const;

    /**
     * @brief 
     * 
     * @param beginIndex 
     * @return mcuf::lang::Memory 
     */
    mcuf::lang::Memory subMemory(uint32_t beginIndex) const;

    /**
     * @brief 
     * 
     * @param beginIndex 
     * @param length 
     * @return mcuf::lang::Memory 
     */
    mcuf::lang::Memory subMemory(uint32_t beginIndex, uint32_t length) const;

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
