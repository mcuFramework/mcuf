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
  protected: 
    uint16_t mHead;
    uint16_t mTail;
    bool mEmpty;
  
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
  protected:
    
    /**
     * @brief Construct a new Array Queue Prototype object
     * 
     * @param memory 
     */
    ArrayQueuePrototype(const mcuf::lang::Memory& memory);
  
    /**
     * @brief Construct a new Array Queue Prototype object
     * 
     * @param size
     */
    ArrayQueuePrototype(uint32_t size);

    /**
     * @brief Destroy the Array Queue Prototype object
     * 
     */
    virtual ~ArrayQueuePrototype(void) override;

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
  public: 
    /**
     * 
     */
    inline bool isEmpty(void) const{
      return this->mEmpty;
    }

    /**
     * 
     */
    inline bool isFull(void) const{
      return ((this->mHead == this->mTail) && (!this->mEmpty));
    }
   
  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override> - mcuf::lang::Memroy
   */
  
  /* **************************************************************************************
   * Protected Method
   */
  protected:
    
    /**
     *
     */
    void clear(void);
  
    /**
     * 
     */
    bool offerPointer(void* pointer);

    /**
     * 
     */
    void* pollPointer(void);  
    
    /**
     * 
     */
    void* peekPointer(void);    
    
    /**
     *
     */
    int size(void) const;

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

#endif /* MCUF_BBEA45DB_2443_4AD0_8532_619E2BDE4831 */
