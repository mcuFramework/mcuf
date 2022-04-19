/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_A8449489_585B_43CB_9628_4057477E1906
#define MCUF_A8449489_585B_43CB_9628_4057477E1906

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/io/ByteBuffer.h"
#include "hal/serial/SerialPortEvent.h"

/* ****************************************************************************************
 * Namespace
 */
namespace hal{
  namespace serial{
    interface SerialPortReceiver;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface hal::serial::SerialPortReceiver{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @return uint32_t 
   */
  virtual uint32_t avariable(void) abstract;

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
  virtual bool clear(void) abstract;

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool readBusy(void) abstract;

  /**
   * @brief pop buffer byte non blocking.
   * 
   * @param result 
   * @return true has data in buffer.
   * @return false no data in buffer.
   */
  virtual bool getByte(char& result) abstract;

  /**
   * @brief 
   * 
   * @param byteBuffer 
   * @return int 
   */
  virtual int get(mcuf::io::ByteBuffer& byteBuffer) abstract;

  /**
   * @brief 
   * 
   * @param buffer 
   * @param bufferSize 
   * @return int 
   */
  virtual int get(void* buffer, int bufferSize) abstract;

  /**
   * @brief 
   * 
   * @param buffer 
   * @param maxLength 
   * @return uint32_t 
   */
  virtual uint32_t read(void* buffer, uint32_t maxLength) abstract;

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
                     
};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_A8449489_585B_43CB_9628_4057477E1906 */
