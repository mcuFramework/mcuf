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
#include "mcuf\hal\Base.h"
#include "mcuf\io\ByteBuffer.h"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    interface SerialPort;
    interface SerialPortEvent;
  }
}



/* ****************************************************************************************
 * Interface SerialPort
 */  
interface mcuf::hal::SerialPort implement mcuf::hal::Base{

  /* **************************************************************************************
   * Method
   */

  /**
   * 
   */
  virtual bool abortRead(void) abstract;

  /**
   * 
   */
  virtual bool abortWrite(void) abstract;

  /**
   * 
   */
  virtual uint32_t baudrate(void) abstract;

  /**
   * 
   */
  virtual uint32_t baudrate(uint32_t rate) abstract;

  /**
   *
   */
  virtual bool readBusy(void) abstract;

  /**
   *
   */
  virtual bool writeBusy(void) abstract;

  /**
   * 
   */
  virtual bool read(mcuf::io::ByteBuffer* byteBuffer, SerialPortEvent* event) abstract;

  /**
   * 
   */
  virtual bool write(mcuf::io::ByteBuffer* byteBuffer, SerialPortEvent* event) abstract;
  
};

/* *****************************************************************************************
 * End of file
 */ 


#endif/* MCUF_A805502A_41D9_45B8_A89A_B11ED86A2F19 */
