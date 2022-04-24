/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_F892B454_EC96_4F6C_B6FD_E2048ECC8CA2
#define MCUF_F892B454_EC96_4F6C_B6FD_E2048ECC8CA2

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/io/InputStreamBuffer.h"
#include "mcuf/io/OutputStream.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace hal{
  namespace serial{
    interface SerialPortTransfer;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::serial::SerialPortTransfer extends 
mcuf::io::InputStreamBuffer,
mcuf::io::OutputStream{

  /* **************************************************************************************
   * Method
   */
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_F892B454_EC96_4F6C_B6FD_E2048ECC8CA2 */
