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
#include "mcuf/hal/Base.h"
#include "mcuf/hal/serial/bus/SerialBusControl.h"
#include "mcuf/hal/serial/bus/SerialBusTransfer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    namespace serial{
      namespace bus{
        interface SerialBus;
      }
    }
  }
}

/* ****************************************************************************************
 * Interface/Class/Struct
 */  
interface mcuf::hal::serial::bus::SerialBus extends mcuf::hal::Base,
  mcuf::hal::serial::bus::SerialBusControl,
  mcuf::hal::serial::bus::SerialBusTransfer{

  /* **************************************************************************************
   * Method
   */

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_BE431D3A_03AC_4CF4_85C2_68C442B30474 */
