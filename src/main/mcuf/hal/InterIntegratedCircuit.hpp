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
#include "mcuf\hal\Base.hpp"
#include "mcuf\io\channel\ByteBuffer.hpp"
#include "mcuf\io\channel\CompletionHandler.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    interface InterIntegratedCircuit;
  }
}



/* ****************************************************************************************
 * Interface InterIntegratedCircuit
 */  
interface mcuf::hal::InterIntegratedCircuit implement mcuf::hal::Base{

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
  virtual void read(mcuf::io::channel::ByteBuffer* receiver, Event* event) abstract;

  /**
   * 
   */
  virtual void write(mcuf::io::channel::ByteBuffer* transfer, Event* event) abstract;
  
  /**
   *
   */
  virtual bool writeAfterRead(mcuf::io::channel::ByteBuffer* transfer, 
                              mcuf::io::channel::ByteBuffer* receiver,
                              Event* event) abstract;

};



/* ****************************************************************************************
 * Interface InterIntegratedCircuit::Event
 */  
interface mcuf::hal::InterIntegratedCircuit::Event{
  /* **************************************************************************************
   * Subclass
   */
  enum Status{
    WRITE_SUCCESSFUL,
    WRITE_FAIL,
    READ_SUCCESSFUL,
    READ_FAIL, 
  };

  /* **************************************************************************************
   * Method
   */
  
  /**
   *
   */
  virtual void onInterIntegratedCircuitEvent(Status status, mcuf::io::channel::ByteBuffer* byteBuffer) abstract;
  
};


/* *****************************************************************************************
 * End of file
 */ 


#endif/* MCUF_BE431D3A_03AC_4CF4_85C2_68C442B30474 */
