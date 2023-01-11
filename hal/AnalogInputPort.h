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
#include "../mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "./Base.h"
#include "./AnalogInputPortControl.h"

/* ****************************************************************************************
 * Namespace
 */

namespace mcuf::hal{
  interface AnalogInputPort;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::AnalogInputPort extends 
mcuf::hal::Base,
mcuf::hal::AnalogInputPortControl{

  /* **************************************************************************************
   * Method
   */
  
};  

/* *****************************************************************************************
 * End of file
 */

#endif /* MCUF_C04F29D8_8794_4EA6_A3AD_CFBD1C61458B */
