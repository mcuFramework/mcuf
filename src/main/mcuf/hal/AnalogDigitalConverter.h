/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_B7C59389_FEAA_4CBA_B589_2658C300DF4C
#define MCUF_B7C59389_FEAA_4CBA_B589_2658C300DF4C

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/hal/Base.h"



/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  namespace hal{
    interface AnalogDigitalConverter;
  }
}



/* ****************************************************************************************
 * Interface AnalogDigitalConverter
 */  
interface mcuf::hal::AnalogDigitalConverter implement mcuf::hal::Base{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Method
   */

  /**
   * 
   */
  virtual bool enableChannel(uint32_t channel) abstract;
  
  /**
   * 
   */
  virtual bool disableChannel(uint32_t channel) abstract;
  
  /**
   * 
   */
  virtual uint32_t read(uint32_t channel) abstract;
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_B7C59389_FEAA_4CBA_B589_2658C300DF4C */
