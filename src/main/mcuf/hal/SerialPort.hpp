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
#include "mcuf\hal\Base.hpp"
#include "mcuf\io\channel\ByteBuffer.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    interface SerialPort;
  }
}



/* ****************************************************************************************
 * Interface SerialPort
 */  
interface mcuf::hal::SerialPort implement mcuf::hal::Base{
        
  /* **************************************************************************************
   * Subclass
   */
  interface Event;

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
  virtual bool read(mcuf::io::channel::ByteBuffer& byteBuffer, 
                    Event* event) abstract;

  /**
   * 
   */
  virtual bool write(mcuf::io::channel::ByteBuffer& byteBuffer, 
                     Event* event) abstract;
  
};

/* ****************************************************************************************
 * Interface SerialPort::Event
 */  
interface mcuf::hal::SerialPort::Event{

  
  /* **************************************************************************************
   * Subclass
   */
  enum Status{
    TXD_SUCCESSFUL,
    TXD_ABORT,
    TXD_FAIL,
    RXD_SUCCESSFUL,
    RXD_ABORT,
    RXD_FAIL,
  };
  
  /* **************************************************************************************
   * Method
   */

  /**
   * 
   */
  virtual void onSerialPortEvent(Status event, mcuf::io::channel::ByteBuffer& byteBuffer) abstract;
  
};


/* *****************************************************************************************
 * End of file
 */ 


#endif/* MCUF_A805502A_41D9_45B8_A89A_B11ED86A2F19 */
