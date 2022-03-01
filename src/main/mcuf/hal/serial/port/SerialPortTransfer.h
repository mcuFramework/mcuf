/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_F892B454_EC96_4F6C_B6FD_E2048ECC8CA2
#define MCUF_F892B454_EC96_4F6C_B6FD_E2048ECC8CA2

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/io/ByteBuffer.h"
#include "mcuf/hal/serial/port/SerialPortEvent.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    namespace serial{
      namespace port{
        interface SerialPortTransfer;
      }
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::serial::port::SerialPortTransfer{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool abortRead(void) abstract;

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool abortWrite(void) abstract;

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool readBusy(void) abstract;

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool writeBusy(void) abstract;

  /**
   * @brief 
   * 
   * @param byteBuffer 
   * @param attachment 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool read(mcuf::io::ByteBuffer& byteBuffer, 
                    void* attachment,
                    mcuf::hal::serial::port::SerialPortEvent* event) abstract;

  /**
   * @brief 
   * 
   * @param value 
   * @param attachment 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool skip(int value,
                    void* attachment, 
                    mcuf::hal::serial::port::SerialPortEvent* event) abstract;

  /**
   * @brief 
   * 
   * @param byteBuffer 
   * @param attachment 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool write(mcuf::io::ByteBuffer& byteBuffer,
                     void* attachment,
                     mcuf::hal::serial::port::SerialPortEvent* event) abstract;
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_F892B454_EC96_4F6C_B6FD_E2048ECC8CA2 */
