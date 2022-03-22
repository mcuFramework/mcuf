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
#include "mcuf/hal/serial/periph/SerialPeriphPhase.h"
#include "mcuf/hal/serial/periph/SerialPeriphPolarity.h"
#include "mcuf/hal/serial/periph/SerialPeriphSignificantBit.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    namespace serial{
      namespace periph{
        struct SerialPeriphPacket;
      }
    } 
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
struct mcuf::hal::serial::periph::SerialPeriphPacket{
  mcuf::io::ByteBuffer* tx;
  mcuf::io::ByteBuffer* rx;
  uint32_t clock;
  mcuf::hal::serial::periph::SerialPeriphPhase phase;
  mcuf::hal::serial::periph::SerialPeriphPolarity polarity;
  mcuf::hal::serial::periph::SerialPeriphSignificantBit significantBit;
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_FE4F2681_1D7B_4D15_9CE7_36A02315CBED */
