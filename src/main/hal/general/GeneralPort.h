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
#include "hal/Base.h"
#include "hal/general/GeneralPortControl.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
  namespace general{
    interface GeneralPort;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::general::GeneralPort extends hal::Base, 
hal::general::GeneralPortControl{
  /* **************************************************************************************
   * Method 
   */

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_DA8BBDE6_3AFE_4070_945C_08F9966A0B20 */
