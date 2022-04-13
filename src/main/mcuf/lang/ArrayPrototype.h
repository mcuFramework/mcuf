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
    uint32_t mElementSize;
    uint32_t mElementLength;

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
    ArrayPrototype(const mcuf::lang::Memory& memory, uint32_t elementSize);
    
    /**
     * @brief Construct a new Array Prototype object
     * 
     * @param length 
     * @param elementSize 
     */
    ArrayPrototype(uint32_t length, uint32_t elementSize);

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
     * @return uint32_t 
     */
    uint32_t getElementLength(void);

    /**
     * @brief Get the Element Size object
     * 
     * @return uint32_t 
     */
    uint32_t getElementSize(void);

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
    void set(const void* src, uint32_t shift);

    /**
     * @brief 
     * 
     * @param shift 
     * @return void* 
     */
    void* get(uint32_t shift);

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
