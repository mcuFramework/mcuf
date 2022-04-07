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
#include "hal/serial/SerialBusEvent.h"

/* ****************************************************************************************
 * Namespace
 */  
 
namespace hal{
  namespace serial{
    interface SerialBusTransfer;
  }
}

/* ****************************************************************************************
 * Interface/Class/Struct
 */  
interface hal::serial::SerialBusTransfer{

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
  virtual bool read(uint16_t address, 
                    mcuf::io::ByteBuffer& receiver,
                    void* attachment,
                    hal::serial::SerialBusEvent* event) abstract;

  /**
   * @brief 
   * 
   * @param address 
   * @param receiver 
   * @param event 
   */
  virtual bool write(uint16_t address, 
                     mcuf::io::ByteBuffer& transfer,
                     void* attachment,
                     hal::serial::SerialBusEvent* event) abstract;
  
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
                              void* attachment,
                              hal::serial::SerialBusEvent* event) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_D6F51B91_28D1_4137_A132_2CECD1B3E012 */
