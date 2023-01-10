/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_BE431D3A_03AC_4CF4_85C2_68C442B30474
#define MCUF_BE431D3A_03AC_4CF4_85C2_68C442B30474

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf/mcuf_base.h"

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "mcuf/hal/Base.h"
#include "mcuf/hal/SerialBusControl.h"
#include "mcuf/hal/SerialBusTransfer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf::hal{
  interface SerialBus;
}

/* ****************************************************************************************
 * Interface/Class/Struct
 */  
interface mcuf::hal::SerialBus extends 
mcuf::hal::Base,
mcuf::hal::SerialBusControl,
mcuf::hal::SerialBusTransfer{

  /* **************************************************************************************
   * Method
   */

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_BE431D3A_03AC_4CF4_85C2_68C442B30474 */
