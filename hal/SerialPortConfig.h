/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_B9EBB8B5_7716_4DD7_907B_6BA3C9F0756C
#define MCUF_B9EBB8B5_7716_4DD7_907B_6BA3C9F0756C

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf\Interface.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
  interface SerialPortConfig;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::SerialPortConfig extends virtual mcuf::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @return uint32_t 
   */
  virtual uint32_t baudrate(void) abstract;

  /**
   * @brief 
   * 
   * @param rate 
   * @return uint32_t 
   */
  virtual uint32_t baudrate(uint32_t rate) abstract;
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_B9EBB8B5_7716_4DD7_907B_6BA3C9F0756C */
