/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_F0B9EBB3_0F7D_45BA_B2A4_73DE35A44DCD
#define MCUF_F0B9EBB3_0F7D_45BA_B2A4_73DE35A44DCD

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/lang/Object.h"
#include "mcuf/io/InputStream.h"
#include "mcuf/io/OutputStream.h"
#include "mcuf/io/DuplexStream.h"
#include "mcuf/io/StreamSkipper.h"

//-----------------------------------------------------------------------------------------
#include "hal/SerialBus.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    class SerialBusStream;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::io::SerialBusStream extends mcuf::lang::Object implements
public mcuf::io::InputStream,
public mcuf::io::OutputStream,
public mcuf::io::DuplexStream,
public hal::SerialBusEvent{

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
    hal::SerialBus& mSerialBus;
    mcuf::io::StreamSkipper mStreamSkipper;
    void* mAttachment;
    mcuf::io::CompletionHandler<int, void*>* mHandler;
    uint16_t mAddress;
    bool mBusy;

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
     * @brief Construct a new Serial Bus Stream object
     * 
     * @param serialBus 
     */
    SerialBusStream(hal::SerialBus& serialBus, uint16_t address);

    /**
     * @brief Destroy the Serial Bus Stream object
     * 
     */
    virtual ~SerialBusStream(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::io::InputStream
   */
  public:
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
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
     * @param outputBuffer 
     * @return int 
     */
    virtual bool read(mcuf::io::InputBuffer& inputBuffer, int timeout) override;
    
    /**
     * @brief nonblocking
     * 
     * @param outputBuffer 
     * @param attachment 
     * @param handler 
     * @return true successful.
     * @return false fail.
     */
    virtual bool read(mcuf::io::InputBuffer& inputBuffer, 
                      void* attachment,
                      mcuf::io::CompletionHandler<int, void*>* handler) override;

    /**
     * @brief 
     * 
     * @param outputBuffer 
     * @param future 
     * @return true 
     * @return false 
     */
    virtual bool read(mcuf::io::InputBuffer& inputBuffer, mcuf::io::Future& future) override;

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
     * @param outputBuffer
     * @param future 
     * @return true 
     * @return false 
     */
    virtual bool write(mcuf::io::OutputBuffer& outputBuffer, int timeout) override;  
    
    /**
     * @brief 
     * 
     * @param outputBuffer
     * @param attachment 
     * @param handler 
     * @return true successful.
     * @return false fail.
     */
    virtual bool write(mcuf::io::OutputBuffer& outputBuffer, 
                      void* attachment,
                      mcuf::io::CompletionHandler<int, void*>* handler) override;

    /**
     * @brief 
     * 
     * @param outputBuffer
     * @param future 
     * @return true 
     * @return false 
     */
    virtual bool write(mcuf::io::OutputBuffer& outputBuffer, mcuf::io::Future& future) override;

  /* **************************************************************************************
   * Public Method <Override> - mcuf::io::DuplexStream
   */
  public:
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool abortTransfer(void) override;  
    
    /**
     * @brief 
     * 
     * @return true is busy.
     * @return false isn't busy.
     */
    virtual bool transferBusy(void) override;

    /**
     * @brief 
     * 
     * @param inputBuffer 
     * @param outputBuffer 
     * @param timeout 
     * @return true 
     * @return false 
     */
    virtual bool transfer(mcuf::io::InputBuffer& inputBuffer, 
                          mcuf::io::OutputBuffer& outputBuffer, 
                          int timeout) override;

    /**
     * @brief 
     * 
     * @param inputBuffer 
     * @param outputBuffer 
     * @param attachment 
     * @param handler 
     * @return true 
     * @return false 
     */
    virtual bool transfer(mcuf::io::InputBuffer& inputBuffer, 
                          mcuf::io::OutputBuffer& outputBuffer, 
                          void* attachment,
                          mcuf::io::CompletionHandler<int, void*>* handler) override;

    /**
     * @brief 
     * 
     * @param inputBuffer 
     * @param outputBuffer 
     * @param future 
     * @return true 
     * @return false 
     */
    virtual bool transfer(mcuf::io::InputBuffer& inputBuffer,
                          mcuf::io::OutputBuffer& outputBuffer,
                          mcuf::io::Future& future) override;

  /* **************************************************************************************
   * Public Method <Override> - hal::SerialBusEvent
   */    
  public:
    /**
     * @brief 
     * 
     * @param status handle status
     * @param result 0 = successful, other = remaining byte count.
     * @param attachment user data
     */
    virtual void onSerialBusEvent(hal::SerialBusStatus status, 
                                  int result,
                                  void* attachment) override;

  /* **************************************************************************************
   * Public Method <Inline>
   */
  public:
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    inline bool isBusy(void){
      return (this->mBusy || this->mSerialBus.isBusy());
    }

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

#endif /* MCUF_F0B9EBB3_0F7D_45BA_B2A4_73DE35A44DCD */
