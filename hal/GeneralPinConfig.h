/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_A6C99BE5_AB26_4FEE_B210_6549D41C6EDF
#define MCUF_A6C99BE5_AB26_4FEE_B210_6549D41C6EDF

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/lang/Interface.h"

//-----------------------------------------------------------------------------------------
#include "hal/GeneralPinMode.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
  namespace general{
    interface GeneralPinConfig;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::general::GeneralPinConfig extends virtual mcuf::lang::Interface{
  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @return PinMode 
   */
  virtual hal::general::GeneralPinMode pinMode(void) abstract;

  /**
   * @brief 
   * 
   * @param mode 
   * @return true 
   * @return false 
   */
  virtual bool pinMode(hal::general::GeneralPinMode mode) abstract; 

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_A6C99BE5_AB26_4FEE_B210_6549D41C6EDF */
