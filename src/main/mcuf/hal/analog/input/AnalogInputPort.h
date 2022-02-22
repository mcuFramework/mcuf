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
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/hal/Base.h"
#include "mcuf/hal/analog/input/AnalogInputPortConfig.h"
#include "mcuf/hal/analog/input/AnalogInputPortControl.h"

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  namespace hal{
    namespace analog{
      namespace input{
        interface AnalogInputPort;
      }
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::analog::input::AnalogInputPort extends mcuf::hal::Base,
  mcuf::hal::analog::input::AnalogInputPortConfig,
  mcuf::hal::analog::input::AnalogInputPortControl{

  /* **************************************************************************************
   * Method
   */
  
};  

/* *****************************************************************************************
 * End of file
 */

#endif/* MCUF_C04F29D8_8794_4EA6_A3AD_CFBD1C61458B */
