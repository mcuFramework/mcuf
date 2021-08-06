/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_CC6CB359_4B0D_4114_BFAB_B1FAC5E13DF6
#define MCUF_CC6CB359_4B0D_4114_BFAB_B1FAC5E13DF6

/* ****************************************************************************************
 * Include
 */  
#include "Queue.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    template<typename E> class FixedQueue;
  }
}



/* ****************************************************************************************
 * Class Queue
 */  
template<typename E>
class mcuf::util::FixedQueue: 
      public mcuf::util::Queue<E>{
  
  /* **************************************************************************************
   * Subclass
   */
  
  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */
  protected: E* element;
  protected: uint32_t max;
  protected: uint32_t start;
  protected: uint32_t end;
  protected: bool empty;


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
  public: FixedQueue(mcuf::lang::Memory& memory):
          Queue<E>(){

    this->element = (E*)memory.pointer();
    this->max = (memory.length() / sizeof(E));
    this->start = 0;
    this->end = 0;
    this->empty = true;
    return;
  }

  /**
   * Disconstruct.
   */
  public: virtual ~FixedQueue() = default;

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
   * Inserts the specified element into this queue if it is possible to do so immediately 
   * without violating capacity restrictions.
   * 
   * @e the element to add.
   * @return true if the element was added to this queue, else false.
   */
  public: virtual bool offer(E e){
    if(this->isFull())
      return false;
    
    this->empty = false;
    this->element[this->end++] = e;

    if(this->end >= this->max)
      this->end = 0;

    return true;
  };

  /**
   * Retrieves, but does not remove, the head of this queue, or returns null if this queue 
   * is empty.
   * @return Retrieves, but does not remove, the head of this queue, or returns null if 
   *         this queue is empty.
   */
  public: virtual E poll(void){
    if(this->empty)
      return this->element[0];
    
    E* result = &this->element[this->start];

    ++this->start;
    if(this->start >= this->max)
      this->start = 0;
    
    if(this->start == this->end)
      this->empty = true;

    return *result;
  }

  /**
   * Retrieves and removes the head of this queue, or returns null if this queue is empty.
   * 
   * @return he head of this queue, or null if this queue is empty.
   */
  public: virtual E peek(void){
    return this->element[this->start];
  }

  /**
   * Removes all of the elements from this collection. The collection will be empty after 
   * this method returns.
   */
  public: virtual void clear(void){
    this->start = 0;
    this->end = 0;
    this->empty = true;
  }

  /**
   * Returns true if this collection contains no elements.
   * 
   * @return true if this collection contains no elements.
   */
  public: virtual bool isEmpty(void){
    return this->empty;
  };

  /**
   * Returns the number of elements in this collection.
   * 
   * @return the number of elements in this collection.
   */
  public: virtual uint32_t size(void){
    if(empty)
      return 0;
    
    if(this->isFull())
      return this->max;

    if(this->end > this->start)
      return this->end - this->start;
    else
      return (this->max - this->start) + this->end;
  }

  /* **************************************************************************************
   * Public Method
   */

  public: bool isFull(void){
    return ((this->start == this->end) == !this->empty);
  }

  public: uint32_t length(void){
    return this->max;
  }

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


#endif/* MCUF_CC6CB359_4B0D_4114_BFAB_B1FAC5E13DF6 */
