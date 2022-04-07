/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_D2C77331_580F_474B_BC99_EABAF6FEF1A9
#define MCUF_D2C77331_580F_474B_BC99_EABAF6FEF1A9

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/io/ByteBuffer.h"
#include "hal/serial/SerialPortStatus.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
  namespace serial{
    interface SerialPortEvent;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::serial::SerialPortEvent{
  
  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @param status handle status
   * @param result 0 = successful, other = remaining byte count.
   * @param attachment user data
   */
  virtual void onSerialPortEvent(hal::serial::SerialPortStatus status, 
                                 int result,
                                 void* attachment) abstract;
  
};

#endif /* MCUF_D2C77331_580F_474B_BC99_EABAF6FEF1A9 */
