/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_D62227AD_6C8A_4906_8DEB_0269D2F0EBF1
#define MCUF_D62227AD_6C8A_4906_8DEB_0269D2F0EBF1

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    namespace serial{
      namespace bus{
        interface SerialBusControl;
      }
    }
  }
}

/* ****************************************************************************************
 * Interface/Class/Struct
 */  
interface mcuf::hal::serial::bus::SerialBusControl{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * 
   */
  virtual uint32_t clockRate(void) abstract;

  /**
   * 
   */
  virtual uint32_t clockRate(uint32_t clock) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_D62227AD_6C8A_4906_8DEB_0269D2F0EBF1 */
