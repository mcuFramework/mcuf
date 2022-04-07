/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_8FE9223C_FFFD_4DB6_ACA0_1BE151D350EF
#define MCUF_8FE9223C_FFFD_4DB6_ACA0_1BE151D350EF

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
#include "mcuf/io/Future.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    class SerialPortInputStream;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::io::SerialPortInputStream extends mcuf::lang::Object implements 
  public mcuf::io::InputStream,
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
    mcuf::io::CompletionHandler<int, void*>* mReadHandler;
  
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
     * @brief Construct a new Serial Port Input Stream object
     * 
     * @param serialPort 
     */
    SerialPortInputStream(hal::serial::SerialPort& serialPort);

    /**
     * @brief Destroy the Serial Port Input Stream object
     * 
     */
    virtual ~SerialPortInputStream(void);

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
     * @param status handle status
     * @param result 0 = successful, other = remaining byte count.
     * @param attachment user data
     */
    virtual void onSerialPortEvent(hal::serial::SerialPortStatus status, 
                                   int result,
                                   void* attachment) override;

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
    virtual bool read(mcuf::io::ByteBuffer& byteBuffer, 
                      void* attachment,
                      mcuf::io::CompletionHandler<int, void*>* handler) override;

    /**
     * @brief blocking, cannot call in interrupt
     * 
     * @param byteBuffer 
     * @return int 
     */
    virtual bool read(mcuf::io::ByteBuffer& byteBuffer, 
                      mcuf::io::Future& feture) override;
                  
    /**
     * @brief 
     * 
     * @param value 
     * @param attachment 
     * @param handler 
     * @return true 
     * @return false 
     */
    virtual bool skip(int value, 
                      void* attachment,
                      mcuf::io::CompletionHandler<int, void*>* handler) override;

    /**
     * @brief 
     * 
     * @param value 
     * @param future 
     * @return true 
     * @return false 
     */
    virtual bool skip(int value, mcuf::io::Future& future) override;
                      
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

#endif /* MCUF_8FE9223C_FFFD_4DB6_ACA0_1BE151D350EF */
