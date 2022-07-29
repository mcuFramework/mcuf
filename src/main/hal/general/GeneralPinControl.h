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
#include "hal/general/GeneralInput.h"
#include "hal/general/GeneralOutput.h"

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
interface hal::general::GeneralPinControl extends 
hal::general::GeneralInput,
hal::general::GeneralOutput{

  /* **************************************************************************************
   * Method
   */
  using GeneralInput::value;
  using GeneralOutput::value;

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
   * @brief Set the Input object
   * 
   */
  virtual void setInput(void) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_AD1E32C3_0942_4DB6_9C48_5D17FA9BFA04 */
