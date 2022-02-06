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
#include "mcuf_base.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    interface GeneralPinConfig;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::GeneralPinConfig{
  
  /* **************************************************************************************
   * Enum PinMode
   */
  enum PinMode{
    PINMODE_NOT_SUPPORT,
    PINMODE_PUSH_PULL,
    PINMODE_PULL_UP,
    PINMODE_PULL_DOWN,
    PINMODE_OPEN_DRAIN,
  };
   
  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @return PinMode 
   */
  virtual PinMode pinMode(void) abstract;

  /**
   * @brief 
   * 
   * @param mode 
   * @return true 
   * @return false 
   */
  virtual bool pinMode(PinMode mode) abstract; 

};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_A6C99BE5_AB26_4FEE_B210_6549D41C6EDF */
