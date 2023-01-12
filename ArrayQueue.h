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
#include "./mcuf_base.h"
#include "./ArrayQueuePrototype.h"
#include "./Collection.h"
#include "./Queue.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  template<typename E> class ArrayQueue;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
template<typename E>
class mcuf::ArrayQueue extends mcuf::ArrayQueuePrototype implements 
  public mcuf::Queue<E>{

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

  public: 
  
    /**
     * @brief Construct a new Array Queue object
     * 
     * @param memory 
     */
    ArrayQueue(const Memory& memory) : mcuf::ArrayQueuePrototype(memory){
      return;
    }

    /**
     * @brief Construct a new Array Queue object
     * 
     * @param length 
     */
    ArrayQueue(uint32_t length) : mcuf::ArrayQueuePrototype(length){
      return;
    }

    /**
     * @brief Destroy the Array Queue object
     * 
     */
    virtual ~ArrayQueue(void) override {
      return;
    }

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::Queue<E>
   */
  public: 

    /**
     * @brief Inserts the specified element into this queue if it is possible to do so 
     *        immediately without violating capacity restrictions.
     * 
     * @param e 
     * @return true add successful
     * @return false add fail
     */
    virtual bool offer(E* e) override{
      return this->ArrayQueuePrototype::offerPointer(e);
    }

    /**
     * @brief  Retrieves, but does not remove, the head of this queue, or returns null if 
     *         this queue is empty.
     * 
     * @return E* Retrieves, but does not remove, the head of this queue, or returns null if
     *            this queue is empty.
     */
    virtual E* poll(void) override{
      return static_cast<E*>(this->ArrayQueuePrototype::pollPointer());
    }

    /**
     * @brief Retrieves and removes the head of this queue, or returns null if this queue 
     *        is empty.
     * 
     * @return E* the head of this queue, or null if this queue is empty.
     */
    virtual E* peek(void) override{
      return static_cast<E*>(this->ArrayQueuePrototype::peekPointer());
    }
  
  /* **************************************************************************************
   * Public Method <Override> - mcuf::Iterable<E>
   */
  public:

    /**
     * @brief Performs the given action for each element of the Iterable until all 
     *        elements have been processed or the action throws an exception. Unless 
     *        otherwise specified by the implementing class, actions are performed in the 
     *        order of iteration (if an iteration order is specified). 
     * 
     * @param attachment user data.
     * @param action action The action to be performed for each element.
     */
    virtual void forEach(void* attachment, mcuf::BiConsumer<E*, void*>& action) const override{
      this->foreachPrototype(attachment, reinterpret_cast<mcuf::BiConsumer<void*, void*>&>(action));
    }
  
  /* **************************************************************************************
   * Public Method <Override> - mcuf::Collection<E>
   */  
  public:

    /**
     * @brief Removes all of the elements from this collection. The collection will be 
     *        empty after this method returns.
     * 
     */
    virtual void clear(void) override{
      return this->ArrayQueuePrototype::clear();
    }

    /**
     * @brief Returns true if this collection contains no elements.
     * 
     * @return true if this collection contains no elements
     * @return false 
     */
    virtual bool isEmpty(void) const override{
      return this->ArrayQueuePrototype::isEmpty();
    }
    
    /**
     * @brief Returns the number of elements in this collection.
     * 
     * @return uint32_t the number of elements in this collection.
     */
    virtual int size(void) const override{
      return this->ArrayQueuePrototype::size();
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

#endif /* MCUF_EABFB0E9_4CE7_4009_A990_B20F60799B41 */
