/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_DA8BBDE6_3AFE_4070_945C_08F9966A0B20
#define MCUF_DA8BBDE6_3AFE_4070_945C_08F9966A0B20

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/hal/base.h"
#include "mcuf/hal/GeneralPortControl.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    interface GeneralPort;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::GeneralPort extends mcuf::hal::Base, 
  mcuf::hal::GeneralPortControl{

  /* **************************************************************************************
   * Method 
   */

};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_DA8BBDE6_3AFE_4070_945C_08F9966A0B20 */
