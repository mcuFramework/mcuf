/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_BE431D3A_03AC_4CF4_85C2_68C442B30474
#define MCUF_BE431D3A_03AC_4CF4_85C2_68C442B30474

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
    interface SerialBus;
    interface SerialBusEvent;
  }
}



/* ****************************************************************************************
 * Interface SerialBus
 */  
interface mcuf::hal::SerialBus implement mcuf::hal::Base{

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
  virtual uint8_t address(void) abstract;
  
  /**
   *
   */
  virtual bool address(uint8_t address) abstract;
  
  /**
   * 
   */
  virtual uint32_t clockRate(void) abstract;

  /**
   * 
   */
  virtual uint32_t clockRate(uint32_t clock) abstract;

  /**
   * 
   */
  virtual void read(mcuf::io::ByteBuffer* receiver, Event* event) abstract;

  /**
   * 
   */
  virtual void write(mcuf::io::ByteBuffer* transfer, Event* event) abstract;
  
  /**
   *
   */
  virtual bool writeAfterRead(mcuf::io::ByteBuffer* transfer, 
                              mcuf::io::ByteBuffer* receiver,
                              SerialBusEvent* event) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 


#endif/* MCUF_BE431D3A_03AC_4CF4_85C2_68C442B30474 */
