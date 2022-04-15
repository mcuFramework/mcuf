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
    virtual int copy(const void* source, int length) override;

    /**
     * @brief 
     * 
     * @param source 
     * @param start 
     * @param length 
     * @return int32_t 
     */
    virtual int copy(const void* source, int start, int length) override;

    /**
     * @brief 
     * 
     * @param source 
     * @param shift 
     * @param start 
     * @param length 
     * @return int32_t 
     */
    virtual int copy(const void* source, int shift, int start, int length) override;

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
    inline int length(void) const{
      return static_cast<int>(this->mLength & 0x7FFFFFFF);
    }  
  
  /* **************************************************************************************
   * Public Method
   */
  public: 
  
    /**
     * @brief 
     * 
     * @return int 
     */
    virtual int wipe(void);

    /**
     * @brief 
     * 
     * @param value 
     * @return int 
     */
    virtual int wipe(uint8_t value);
  
    /**
     * @brief 
     * 
     * @param value 
     * @param length 
     * @return int 
     */
    virtual int wipe(uint8_t value, int length);
  
    /**
     * @brief 
     * 
     * @param value 
     * @param start 
     * @param length 
     * @return int 
     */
    virtual int wipe(uint8_t value, int start, int length);

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
    
    /**
     * @brief 
     * 
     * @param source 
     * @param shift 
     * @param start 
     * @param length 
     * @return int32_t 
     */
    virtual int insertArray(const void* source, int start, int length);

    /**
     * @brief 
     * 
     * @param source 
     * @param shift 
     * @param start 
     * @param length 
     * @return int32_t 
     */
    virtual int insertArray(const void* source, int shift, int start, int length);

    /**
     * @brief 
     * 
     * @param start 
     * @param length 
     * @return int32_t 
     */
    virtual int popArray(int start, int length);

    /**
     * @brief 
     * 
     * @param source 
     * @param start 
     * @param length 
     * @return int32_t 
     */
    virtual int popArray(void* source, int start, int length);

    /**
     * @brief 
     * 
     * @param source 
     * @param shift 
     * @param start 
     * @param length 
     * @return true 
     * @return false 
     */
    virtual int popArray(void* source, int shift, int start, int length);

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
