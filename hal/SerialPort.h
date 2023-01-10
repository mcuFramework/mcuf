/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_A805502A_41D9_45B8_A89A_B11ED86A2F19
#define MCUF_A805502A_41D9_45B8_A89A_B11ED86A2F19

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf/mcuf_base.h"

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "mcuf/hal/Base.h"
#include "mcuf/hal/SerialPortConfig.h"
#include "mcuf/hal/SerialPortTransfer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf::hal{
  interface SerialPort;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::SerialPort extends 
mcuf::hal::Base,
mcuf::hal::SerialPortConfig,
mcuf::hal::SerialPortTransfer{

  /* **************************************************************************************
   * Method
   */
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_A805502A_41D9_45B8_A89A_B11ED86A2F19 */
