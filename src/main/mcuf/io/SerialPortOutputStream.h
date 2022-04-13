/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_056EB5AC_CAA5_4283_A960_832982C15294
#define MCUF_056EB5AC_CAA5_4283_A960_832982C15294

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "hal/serial/SerialPort.h"
#include "hal/serial/SerialPortEvent.h"
#include "hal/serial/SerialPortStatus.h"
#include "mcuf/io/InputStream.h"
#include "mcuf/io/OutputStream.h"
#include "mcuf/io/CompletionHandler.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    class SerialPortOutputStream;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::io::SerialPortOutputStream extends mcuf::lang::Object implements 
  public mcuf::io::OutputStream,
  public hal::serial::SerialPortEvent
{

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
    hal::serial::SerialPort& mSerialPort;
    mcuf::io::CompletionHandler<int, void*>* mWriteHandler;

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
     * @brief Construct a new Serial Port Output Stream object 
     * 
     * @param serialPort 
     */
    SerialPortOutputStream(hal::serial::SerialPort& serialPort);

    /**
     * @brief Destroy the Serial Port Output Stream object
     * 
     */
    virtual ~SerialPortOutputStream(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - hal::serial::SerialPortEvent
   */  
  public:

    /**
     * @brief 
     * 
     * @param status 
     * @param byteBuffer 
     */
    virtual void onSerialPortEvent(hal::serial::SerialPortStatus status, 
                                   int resutl,
                                   void* attachment) override;


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
    virtual bool write(mcuf::io::ByteBuffer& byteBuffer, 
                      void* attachment,
                      mcuf::io::CompletionHandler<int, void*>* handler) override;

    /**
     * @brief blocking, cannot call in interrupt
     * 
     * @param byteBuffer 
     * @return int 
     */
    virtual bool write(mcuf::io::ByteBuffer& byteBuffer, mcuf::io::Future& feture) override;
                      
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

/* ****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_056EB5AC_CAA5_4283_A960_832982C15294 */
