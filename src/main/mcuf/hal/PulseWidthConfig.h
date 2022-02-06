/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_A6DB458A_C45C_42D0_9C57_E6D4E3E6ECAD
#define MCUF_A6DB458A_C45C_42D0_9C57_E6D4E3E6ECAD

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
    interface PulseWidthConfig;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::PulseWidthConfig{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief Set the Frequence object
   * 
   * @param hz 
   * @return true 
   * @return false 
   */
  virtual bool setBaseFrequence(uint32_t hz) abstract;

  /**
   * @brief Set the Base Second object
   * 
   * @param second 
   * @return true 
   * @return false 
   */
  virtual bool setBaseSecond(float second) abstract;
   
};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_A6DB458A_C45C_42D0_9C57_E6D4E3E6ECAD */
