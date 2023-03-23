/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_BCEF8EF1_8E8F_4C7F_B575_41D3DEE77164
#define MCUF_BCEF8EF1_8E8F_4C7F_B575_41D3DEE77164

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "../mcuf/package-info.h"

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./GeneralInput.h"
#include "./GeneralOutput.h"
#include "./GeneralPinMode.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
  interface GeneralPin;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::GeneralPin extends hal::GeneralOutput,
    hal::GeneralInput{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @return PinMode 
   */
  virtual hal::GeneralPinMode getPinMode(void) abstract;

  /**
   * @brief Set the Pin Mode object
   * 
   * @param mode 
   * @return hal::GeneralPinMode 返回設定模式
   */
  virtual hal::GeneralPinMode setPinMode(hal::GeneralPinMode mode) abstract; 

  /**
   * @brief  Get io direction.
   * 
   * @return true output
   * @return false input
   */
  virtual bool getDir(void) abstract;
  
  /**
   * @brief Set io direction.
   * 
   * @param dir false = input, true = output.
   */
  virtual void setDir(bool dir) abstract;

  /**
   * @brief Set the Input object
   * 
   */
  virtual void setInput(void) abstract;

  /**
   * @brief Set the Output object
   * 
   */
  virtual void setOutput(void) abstract;
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_BCEF8EF1_8E8F_4C7F_B575_41D3DEE77164 */
