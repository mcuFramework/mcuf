/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_5C74EA1C_70D3_4787_9DF0_AEF03A283936
#define MCUF_5C74EA1C_70D3_4787_9DF0_AEF03A283936

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/io/OutputBuffer.h"
#include "mcuf/io/InputBuffer.h"
#include "hal/serial/SerialBus.h"

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  namespace io{
    struct SerialBusQueuePacket;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct mcuf::io::SerialBusQueuePacket{
  uint16_t reserved;
  uint16_t address;
  mcuf::io::OutputBuffer* out;
  mcuf::io::InputBuffer* in;
  void* attachment;
  hal::serial::SerialBusEvent* event;
};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_5C74EA1C_70D3_4787_9DF0_AEF03A283936 */
