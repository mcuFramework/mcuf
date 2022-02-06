/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_BBCC216D_3F3B_4465_9579_6960281585E8
#define MCUF_BBCC216D_3F3B_4465_9579_6960281585E8

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/hal/Base.h"
#include "mcuf/hal/PulseWidthConfig.h"
#include "mcuf/hal/PulseWidthControl.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    interface PulseWidth;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::PulseWidth extends mcuf::hal::Base,
  mcuf::hal::PulseWidthConfig,
  mcuf::hal::PulseWidthControl{

  /* **************************************************************************************
   * Method
   */
   
};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_BBCC216D_3F3B_4465_9579_6960281585E8 */
