/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_BFC82B3D_EF2A_4C50_AC22_04B947DCE669
#define MCUF_BFC82B3D_EF2A_4C50_AC22_04B947DCE669

/* ****************************************************************************************
 * Include
 */  
#include "Collection.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    template<typename E> class Queue;
  }
}



/* ****************************************************************************************
 * Class Queue
 */  
template<typename E>
class mcuf::util::Queue: 
      public mcuf::util::Collection<E>{
  
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

  /**
   * Inserts the specified element into this queue if it is possible to do so immediately 
   * without violating capacity restrictions.
   * 
   * @param e the element to add.
   * @return true if the element was added to this queue, else false.
   */
  public: virtual bool offer(E e) = 0;

  /**
   * Retrieves, but does not remove, the head of this queue, or returns null if this queue 
   * is empty.
   * 
   * @return Retrieves, but does not remove, the head of this queue, or returns null if 
   *         this queue is empty.
   */
  public: virtual E poll(void) = 0;

  /**
   * Retrieves and removes the head of this queue, or returns null if this queue is empty.
   * 
   * @return he head of this queue, or null if this queue is empty.
   */
  public: virtual E peek(void) = 0;

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  
  /**
   * Construct.
   */
  public: Queue(void):
          Collection<E>(){
    return;
  }

  /**
   * Disconstruct.
   */
  public: ~Queue(){
    return;
  }

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


#endif/* MCUF_BFC82B3D_EF2A_4C50_AC22_04B947DCE669 */
