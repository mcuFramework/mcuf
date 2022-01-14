/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_DE6DDA25_542E_4780_B9F6_CE3B65F761EC
#define MCUF_DE6DDA25_542E_4780_B9F6_CE3B65F761EC

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/lang/Memory.hpp"
#include "mcuf/util/Pool.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    class LinkedPool;
  }
}

/* ****************************************************************************************
 * Class Object
 */  
class mcuf::util::LinkedPool extends mcuf::lang::Memory
      implements mcuf::util::Pool{

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
  private: uint32_t mElementSize;
  private: uint32_t mEmptyBlock;
  private: uint32_t mUsedBlock;

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
  public: LinkedPool(Memory& memory, uint32_t elementSize);

  /**
   * Disconstruct.
   */
  public: virtual ~LinkedPool(void);

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Public> - mcuf::util::Iterable
   */
   
  /**
   * Performs the given action for each element of the Iterable until all elements have 
   * been processed or the action throws an exception. Unless otherwise specified by the 
   * implementing class, actions are performed in the order of iteration (if an iteration 
   * order is specified). 
   *
   * @action - The action to be performed for each element.
   */
  public: virtual void forEach(mcuf::function::Consumer<mcuf::lang::Memory*>& action) override;
   
  /* **************************************************************************************
   * Public Method <Public> - mcuf::util::Collection
   */

  /**
   * Removes all of the elements from this collection. The collection will be empty after 
   * this method returns.
   */
  public: virtual void clear(void) override;

  /**
   * Returns true if this collection contains no elements.
   * 
   * @return true if this collection contains no elements.
   */
  public: virtual bool isEmpty(void) override;

  /**
   * Returns the number of elements in this collection.
   * 
   * @return the number of elements in this collection.
   */
  public: virtual uint32_t size(void) override;
  
  /* **************************************************************************************
   * Public Method <Public> - mcuf::util::Pool
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
  public: virtual void* add(void* elenemt) override;
  
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

#endif/* MCUF_DE6DDA25_542E_4780_B9F6_CE3B65F761EC */
