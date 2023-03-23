/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_C04F29D8_8794_4EA6_A3AD_CFBD1C61458B
#define MCUF_C04F29D8_8794_4EA6_A3AD_CFBD1C61458B

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "../mcuf/package-info.h"

//-----------------------------------------------------------------------------------------
#include "./Base.h"

/* ****************************************************************************************
 * Namespace
 */

namespace hal{
  interface AnalogInputPort;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::AnalogInputPort extends hal::Base{

  /* **************************************************************************************
   * Method
   */
  /**
   * @brief 
   * 
   * @param pin 
   * @return uint32_t 
   */
  virtual uint32_t read(int channel) abstract;

  /**
   * @brief Get the adc convert bit.
   * 
   * @return uint32_t 
   */
  virtual uint32_t getConvertLevel(void) abstract;
};  

/* *****************************************************************************************
 * End of file
 */

#endif /* MCUF_C04F29D8_8794_4EA6_A3AD_CFBD1C61458B */
