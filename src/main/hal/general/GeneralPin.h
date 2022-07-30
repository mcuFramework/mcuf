/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_BCEF8EF1_8E8F_4C7F_B575_41D3DEE77164
#define MCUF_BCEF8EF1_8E8F_4C7F_B575_41D3DEE77164

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "hal/general/GeneralPinControl.h"
#include "hal/general/GeneralPinConfig.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
  namespace general{
    interface GeneralPin;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::general::GeneralPin extends 
hal::general::GeneralPinConfig,
hal::general::GeneralPinControl{


  /* **************************************************************************************
   * Method
   */

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_BCEF8EF1_8E8F_4C7F_B575_41D3DEE77164 */
