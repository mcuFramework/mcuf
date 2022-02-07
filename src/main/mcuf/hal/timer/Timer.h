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
#include "mcuf_base.h"
#include "mcuf/hal/Base.h"
#include "mcuf/hal/timer/TimerControl.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{  
    namespace timer{
      interface Timer;
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::timer::Timer extends mcuf::hal::Base,
  mcuf::hal::timer::TimerControl{

  /* **************************************************************************************
   * Method
   */

};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_AD0B942D_EE2D_4080_BDAD_3E9AACE341DA */
