/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_B4E61D80_F9A1_469D_84FD_FBB3D8FC11E4
#define MCUF_B4E61D80_F9A1_469D_84FD_FBB3D8FC11E4

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/lang/Iterable.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    template<typename T> interface Collection;
  }
}



/* ****************************************************************************************
 * Class Collection
 */  
template<typename T>
interface mcuf::util::Collection extends mcuf::lang::Iterable<T>{
  
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
   * Removes all of the elements from this collection. The collection will be empty after 
   * this method returns.
   */
  virtual void clear(void) abstract;

  /**
   * Returns true if this collection contains no elements.
   * 
   * @return true if this collection contains no elements.
   */
  virtual bool isEmpty(void) abstract;

  /**
   * Returns the number of elements in this collection.
   * 
   * @return the number of elements in this collection.
   */
  virtual uint32_t size(void) abstract;

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


#endif/* MCUF_B4E61D80_F9A1_469D_84FD_FBB3D8FC11E4 */
