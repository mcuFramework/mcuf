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
#include "mcuf\Collection.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  template<typename E> interface Queue;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
template<typename E>
interface mcuf::Queue extends mcuf::Collection<E>{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief Inserts the specified element into this queue if it is possible to do so 
   *        immediately without violating capacity restrictions.
   * 
   * @param e the element to add.
   * @return true the element was added to this queue
   * @return false 
   */
  virtual bool offer(E* e) abstract;

  /**
   * @brief Retrieves, but does not remove, the head of this queue, or returns null if 
   *        this queue is empty.
   * 
   * @return E* 
   */
  virtual E* poll(void) abstract;

  /**
   * @brief Retrieves and removes the head of this queue, or returns null if this queue 
   *        is empty.
   * 
   * @return E* the head of this queue, or null if this queue is empty.
   */
  virtual E* peek(void) abstract;
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_BFC82B3D_EF2A_4C50_AC22_04B947DCE669 */
