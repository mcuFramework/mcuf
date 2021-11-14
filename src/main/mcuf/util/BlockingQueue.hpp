/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_EABFB0E9_4CE7_4009_A990_B20F60799B41
#define MCUF_EABFB0E9_4CE7_4009_A990_B20F60799B41

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/util/BlockingQueuePrototype.hpp"
#include "mcuf/util/Collection.hpp"
#include "mcuf/util/Queue.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    template<typename E> class BlockingQueue;
  }
}

/* ****************************************************************************************
 * Class Object
 */  
template<typename E>
class mcuf::util::BlockingQueue extends mcuf::util::BlockingQueuePrototype
  implements mcuf::util::Queue<E>{

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
   * Construct.
   */
  public: BlockingQueue(Memory& memory) construct mcuf::util::BlockingQueuePrototype(memory){
    return;
  }
  
  /**
   * Construct.
   */
  public: BlockingQueue(Memory&& memory) construct mcuf::util::BlockingQueuePrototype(memory){
    return;
  }  
  
  /**
   * Construct.
   */
  public: BlockingQueue(uint32_t length) construct mcuf::util::BlockingQueuePrototype(length){
    return;
  }

  /**
   * Destruct.
   */
  public: virtual ~BlockingQueue(void) = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::util::Queue<E>
   */
  
  /**
   * Inserts the specified element into this queue if it is possible to do so immediately 
   * without violating capacity restrictions.
   * 
   * @param e the element to add.
   * @return true if the element was added to this queue, else false.
   */
  public: virtual bool offer(E* e) override{
    return this->BlockingQueuePrototype::offerPointer(e);
  }

  /**
   * Retrieves, but does not remove, the head of this queue, or returns null if this queue 
   * is empty.
   * 
   * @return Retrieves, but does not remove, the head of this queue, or returns null if 
   *         this queue is empty.
   */
  public: virtual E* poll(void) override{
    return static_cast<E*>(this->BlockingQueuePrototype::pollPointer());
  }

  /**
   * Retrieves and removes the head of this queue, or returns null if this queue is empty.
   * 
   * @return he head of this queue, or null if this queue is empty.
   */
  public: virtual E* peek(void) override{
    return static_cast<E*>(this->BlockingQueuePrototype::peekPointer());
  }
  
  /* **************************************************************************************
   * Public Method <Override> - mcuf::lang::Iterable<E>
   */  
  
  /**
   * Performs the given action for each element of the Iterable until all elements have 
   * been processed or the action throws an exception. Unless otherwise specified by the 
   * implementing class, actions are performed in the order of iteration (if an iteration 
   * order is specified). 
   *
   * @action - The action to be performed for each element.
   */
  virtual void forEach(mcuf::function::Consumer<E*>& action) override{
  
  }  
  
  /* **************************************************************************************
   * Public Method <Override> - mcuf::util::Collection<E>
   */  

  /**
   * Removes all of the elements from this collection. The collection will be empty after 
   * this method returns.
   */
  public: virtual void clear(void) override{
    return this->BlockingQueuePrototype::clear();
  }

  /**
   * Returns true if this collection contains no elements.
   * 
   * @return true if this collection contains no elements.
   */
  public: virtual bool isEmpty(void) override{
    return this->BlockingQueuePrototype::isEmpty();
  }

  /**
   * Returns the number of elements in this collection.
   * 
   * @return the number of elements in this collection.
   */
  public: virtual uint32_t size(void) override{
    return this->BlockingQueuePrototype::size();
  }

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

#endif/* MCUF_EABFB0E9_4CE7_4009_A990_B20F60799B41 */
