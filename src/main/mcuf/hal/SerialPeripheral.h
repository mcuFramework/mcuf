/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_E0DBA665_1EF1_4ECC_BF90_B467759500E6
#define MCUF_E0DBA665_1EF1_4ECC_BF90_B467759500E6

/* ****************************************************************************************
 * Include
 */
#include "mcuf_base.h"
#include "mcuf/hal/Base.h"
#include "mcuf/io/channel/ByteBuffer.h"
#include "mcuf/lang/Pointer.h"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    interface SerialPeripheral;
  }
}



/* ****************************************************************************************
 * Interface SerialPeripheral
 */  
interface mcuf::hal::SerialPeripheral implement mcuf::hal::Base{

  /* **************************************************************************************
   * Subclass
   */
  interface Event;

  /* **************************************************************************************
   * Enum Polarity
   */
  enum Polarity{
    ACTIVE_HIGH = 0x0U,
    ACTIVE_LOW = 0x1U
  };

  /* **************************************************************************************
   * Enum Phase
   */
  enum Phase{
    FIRST_EDGE = 0x0U,
    SECOND_EDGE = 0x1U
  };

  /* **************************************************************************************
   * Method
   */
   
  /**
   *
   */
  virtual bool abort(void) abstract;
  
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
  virtual bool isBusy(void) abstract;

  /**
   * 
   */
  virtual bool lsb(void) abstract;

  /**
   * 
   */
  virtual bool lsb(bool enable) abstract;

  /**
   * 
   */
  virtual Phase phase(void) abstract;

  /**
   * 
   */
  virtual bool phase(Phase set) abstract;

  /**
   * 
   */
  virtual Polarity polarity(void) abstract;

  /**
   * 
   */
  virtual bool polarity(Polarity set) abstract;

  /**
   * 
   */
  virtual bool transfer(mcuf::io::channel::ByteBuffer* transfer,
                        mcuf::io::channel::ByteBuffer* receiver,
                        Event* event) abstract;

};

/* ****************************************************************************************
 * Interface SerialPeripheral::Event
 */  
interface mcuf::hal::SerialPeripheral::Event{
  /* **************************************************************************************
   * Subclass
   */
  enum Status{
    SUCCESSFUL,
    FAIL,
    ABORT,
  };
  
  /* **************************************************************************************
   * Method
   */  
  
  virtual void onSerialPeripheralEvent(Status status, 
                                       mcuf::io::channel::ByteBuffer* transfer,
                                       mcuf::io::channel::ByteBuffer* receiver) abstract;
};




/* *****************************************************************************************
 * End of file
 */ 


#endif/* MCUF_E0DBA665_1EF1_4ECC_BF90_B467759500E6 */
