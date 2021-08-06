/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_E052FF6F_B370_4FEE_8D98_DE8F6F181205
#define MCUF_E052FF6F_B370_4FEE_8D98_DE8F6F181205

/* ****************************************************************************************
 * Include
 */  
#include "../util/BlockPool.hpp"
#include "../lang/Vector.hpp"


/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    class VectorBlockPool;
  }
}



/* ****************************************************************************************
 * Class VectorBlockPool
 */  
class mcuf::util::VectorBlockPool : 
      public mcuf::util::BlockPool, 
      public mcuf::lang::Vector<mcuf::util::VectorBlockPool>{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

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
   * 
   */
  protected: VectorBlockPool(void* flag, void* pointer, uint32_t elementSize, uint32_t capacity);

  /**
   * 
   */
  public: VectorBlockPool(mcuf::lang::Memory flags, mcuf::lang::Memory memory, uint32_t elementSize);
  
  /**
   * 
   */
  public: VectorBlockPool(mcuf::lang::Memory memory, uint32_t elementSize);

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
   * Alloc memory from pool and copy element.
   *
   * @element Element pointer.
   * @return element pointer if pool not full, otherwise null pointer.
   */
  public: virtual void* add(void* element);

  /**
   * Alloc memory from pool.
   *
   * @return element pointer if pool not full, otherwise null pointer.
   */
  public: virtual void* alloc(void);

  /**
   * 
   */
  public: virtual mcuf::lang::Memory allocMemory(void);

  /**
   * Returns this pool's capacity.
   *
   * @return The capacity of this pool.
   */
  public: virtual uint32_t capacity(void);

  /**
   * Removes all of the elements from this pool (optional operation). The pool will be empty after this method returns.
   */
  public: virtual void clear(void);
  
  /**
   * Performs the given action for each element of the Iterable until all elements have 
   * been processed or the action throws an exception. Unless otherwise specified by the 
   * implementing class, actions are performed in the order of iteration (if an iteration 
   * order is specified). 
   *
   * @action - The action to be performed for each element.
   */
  public: virtual void forEach(mcuf::function::Consumer<mcuf::lang::Memory&>& consumer);

  /**
   * 
   */
  public: virtual VectorBlockPool* getBase(void);

  /**
   * Returns true if this pool contains no elements.
   *
   * @return true if this pool contains no elements.
   */
  public: virtual bool isEmpty(void);
  
  /**
   * 
   */
  public: bool isFull(void);

  /**
   * Returns the number of elements in this pool.
   *
   * @return the number of elements in this pool.
   */
  public: virtual uint32_t size(void);
  
  /**
   * Free this element memory.  
   *
   * @element Element pointer.
   * @return true if this poll found element and remove.
   */
  public: virtual bool remove(void* element);

  /* **************************************************************************************
   * Public Method
   */

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
 * End of file
 */ 


#endif/* MCUF_E052FF6F_B370_4FEE_8D98_DE8F6F181205 */
