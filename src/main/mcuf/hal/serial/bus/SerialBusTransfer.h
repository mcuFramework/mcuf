/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_D6F51B91_28D1_4137_A132_2CECD1B3E012
#define MCUF_D6F51B91_28D1_4137_A132_2CECD1B3E012

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/io/ByteBuffer.h"
#include "mcuf/hal/serial/bus/SerialBusEvent.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    namespace serial{
      namespace bus{
        interface SerialBusTransfer;
      }
    }
  }
}

/* ****************************************************************************************
 * Interface/Class/Struct
 */  
interface mcuf::hal::serial::bus::SerialBusTransfer{

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
   * @param address 
   * @param receiver 
   * @param event 
   */
  virtual bool read(uint8_t address, 
                    mcuf::io::ByteBuffer& receiver, 
                    mcuf::hal::serial::bus::SerialBusEvent* event) abstract;

  /**
   * @brief 
   * 
   * @param address 
   * @param receiver 
   * @param event 
   */
  virtual bool write(uint16_t address, 
                     mcuf::io::ByteBuffer& receiver, 
                     mcuf::hal::serial::bus::SerialBusEvent* event) abstract;
  
  /**
   * @brief 
   * 
   * @param address 
   * @param transfer 
   * @param receiver 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool writeAfterRead(uint16_t address, 
                              mcuf::io::ByteBuffer& transfer, 
                              mcuf::io::ByteBuffer& receiver,
                              mcuf::hal::serial::bus::SerialBusEvent* event) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_D6F51B91_28D1_4137_A132_2CECD1B3E012 */
