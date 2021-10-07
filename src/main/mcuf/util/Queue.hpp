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

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"
#include "mcuf/util/Collection.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    template<typename E> interface Queue;
  }
}

/* ****************************************************************************************
 * Class Queue
 */  
template<typename E>
interface mcuf::util::Queue implement mcuf::util::Collection<E>{
  
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
  virtual bool offer(E e) abstract;

  /**
   * Retrieves, but does not remove, the head of this queue, or returns null if this queue 
   * is empty.
   * 
   * @return Retrieves, but does not remove, the head of this queue, or returns null if 
   *         this queue is empty.
   */
  virtual E poll(void) abstract;

  /**
   * Retrieves and removes the head of this queue, or returns null if this queue is empty.
   * 
   * @return he head of this queue, or null if this queue is empty.
   */
  virtual E peek(void) abstract;

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

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
