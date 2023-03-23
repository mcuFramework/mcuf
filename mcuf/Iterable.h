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

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./../func/Consumer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  template<typename E> interface Iterable;
}



/* ****************************************************************************************
 * Class/Interface/Struct
 */  
template<typename E>
interface mcuf::Iterable extends virtual mcuf::Interface{
  
  /* **************************************************************************************
   * Method
   */

  /**
   * @brief Performs the given action for each element of the Iterable until all elements 
   *        have been processed or the action throws an exception. Unless otherwise 
   *        specified by the implementing class, actions are performed in the order of 
   *        iteration (if an iteration order is specified).
   * 
   * @param attachment User data.
   * @param action The action to be performed for each element.
   */
  virtual void forEach(func::Consumer<E*>& accept) const abstract;

};
 


/* *****************************************************************************************
 *  End of file
 */ 


#endif /* MCUF_B2C3BB85_C758_49A3_B664_9831792BF3F1 */
