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
#include "mcuf_base.h"
#include "hal/Base.h"
#include "hal/serial/SerialBusControl.h"
#include "hal/serial/SerialBusTransfer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace hal{
  namespace serial{
    interface SerialBus;
  }
}

/* ****************************************************************************************
 * Interface/Class/Struct
 */  
interface hal::serial::SerialBus extends hal::Base,
  hal::serial::SerialBusControl,
  hal::serial::SerialBusTransfer{

  /* **************************************************************************************
   * Method
   */

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_BE431D3A_03AC_4CF4_85C2_68C442B30474 */
