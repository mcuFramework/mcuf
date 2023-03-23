/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_B0F0F032_A3B1_4BA1_B0A8_BB7F11C63CBD
#define MCUF_B0F0F032_A3B1_4BA1_B0A8_BB7F11C63CBD

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./Interface.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  template<typename E> interface Linked;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
template<typename E>
interface mcuf::Linked extends virtual mcuf::Interface{

  /* **************************************************************************************
   * Method
   */
   
  /**
   * @brief 
   * 
   * @param e 
   * @return true 
   * @return false 
   */
  virtual bool addLinked(E* e) abstract;

  /**
   * @brief 
   * 
   * @param e 
   * @return true 
   * @return false 
   */
  virtual bool insertLinked(E* e) abstract;

  /**
   * @brief Get the Next Linked object
   * 
   * @return E* 
   */
  virtual E* getNextLinked(void) abstract;

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool hasNextLinked(void) abstract;

  /**
   * @brief 
   * 
   * @return E* 
   */
  virtual E* removeLinked(void) abstract;

  /**
   * @brief 
   * 
   * @return E* 
   */
  virtual E* removeAllLinked(void) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_B0F0F032_A3B1_4BA1_B0A8_BB7F11C63CBD */
