/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_C7AF213C_229B_4649_8BE8_7A2304803C4D
#define MCUF_C7AF213C_229B_4649_8BE8_7A2304803C4D

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
    interface SerialBusSlot;
  }
}

/* ****************************************************************************************
 * Interface/Class/Struct
 */  
interface hal::serial::SerialBusSlot{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @param address 
   * @return true 
   * @return false 
   */
  virtual bool address(uint16_t address) abstract;

  /**
   * @brief 
   * 
   * @return uint16_t 
   */
  virtual uint16_t address(void) abstract;

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
  virtual void read(mcuf::io::ByteBuffer& receiver, 
                    hal::serial::SerialBusEvent* event) abstract;

  /**
   * @brief 
   * 
   * @param address 
   * @param receiver 
   * @param event 
   */
  virtual void write(mcuf::io::ByteBuffer& receiver, 
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
  virtual bool writeAfterRead(mcuf::io::ByteBuffer& transfer, 
                              mcuf::io::ByteBuffer& receiver,
                              hal::serial::SerialBusEvent* event) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_C7AF213C_229B_4649_8BE8_7A2304803C4D */
