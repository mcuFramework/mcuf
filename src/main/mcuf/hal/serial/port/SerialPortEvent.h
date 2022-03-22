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
#include "mcuf/hal/serial/port/SerialPortStatus.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    namespace serial{
      namespace port{
        interface SerialPortEvent;
      }
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::serial::port::SerialPortEvent{
  
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
  virtual void onSerialPortEvent(mcuf::hal::serial::port::SerialPortStatus status, 
                                 int result,
                                 void* attachment) abstract;
  
};

#endif /* MCUF_D2C77331_580F_474B_BC99_EABAF6FEF1A9 */
