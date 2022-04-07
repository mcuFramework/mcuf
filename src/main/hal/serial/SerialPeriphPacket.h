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
#include "hal/serial/SerialPeriphPhase.h"
#include "hal/serial/SerialPeriphPolarity.h"
#include "hal/serial/SerialPeriphSignificantBit.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
  namespace serial{
    struct SerialPeriphPacket;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
struct hal::serial::SerialPeriphPacket{
  mcuf::io::ByteBuffer* tx;
  mcuf::io::ByteBuffer* rx;
  uint32_t clock;
  hal::serial::SerialPeriphPhase phase;
  hal::serial::SerialPeriphPolarity polarity;
  hal::serial::SerialPeriphSignificantBit significantBit;
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_FE4F2681_1D7B_4D15_9CE7_36A02315CBED */
