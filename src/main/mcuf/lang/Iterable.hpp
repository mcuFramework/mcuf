/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_B2C3BB85_C758_49A3_B664_9831792BF3F1
#define MCUF_B2C3BB85_C758_49A3_B664_9831792BF3F1

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/lang/Object.hpp"
#include "mcuf/function/Consumer.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    template<typename E> interface Iterable;
  }
}



/* ****************************************************************************************
 * Class Iterable
 */  
template<typename E>
interface mcuf::lang::Iterable{
  
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
   * Performs the given action for each element of the Iterable until all elements have 
   * been processed or the action throws an exception. Unless otherwise specified by the 
   * implementing class, actions are performed in the order of iteration (if an iteration 
   * order is specified). 
   *
   * @action - The action to be performed for each element.
   */
  virtual void forEach(mcuf::function::Consumer<E*>& action) abstract;

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
 *  End of file
 */ 


#endif/* MCUF_B2C3BB85_C758_49A3_B664_9831792BF3F1 */
