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

#include "mcuf\Array.h"
#include "mcuf\BiConsumer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  class ArrayQueuePrototype;
}

/* ****************************************************************************************
 * Class Object
 */  
class mcuf::ArrayQueuePrototype extends mcuf::Array<void*>{

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
    ArrayQueuePrototype(const mcuf::Memory& memory);
  
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
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    inline bool isEmpty(void) const{
      return this->mEmpty;
    }

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    inline bool isFull(void) const{
      return ((this->mHead == this->mTail) && (!this->mEmpty));
    }
   
  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override> - mcuf::Memroy
   */
  
  /* **************************************************************************************
   * Protected Method
   */
  protected:
    
    /**
     * @brief 
     * 
     */
    void clear(void);
  
    /**
     * @brief 
     * 
     * @param pointer 
     * @return true 
     * @return false 
     */
    bool offerPointer(void* pointer);

    /**
     * @brief 
     * 
     * @return void* 
     */
    void* pollPointer(void);  
    
    /**
     * @brief 
     * 
     * @return void* 
     */
    void* peekPointer(void);    
    
    /**
     * @brief 
     * 
     * @return int 
     */
    int size(void) const;

    /**
     * @brief 
     * 
     * @param attachment 
     * @param action 
     */
    void foreachPrototype(void* attachment, mcuf::function::BiConsumer<void*, void*>& action) const;

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
