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
#include "mcuf/lang/Memory.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class ArrayPrototype;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::lang::ArrayPrototype extends mcuf::lang::Memory{

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */
  protected: 
    int mElementSize;
    int mElementLength;

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
  public:

    /**
     * @brief Construct a new Array Prototype object
     * 
     * @param memory 
     * @param elementSize 
     */
    ArrayPrototype(const mcuf::lang::Memory& memory, size_t elementSize);
    
    /**
     * @brief Construct a new Array Prototype object
     * 
     * @param length 
     * @param elementSize 
     */
    ArrayPrototype(size_t length, size_t elementSize);

    /**
     * @brief Destroy the Array Prototype object
     * 
     */
    virtual ~ArrayPrototype(void) override;

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
  public:

    /**
     * @brief Get the Element Length object
     * 
     * @return int 
     */
    int getElementLength(void);

    /**
     * @brief Get the Element Size object
     * 
     * @return uint32_t 
     */
    int getElementSize(void);

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */
  protected:
    using Memory::indexOf;
  
    /**
     * @brief 
     * 
     * @param element 
     * @return int 
     */
    int indexOf(const void* element) const;

    /**
     * @brief 
     * 
     * @param src 
     * @param shift 
     */
    void set(const void* src, int shift);

    /**
     * @brief 
     * 
     * @param shift 
     * @return void* 
     */
    void* get(int shift);

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

#endif /* MCUF_EC5AD114_2891_41FA_8DE3_9D5FAD422A07 */
