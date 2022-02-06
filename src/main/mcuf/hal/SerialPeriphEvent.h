/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_B4701C5A_F9C9_4C60_AF27_09CD2013EE9A
#define MCUF_B4701C5A_F9C9_4C60_AF27_09CD2013EE9A

/* ****************************************************************************************
 * Include
 */
#include "mcuf_base.h"
#include "mcuf/io/ByteBuffer.h"
#include "mcuf/hal/SerialPeriphStatus.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    interface SerialPeriphEvent;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::SerialPeriphEvent{
  /* **************************************************************************************
   * Subclass
   */
  
  /* **************************************************************************************
   * Method
   */  
  
  virtual void onSerialPeriphEvent(mcuf::hal::SerialPeriphStatus status, 
                                   mcuf::io::ByteBuffer* transfer,
                                   mcuf::io::ByteBuffer* receiver) abstract;
};


/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_B4701C5A_F9C9_4C60_AF27_09CD2013EE9A */
