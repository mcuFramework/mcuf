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
#include "mcuf/hal/general/pin/GeneralPinControl.h"
#include "mcuf/hal/general/pin/GeneralPinConfig.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    namespace general{
      namespace pin{
        interface GeneralPin;
      }
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::general::pin::GeneralPin extends mcuf::hal::general::pin::GeneralPinConfig,
  mcuf::hal::general::pin::GeneralPinControl{

  /* **************************************************************************************
   * Method
   */

};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_BCEF8EF1_8E8F_4C7F_B575_41D3DEE77164 */
