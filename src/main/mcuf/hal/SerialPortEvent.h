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

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{  
    interface SerialPortEvent;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::SerialPortEvent{

  /* **************************************************************************************
   * Subclass
   */
  enum SerialPortStatus{
    HAL_SERIALPORT_WRITE_SUCCESSFUL,
    HAL_SERIALPORT_WRITE_FAIL,
    HAL_SERIALPORT_WRITE_ABROT,
    HAL_SERIALPORT_READ_SUCCESSFUL,
    HAL_SERIALPORT_READ_FAIL,
    HAL_SERIALPORT_READ_ABROT,    
  };
  
  /* **************************************************************************************
   * Method
   */

  /**
   * 
   */
  virtual void onSerialPortEvent(SerialPortStatus status, mcuf::io::ByteBuffer* byteBuffer) abstract;
  
};

#endif/* MCUF_D2C77331_580F_474B_BC99_EABAF6FEF1A9 */
