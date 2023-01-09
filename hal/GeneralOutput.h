/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_F5896110_0162_406F_9ECE_A67699B0938F
#define MCUF_F5896110_0162_406F_9ECE_A67699B0938F

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/lang/Interface.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace hal{
  interface GeneralOutput;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface hal::GeneralOutput extends virtual mcuf::lang::Interface{
  /* **************************************************************************************
   * Method
   */

  /**
   * @brief Set the High object
   * 
   */
  virtual void setHigh(void) abstract;

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

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_F5896110_0162_406F_9ECE_A67699B0938F */
