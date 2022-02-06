/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_A8489895_04E2_42AE_ABD9_E59CE721E05B
#define MCUF_A8489895_04E2_42AE_ABD9_E59CE721E05B

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/hal/Base.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    interface PulseWidthControl;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::PulseWidthControl{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief Set the Duty object
   * 
   * @param percent 
   * @return true 
   * @return false 
   */
  virtual bool setDuty(float percent) abstract;
   
  /**
   * @brief Set the Duty8 Bit object
   * 
   * @param duty 
   * @return true 
   * @return false 
   */
  virtual bool setDuty8Bit(uint8_t duty) abstract;

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool stop(void) abstract;
};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_A8489895_04E2_42AE_ABD9_E59CE721E05B */
