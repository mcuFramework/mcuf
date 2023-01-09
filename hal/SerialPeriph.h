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

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/io/ByteBuffer.h"

//-----------------------------------------------------------------------------------------
#include "hal/Base.h"
#include "hal/SerialPeriphTransfer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace hal{
  namespace serial{
    interface SerialPeriph;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::serial::SerialPeriph extends 
hal::Base,
hal::serial::SerialPeriphTransfer{

  /* **************************************************************************************
   * Method
   */

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_E0DBA665_1EF1_4ECC_BF90_B467759500E6 */
