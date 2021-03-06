/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_EFF1A157_A291_4313_A742_99FB124D0B71
#define MCUF_EFF1A157_A291_4313_A742_99FB124D0B71

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "hal/Base.h"
#include "hal/general/EdgeTriggerControl.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
  namespace general{
    interface EdgeTrigger;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::general::EdgeTrigger extends 
hal::Base,
hal::general::EdgeTriggerControl{
  /* **************************************************************************************
   * Method
   */

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_EFF1A157_A291_4313_A742_99FB124D0B71 */
