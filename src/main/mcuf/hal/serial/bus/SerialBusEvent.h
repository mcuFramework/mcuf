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
#include "mcuf/io/ByteBuffer.h"
#include "mcuf/hal/serial/bus/SerialBusStatus.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    namespace serial{
      namespace bus{
        interface SerialBusEvent;
      }
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::serial::bus::SerialBusEvent{

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
  virtual void onSerialBusEvent(mcuf::hal::serial::bus::SerialBusStatus status, 
                                int result,
                                void* attachment) abstract;
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_F948F450_E9C5_4979_8B11_1563B5BE65F6 */
