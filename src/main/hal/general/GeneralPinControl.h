/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_AD1E32C3_0942_4DB6_9C48_5D17FA9BFA04
#define MCUF_AD1E32C3_0942_4DB6_9C48_5D17FA9BFA04

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
  namespace general{
    interface GeneralPinControl;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::general::GeneralPinControl{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief  Get io direction.
   * 
   * @return true output
   * @return false input
   */
  virtual bool dir(void) abstract;

  /**
   * @brief Set io direction.
   * 
   * @param dir false = input, true = output.
   */
  virtual void dir(bool dir) abstract;

  /**
   * @brief Set the High object
   * 
   */
  virtual void setHigh(void) abstract;
  
  /**
   * @brief Set the Input object
   * 
   */
  virtual void setInput(void) abstract;

  /**
   * @brief Set the Low object
   * 
   */
  virtual void setLow(void) abstract;
  
  /**
   * @brief Set the Output object
   * 
   */
  virtual void setOutput(void) abstract;

  /**
   * @brief Set the Toggle object
   * 
   */
  virtual void setToggle(void) abstract;
  
  /**
   * @brief Get io pin.
   * 
   * @return true high
   * @return false low
   */
  virtual bool value(void) abstract;

  /**
   * @brief Set io pin to high or low.
   * 
   * @param level false = low, true = high.
   */
  virtual void value(bool level) abstract; 

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_AD1E32C3_0942_4DB6_9C48_5D17FA9BFA04 */
