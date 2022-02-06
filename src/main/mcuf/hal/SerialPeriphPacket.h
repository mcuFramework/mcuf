/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_FE4F2681_1D7B_4D15_9CE7_36A02315CBED
#define MCUF_FE4F2681_1D7B_4D15_9CE7_36A02315CBED

/* ****************************************************************************************
 * Include
 */
#include "mcuf_base.h"
#include "mcuf/io/ByteBuffer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    struct SerialPeriphPacket;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
struct mcuf::hal::SerialPeriphPacket{
  mcuf::io::ByteBuffer* tx;
  mcuf::io::ByteBuffer* rx;
  struct config{
    
  };
};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_FE4F2681_1D7B_4D15_9CE7_36A02315CBED */
