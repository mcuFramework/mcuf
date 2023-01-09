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

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "hal/Base.h"
#include "hal/GeneralPortControl.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
  interface GeneralPort;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::GeneralPort extends 
hal::Base, 
hal::GeneralPortControl{
  /* **************************************************************************************
   * Method 
   */

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_DA8BBDE6_3AFE_4070_945C_08F9966A0B20 */
