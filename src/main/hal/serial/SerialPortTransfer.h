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
#include "hal/serial/SerialPortEvent.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace hal{
  namespace serial{
    interface SerialPortTransfer;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::serial::SerialPortTransfer{

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
  virtual bool clear(void) abstract;

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
                    hal::serial::SerialPortEvent* event) abstract;

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
                    hal::serial::SerialPortEvent* event) abstract;
                    
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
                     hal::serial::SerialPortEvent* event) abstract;
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_F892B454_EC96_4F6C_B6FD_E2048ECC8CA2 */
