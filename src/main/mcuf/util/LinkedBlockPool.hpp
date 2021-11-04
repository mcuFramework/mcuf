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

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"
#include "mcuf/util/BlockPool.hpp"
#include "mcuf/lang/Linked.hpp"
#include "mcuf/lang/LinkedEntity.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    class LinkedBlockPool;
  }
}

/* ****************************************************************************************
 * Class LinkedBlockPool
 */  
class mcuf::util::LinkedBlockPool extends mcuf::util::BlockPool
      implements mcuf::lang::Linked<LinkedBlockPool>{

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
  private: mcuf::lang::LinkedEntity mLinkedEntity;

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
  public: LinkedBlockPool(uint32_t pageSize, uint32_t elementSize);

  /**
   * Construct.
   */
  public: LinkedBlockPool(mcuf::lang::Memory& page, uint32_t elementSize, mcuf::lang::Memory& flag);

  /**
   * Construct.
   */
  public: LinkedBlockPool(mcuf::lang::Memory& page, uint32_t elementSize);

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::lang::Linked<LinkedBlockPool>
   */

  /**
   * 
   */
  public: virtual bool addLinked(LinkedBlockPool* e) override;

  /**
   * 
   */
  public: virtual bool insertLinked(LinkedBlockPool* e) override;

  /**
   *
   */
  public: virtual LinkedBlockPool* getNextLinked(void) override;

  /**
   * 
   */
  public: virtual bool hasNextLinked(void) override;

  /**
   * 
   */
  public: virtual LinkedBlockPool* removeLinked(void) override;

  /**
   * 
   */
  public: virtual LinkedBlockPool* removeAllLinked(void) override;

  /* **************************************************************************************
   * Public Method <Override> - mcuf::util::BlockPool
   */

  /**
   * Alloc memory from pool and copy element.
   *
   * @element Element pointer.
   * @return element pointer if pool not full, otherwise null pointer.
   */
  public: virtual void* add(void* element) override;

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
   * Returns this pool's capacity.
   *
   * @return The capacity of this pool.
   */
  public: virtual uint32_t capacity(void) override;

  /**
   * Removes all of the elements from this pool (optional operation). The pool will be empty after this method returns.
   */
  public: virtual void clear(void) override;
  
  /**
   * Performs the given action for each element of the Iterable until all elements have 
   * been processed or the action throws an exception. Unless otherwise specified by the 
   * implementing class, actions are performed in the order of iteration (if an iteration 
   * order is specified). 
   *
   * @action - The action to be performed for each element.
   */
  public: virtual void forEach(mcuf::function::Consumer<mcuf::lang::Memory&>& consumer) override;

  /**
   * Returns true if this pool contains no elements.
   *
   * @return true if this pool contains no elements.
   */
  public: virtual bool isEmpty(void) override;
  


  /**
   * Returns the number of elements in this pool.
   *
   * @return the number of elements in this pool.
   */
  public: virtual uint32_t size(void) override;
  
  /**
   * Free this element memory.  
   *
   * @element Element pointer.
   * @return true if this poll found element and remove.
   */
  public: virtual bool remove(void* element) override;

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

};



/* *****************************************************************************************
 * End of file
 */ 


#endif/* MCUF_E052FF6F_B370_4FEE_8D98_DE8F6F181205 */
