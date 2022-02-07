/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_B099D014_3A61_4973_9DCC_190FF7769067
#define MCUF_B099D014_3A61_4973_9DCC_190FF7769067

/* ****************************************************************************************
 * Include
 */  
 
//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/hal/serial/port/SerialPort.h"
#include "mcuf/hal/serial/port/SerialPortEvent.h"
#include "mcuf/hal/serial/port/SerialPortStatus.h"
#include "mcuf/io/InputStream.h"
#include "mcuf/io/OutputStream.h"
#include "mcuf/io/CompletionHandler.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    class SerialPortStream;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::io::SerialPortStream extends mcuf::lang::Object implements 
  public mcuf::io::OutputStream,
  public mcuf::io::InputStream,
  public mcuf::hal::serial::port::SerialPortEvent{

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  private: 
    mcuf::hal::serial::port::SerialPort* mSerialPort;
    mcuf::io::CompletionHandler<int, void*>* mWriteHandler;
    void* mWriteAttachment;
    mcuf::io::CompletionHandler<int, void*>* mReadHandler;
    void* mReadAttachment;
    
  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  public:

    /**
     * @brief Construct a new Serial Port Stream object
     * 
     * @param serialPort 
     */
    SerialPortStream(mcuf::hal::serial::port::SerialPort* serialPort);

    /**
     * @brief Destroy the Serial Port Stream object
     * 
     */
    ~SerialPortStream(void);

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::hal::serial::port::SerialPortEvent
   */  
  public:

    /**
     * @brief 
     * 
     * @param status 
     * @param byteBuffer 
     */
    virtual void onSerialPortEvent(mcuf::hal::serial::port::SerialPortStatus status, 
                                   mcuf::io::ByteBuffer* byteBuffer) override;

  /* **************************************************************************************
   * Public Method <Override> - mcuf::io::OutputStream
   */
  public:

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool abortWrite(void) override;  
    
    /**
     * @brief 
     * 
     * @return true is busy.
     * @return false isn't busy.
     */
    virtual bool writeBusy(void) override;

    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @param attachment 
     * @param handler 
     * @return true successful.
     * @return false fail.
     */
    virtual bool write(mcuf::io::ByteBuffer* byteBuffer, 
                      void* attachment,
                      mcuf::io::CompletionHandler<int, void*>* handler) override;

  /* **************************************************************************************
   * Public Method <Override> - mcuf::io::InputStream
   */                      
  public:

    /**
     * @brief 
     * 
     * @return true abrot successful.
     * @return false abrot fail.
     */
    virtual bool abortRead(void) override;
                              
    /**
     * @brief 
     * 
     * @return true is busy.
     * @return false isn't busy.
     */
    virtual bool readBusy(void) override;
    
    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @param attachment 
     * @param handler 
     * @return true successful.
     * @return false fail.
     */
    virtual bool read(mcuf::io::ByteBuffer* byteBuffer, 
                      void* attachment,
                      mcuf::io::CompletionHandler<int, void*>* handler) override;
                             

  /* **************************************************************************************
   * Public Method
   */

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */
   
  /* **************************************************************************************
   * Private Method
   */  

};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_B099D014_3A61_4973_9DCC_190FF7769067 */
