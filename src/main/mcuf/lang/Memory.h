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
    uint32_t mLength;
    Memory* mNext;

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
    Memory(const void* pointer, size_t length);

    /**
     * @brief Construct a new Memory object
     * 
     * @param pointer 
     * @param length 
     */
    Memory(void* pointer, size_t length);

    /**
     * @brief Construct a new Memory object
     * 
     * @param length 
     */
    Memory(size_t length);
    
    /**
     * @brief Destroy the Memory object
     * 
     */
    virtual ~Memory(void) override;

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

    /**
     * @brief 
     * 
     * @param source 
     * @param length 
     * @return int32_t 
     */
    virtual int32_t copy(const void* source, uint32_t length) override;

    /**
     * @brief 
     * 
     * @param source 
     * @param shift 
     * @param length 
     * @return int32_t 
     */
    virtual int32_t copy(const void* source, int32_t shift, uint32_t length) override;

    /**
     * @brief 
     * 
     * @param source 
     * @param shift 
     * @param start 
     * @param length 
     * @return int32_t 
     */
    virtual int32_t copy(const void* source, int32_t shift, int32_t start, uint32_t length) override;

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
      return (this->mLength & 0x80000000);
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
    inline uint32_t length(void) const{
      return static_cast<uint32_t>(this->mLength & 0x7FFFFFFF);
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
    virtual bool wipe(void);

    /**
     * @brief 
     * 
     * @param value 
     * @return Memory& 
     */
    virtual bool wipe(uint8_t value);

    /**
     * @brief 
     * 
     * @param address 
     * @return true in range.
     * @return false isn't range.
     */
    virtual bool inRange(void* address) const;

    /**
     * @brief 
     * 
     * @param beginIndex 
     * @return mcuf::lang::Memory 
     */
    virtual mcuf::lang::Memory subMemory(uint32_t beginIndex) const;

    /**
     * @brief 
     * 
     * @param beginIndex 
     * @param length 
     * @return mcuf::lang::Memory 
     */
    virtual mcuf::lang::Memory subMemory(uint32_t beginIndex, uint32_t length) const;

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


#endif /* MCUF_D6A75B59_D8E5_4FB2_BAB8_41477CE17D21 */
