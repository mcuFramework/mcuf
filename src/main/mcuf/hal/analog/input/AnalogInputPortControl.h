/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_DF7E59DB_F968_49E3_A7B7_7304120298F4
#define MCUF_DF7E59DB_F968_49E3_A7B7_7304120298F4

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  namespace hal{
    namespace analog{
      namespace input{
        interface AnalogInputPortControl;
      }
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::analog::input::AnalogInputPortControl{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @param pin 
   * @return uint32_t 
   */
  virtual uint32_t convert(uint32_t pin) abstract;

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

#endif/* MCUF_DF7E59DB_F968_49E3_A7B7_7304120298F4 */
