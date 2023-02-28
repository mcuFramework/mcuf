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

//-----------------------------------------------------------------------------------------
#include "../mcuf/mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "../mcuf/InputStreamBuffer.h"
#include "../mcuf/OutputStream.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf::hal{
  interface SerialPortTransfer;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::SerialPortTransfer extends 
mcuf::InputStreamBuffer,
mcuf::OutputStream{

  /* **************************************************************************************
   * Method
   */
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_F892B454_EC96_4F6C_B6FD_E2048ECC8CA2 */
