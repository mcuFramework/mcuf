/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_E650C2D3_441C_41FE_9189_E4BDDEA0CC31
#define MCUF_E650C2D3_441C_41FE_9189_E4BDDEA0CC31

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/util/Pool.h"
#include "mcuf/lang/Memory.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    class BlockPool;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::util::BlockPool extends mcuf::lang::Memory implements 
  public mcuf::util::Pool{

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */
  protected: 
    uint32_t mCapacity;
    uint32_t mElementSize;
    uint32_t mSize;
    uint32_t mLastFlag;
    uint8_t* mFlags;
    uint32_t mFlagSize;

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
     * @brief Construct a new Block Pool object
     * 
     * @param memory 
     * @param elementSize 
     */
    BlockPool(const mcuf::lang::Memory& memory, uint32_t elementSize);
    
    /**
     * @brief Destroy the Block Pool object
     * 
     */
    virtual ~BlockPool(void) = default;
    
  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */
  
  /* **************************************************************************************
   * Public Method <Override>
   */
  public:

    /**
     * @brief Returns this pool element size of byte.
     * 
     * @return uint32_t element size of byte.
     */
    virtual uint32_t elementSize(void) override;

    /**
     * @brief Returns this pool's capacity.
     * 
     * @return uint32_t The capacity of this pool.
     */
    virtual uint32_t capacity(void) override;

    /**
     * @brief Returns the number of elements in this pool.
     * 
     * @return uint32_t the number of elements in this pool.
     */
    virtual int size(void) override;
    
    /**
     * @brief Removes all of the elements from this pool (optional operation). The pool 
     *        will be empty after this method returns.
     * 
     */
    virtual void clear(void) override;
    
    /**
     * @brief  Returns true if this pool contains no elements.
     * 
     * @return true pool contains no elements.
     * @return false 
     */
    virtual bool isEmpty(void) override;

    /**
     * @brief Alloc memory from pool.
     * 
     * @return void* element pointer if pool not full, otherwise null pointer.
     */
    virtual void* alloc(void) override;

    /**
     * @brief 
     * 
     * @return mcuf::lang::Memory 
     */
    virtual mcuf::lang::Memory allocMemory(void) override;

    /**
     * @brief Alloc memory from pool and copy element.
     * 
     * @param element Element pointer.
     * @return void* element pointer if pool not full, otherwise null pointer.
     */
    virtual void* add(const void* element) override;

    /**
     * @brief Free this element memory. 
     * 
     * @param element Element pointer.
     * @return true if this poll found element and remove.
     * @return false 
     */
    virtual bool remove(void* element) override;

  /* **************************************************************************************
   * Public Method <Override> mcuf::lang::Iterable
   */
  public: 

    /**
     * @brief Performs the given action for each element of the Iterable until all elements 
     *        have been processed or the action throws an exception. Unless otherwise 
     *        specified by the implementing class, actions are performed in the order of 
     *        iteration (if an iteration order is specified). 
     * 
     * @param attachment 
     * @param action 
     */
    virtual void forEach(void* attachment, 
                         mcuf::function::BiConsumer<mcuf::lang::Memory*, void*>& action) override;
  
  /* **************************************************************************************
   * Public Method
   */
  public: 
 
    /**
     * @brief 
     * 
     * @return true is full.
     * @return false isn't full
     */
    bool isFull(void);

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
  private:

    /**
     * @brief 
     * 
     * @param elementSize 
     */
    void init(uint32_t elementSize);
    
    /**
     * @brief Set the Flag object
     * 
     * @param shift 
     * @param enable 
     */
    void setFlag(uint32_t shift, bool enable);
      
    /**
     * @brief Get the Block object
     * 
     * @param shift 
     * @return void* 
     */
    void* getBlock(uint32_t shift);

    /**
     * @brief Get the Flag object
     * 
     * @param shift 
     * @return true 
     * @return false 
     */
    bool getFlag(uint32_t shift);
    
    /**
     * @brief 
     * 
     * @param shift 
     * @return void* 
     */
    void* blockClear(uint32_t shift);
    
    /**
     * @brief 
     * 
     * @param shift 
     * @param element 
     * @return void* 
     */
    void* blockCopy(uint32_t shift, void* element);
    
    /**
     * @brief Get the Block Shift object
     * 
     * @param block 
     * @return uint32_t 
     */
    uint32_t getBlockShift(void* block);
  
};
 


/* *****************************************************************************************
 * End of file
 */ 


#endif /* MCUF_E650C2D3_441C_41FE_9189_E4BDDEA0CC31 */
