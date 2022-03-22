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
#include "mcuf/hal/Base.h"
#include "mcuf/hal/general/port/GeneralPortControl.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    namespace general{
      namespace port{
        interface GeneralPort;
      }
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::general::port::GeneralPort extends mcuf::hal::Base, 
  mcuf::hal::general::port::GeneralPortControl{

  /* **************************************************************************************
   * Method 
   */

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_DA8BBDE6_3AFE_4070_945C_08F9966A0B20 */
