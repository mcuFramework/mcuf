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
#include "../mcuf/mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "../mcuf/Interface.h"

//-----------------------------------------------------------------------------------------
#include "./GeneralPinMode.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace mcuf::hal{
  interface GeneralPinConfig;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::GeneralPinConfig extends virtual mcuf::Interface{
  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @return PinMode 
   */
  virtual mcuf::hal::GeneralPinMode pinMode(void) abstract;

  /**
   * @brief 
   * 
   * @param mode 
   * @return true 
   * @return false 
   */
  virtual bool pinMode(mcuf::hal::GeneralPinMode mode) abstract; 

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_A6C99BE5_AB26_4FEE_B210_6549D41C6EDF */
