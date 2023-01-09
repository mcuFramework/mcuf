/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_AD0B942D_EE2D_4080_BDAD_3E9AACE341DA
#define MCUF_AD0B942D_EE2D_4080_BDAD_3E9AACE341DA

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "hal/Base.h"
#include "hal/TimerControl.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
  interface Timer;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::Timer extends 
hal::Base,
hal::TimerControl{

  /* **************************************************************************************
   * Method
   */

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_AD0B942D_EE2D_4080_BDAD_3E9AACE341DA */
