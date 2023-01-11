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

//-----------------------------------------------------------------------------------------
#include "../mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "../ByteBuffer.h"

//-----------------------------------------------------------------------------------------
#include "./SerialPeriphPhase.h"
#include "./SerialPeriphPolarity.h"
#include "./SerialPeriphSignificantBit.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace mcuf::hal{
  struct SerialPeriphPacket;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
struct mcuf::hal::SerialPeriphPacket{
  mcuf::ByteBuffer* tx;
  mcuf::ByteBuffer* rx;
  uint32_t clock;
  mcuf::hal::SerialPeriphPhase phase;
  mcuf::hal::SerialPeriphPolarity polarity;
  mcuf::hal::SerialPeriphSignificantBit significantBit;
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_FE4F2681_1D7B_4D15_9CE7_36A02315CBED */
