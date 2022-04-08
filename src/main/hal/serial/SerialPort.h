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
#include "mcuf_base.h"
#include "hal/Base.h"
#include "hal/serial/SerialPortConfig.h"
#include "hal/serial/SerialPortReceiver.h"
#include "hal/serial/SerialPortTransfer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace hal{
  namespace serial{
    interface SerialPort;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::serial::SerialPort extends hal::Base,
  hal::serial::SerialPortConfig,
  hal::serial::SerialPortTransfer,
  hal::serial::SerialPortReceiver{

  /* **************************************************************************************
   * Method
   */
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_A805502A_41D9_45B8_A89A_B11ED86A2F19 */
