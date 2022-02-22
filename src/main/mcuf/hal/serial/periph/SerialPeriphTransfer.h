/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_A0D6B8FB_0339_412F_8DD0_D6C82479607C
#define MCUF_A0D6B8FB_0339_412F_8DD0_D6C82479607C

/* ****************************************************************************************
 * Include
 */
#include "mcuf_base.h"
#include "mcuf/hal/Base.h"
#include "mcuf/io/ByteBuffer.h"
#include "mcuf/hal/serial/periph/SerialPeriphEvent.h"
#include "mcuf/hal/serial/periph/SerialPeriphPacket.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    namespace serial{
      namespace periph{
        interface SerialPeriphTransfer;
      }
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::serial::periph::SerialPeriphTransfer{

  /* **************************************************************************************
   * Method
   */
   
  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool abort(void) abstract;
  
  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool isBusy(void) abstract;

  /**
   * @brief 
   * 
   * @param chipSelect 
   * @param packet 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool transfer(uint32_t chipSelect, 
                        mcuf::hal::serial::periph::SerialPeriphPacket* packet,
                        mcuf::hal::serial::periph::SerialPeriphEvent* event) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_A0D6B8FB_0339_412F_8DD0_D6C82479607C */
