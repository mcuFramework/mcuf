/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_C2D460EF_C652_487A_AC15_A26DDF6BC123
#define MCUF_C2D460EF_C652_487A_AC15_A26DDF6BC123

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/io/channel/ByteBuffer.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    interface SerialPortEvent;
  }
}

/* ****************************************************************************************
 * Interface Object
 */  
interface mcuf::hal::SerialPortEvent{

  /* **************************************************************************************
   * Subclass
   */
  enum Event{
    EVENT_SERIAL_PORT_TXD_SUCCESSFUL,
    EVENT_SERIAL_PORT_TXD_FAIL,
    EVENT_SERIAL_PORT_RXD_SUCCESSFUL,
    EVENT_SERIAL_PORT_RXD_FAIL,
  };

  /* **************************************************************************************
   * Method
   */

  /**
   * 
   */
  virtual void onSerialPortEvent(Event event, 
                                 mcuf::io::channel::ByteBuffer& byteBuffer) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_C2D460EF_C652_487A_AC15_A26DDF6BC123 */
