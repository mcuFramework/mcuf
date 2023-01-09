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
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf\ByteBuffer.h"

//-----------------------------------------------------------------------------------------
#include "hal\SerialPeriphPhase.h"
#include "hal\SerialPeriphPolarity.h"
#include "hal\SerialPeriphSignificantBit.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
  struct SerialPeriphPacket;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
struct hal::SerialPeriphPacket{
  mcuf::ByteBuffer* tx;
  mcuf::ByteBuffer* rx;
  uint32_t clock;
  hal::SerialPeriphPhase phase;
  hal::SerialPeriphPolarity polarity;
  hal::SerialPeriphSignificantBit significantBit;
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_FE4F2681_1D7B_4D15_9CE7_36A02315CBED */
