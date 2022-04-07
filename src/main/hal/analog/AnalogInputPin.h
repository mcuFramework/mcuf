/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_B16985A9_A63C_403C_9D7B_5B3BB7B33CFA
#define MCUF_B16985A9_A63C_403C_9D7B_5B3BB7B33CFA

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "hal/Base.h"

/* ****************************************************************************************
 * Namespace
 */

namespace hal{
  namespace analog{
    interface AnalogInputPin;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::analog::AnalogInputPin{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @return uint32_t 
   */
  virtual uint32_t convert(void) abstract;

  /**
   * @brief Get the adc convert bit.
   * 
   * @return uint32_t 
   */
  virtual uint32_t getConvertBit(void) abstract;
};  

/* *****************************************************************************************
 * End of file
 */

#endif /* MCUF_B16985A9_A63C_403C_9D7B_5B3BB7B33CFA */