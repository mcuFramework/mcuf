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
#include "mcuf/io/ByteBuffer.h"
#include "mcuf/lang/Pointer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    interface SerialPeriph;
    interface SerialPeriphEvent;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::SerialPeriph extends mcuf::hal::Base{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Enum Polarity
   */
  enum Polarity{
    HAL_SERIALPERIPH_POLARITY_ACTIVE_HIGH = 0x0U,
    HAL_SERIALPERIPH_POLARITY_ACTIVE_LOW = 0x1U
  };

  /* **************************************************************************************
   * Enum Phase
   */
  enum Phase{
    HAL_SERIALPERIPH_PHASE_FIRST_EDGE = 0x0U,
    HAL_SERIALPERIPH_PHASE_SECOND_EDGE = 0x1U
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
  virtual bool transfer(mcuf::io::ByteBuffer* transfer,
                        mcuf::io::ByteBuffer* receiver,
                        SerialPeriphEvent* event) abstract;

};
  

/* *****************************************************************************************
 * End of file
 */ 


#endif/* MCUF_E0DBA665_1EF1_4ECC_BF90_B467759500E6 */
