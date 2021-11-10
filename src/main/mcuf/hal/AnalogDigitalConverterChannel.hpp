/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_B16985A9_A63C_403C_9D7B_5B3BB7B33CFA
#define MCUF_B16985A9_A63C_403C_9D7B_5B3BB7B33CFA

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  namespace hal{
    interface AnalogDigitalConverterChannel;
  }
}

/* ****************************************************************************************
 * Interface AnalogDigitalConverterChannel
 */  
interface mcuf::hal::AnalogDigitalConverterChannel{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Nethod
   */

  /**
   * 
   */
  virtual bool enable(void) abstract;
  
  /**
   * 
   */
  virtual bool disable(void) abstract;
  
  /**
   * 
   */
  virtual uint32_t read(void) abstract;

};  

/* *****************************************************************************************
 * End of file
 */

#endif/* MCUF_B16985A9_A63C_403C_9D7B_5B3BB7B33CFA */
