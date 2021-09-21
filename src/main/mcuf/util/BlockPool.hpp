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
#include "mcuf/util/Pool.hpp"
#include "mcuf/lang/Memory.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    class BlockPool;
  }
}



/* ****************************************************************************************
 * Class BlockPool
 */  
class mcuf::util::BlockPool implement mcuf::util::Pool{
  
  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */
  protected: uint8_t* mFlags;
  protected: uint8_t* mPointer;
  protected: uint32_t mCapacity;
  protected: uint32_t mElementSize;
  protected: uint32_t mSize;
  protected: uint32_t mLastFlag;

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

  /**
   * Construct.
   */
  protected: BlockPool(void* flag, void* pointer, uint32_t elementSize, uint32_t capacity);

  /**
   * Construct.
   */
  public: BlockPool(mcuf::lang::Memory& flags, mcuf::lang::Memory& memory, uint32_t elementSize);

  /**
   * Construct.
   */
  public: BlockPool(mcuf::lang::Memory& memory, uint32_t elementSize);
  
  /**
   * Destruct.
   */
  public: virtual ~BlockPool() = default;
  
  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */
  
  /* **************************************************************************************
   * Public Method <Override>
   */
  
  /**
   * Returns this pool element size of byte
   *
   * @return element size of byte.
   */
  public: virtual uint32_t elementSize(void) override;
  
  /**
   * Returns this pool's capacity.
   *
   * @return The capacity of this pool.
   */
  public: virtual uint32_t capacity(void) override;
  
  /**
   * Returns the number of elements in this pool.
   *
   * @return the number of elements in this pool.
   */
  public: virtual uint32_t size(void) override;
  
  /**
   * Removes all of the elements from this pool (optional operation). The pool will be empty after this method returns.
   */
  public: virtual void clear(void) override;
  
  /**
   * Returns true if this pool contains no elements.
   *
   * @return true if this pool contains no elements.
   */
  public: virtual bool isEmpty(void) override;
  
  /**
   * Alloc memory from pool.
   *
   * @return element pointer if pool not full, otherwise null pointer.
   */
  public: virtual void* alloc(void) override;

  /**
   * 
   */
  public: virtual mcuf::lang::Memory allocMemory(void) override;
  
  /**
   * Alloc memory from pool and copy element.
   *
   * @element Element pointer.
   * @return element pointer if pool not full, otherwise null pointer.
   */
  public: virtual void* add(void* element) override;
  
  /**
   * Free this element memory.  
   *
   * @element Element pointer.
   * @return true if this poll found element and remove.
   */
  public: virtual bool remove(void* element) override;

  /**
   * Performs the given action for each element of the Iterable until all elements have 
   * been processed or the action throws an exception. Unless otherwise specified by the 
   * implementing class, actions are performed in the order of iteration (if an iteration 
   * order is specified). 
   *
   * @action - The action to be performed for each element.
   */
  public: virtual void forEach(mcuf::function::Consumer<mcuf::lang::Memory&>& consumer) override;
  
  /* **************************************************************************************
   * Public Method
   */

  /**
   * 
   */
  public: bool isFull(void);

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

  /**
   * 
   */
  private: void construct(void* flag, void* pointer, uint32_t elementSize, uint32_t capacity);

  /**
   *
   */
  private: void flagFormat(void);
  
  /**
   * 
   */
  private: uint32_t getFixedSize(uint32_t capacity, uint32_t elementSize);
  
  /**
   *
   */
  private: void setFlag(uint32_t shift, bool enable);
  
  /**
   *
   */
  private: void* getBlock(uint32_t shift);
  
  /**
   * 
   */
  private: uint32_t foundAndSetFlag(void);

  /**
   *
   */
  private: bool getFlag(uint32_t shift);

  /**
   *
   */
  private: void* blockClear(uint32_t shift);
  
  /**
   *
   */
  private: void* blockCopy(uint32_t shift, void* element);
  
  /**
   *
   */
  private: uint32_t getBlockShift(void* block);
  
};
 


/* *****************************************************************************************
 * End of file
 */ 


#endif/* MCUF_E650C2D3_441C_41FE_9189_E4BDDEA0CC31 */
