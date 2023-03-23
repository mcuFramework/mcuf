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

//-----------------------------------------------------------------------------------------
#include "../mcuf/package-info.h"

//-----------------------------------------------------------------------------------------
#include "../mcuf/InputStreamBuffer.h"
#include "../mcuf/OutputStream.h"

//-----------------------------------------------------------------------------------------
#include "./Base.h"


/* ****************************************************************************************
 * Namespace
 */  
namespace hal{
  interface SerialPort;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::SerialPort extends hal::Base,
    mcuf::InputStream,
    mcuf::OutputStream{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @return uint32_t 
   */
  virtual uint32_t getBaudrate(void) abstract;

  /**
   * @brief Set the Baudrate object
   * 
   * @param baudrate 期望的輸出鮑率
   * @return uint32_t 實際的輸出鮑率
   */
  virtual uint32_t setBaudrate(uint32_t baudrate) abstract;
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_A805502A_41D9_45B8_A89A_B11ED86A2F19 */
