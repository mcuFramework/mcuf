/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_F948F450_E9C5_4979_8B11_1563B5BE65F6
#define MCUF_F948F450_E9C5_4979_8B11_1563B5BE65F6

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf\hal\Base.h"
#include "mcuf\io\ByteBuffer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    interface SerialBusEvent;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::SerialBusEvent{
  
  /* **************************************************************************************
   * Enum SerialBusStatus
   */
  enum SerialBusStatus{
    HAL_SERIALBUS_WRITE_SUCCESSFUL,
    HAL_SERIALBUS_WRITE_FAIL,
    HAL_SERIALBUS_READ_SUCCESSFUL,
    HAL_SERIALBUS_READ_FAIL, 
  };

  /* **************************************************************************************
   * Method
   */
  
  /**
   *
   */
  virtual void onSerialBusEvent(SerialBusStatus status, mcuf::io::ByteBuffer* byteBuffer) abstract;
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_F948F450_E9C5_4979_8B11_1563B5BE65F6 */
