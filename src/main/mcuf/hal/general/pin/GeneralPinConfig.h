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
#include "mcuf/hal/general/pin/GeneralPinMode.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    namespace general{
      namespace pin{
        interface GeneralPinConfig;
      }
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::general::pin::GeneralPinConfig{
   
  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @return PinMode 
   */
  virtual mcuf::hal::general::pin::GeneralPinMode pinMode(void) abstract;

  /**
   * @brief 
   * 
   * @param mode 
   * @return true 
   * @return false 
   */
  virtual bool pinMode(mcuf::hal::general::pin::GeneralPinMode mode) abstract; 

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_A6C99BE5_AB26_4FEE_B210_6549D41C6EDF */
