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
#include "mcuf/lang/Interface.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */

namespace hal{
  namespace analog{
    interface AnalogInputPortControl;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::analog::AnalogInputPortControl extends virtual mcuf::lang::Interface{

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

#endif /* MCUF_DF7E59DB_F968_49E3_A7B7_7304120298F4 */
