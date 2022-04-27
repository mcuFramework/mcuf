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
#include "mcuf/lang/Data.h"

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
class mcuf::lang::Memory extends mcuf::lang::Data{

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
   * Public Method <Inline>
   */
  public: 

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    inline bool isHeapMemory(void) const{
      return (this->mNext != nullptr);
    }
  
  /* **************************************************************************************
   * Public Method
   */
  public:
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
     * @param size 
     * @return true 
     * @return false 
     */
    virtual bool resize(int size);

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
