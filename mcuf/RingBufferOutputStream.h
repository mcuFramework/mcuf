/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_773B1369_98E1_4A0E_BE62_135FA19FF875
#define MCUF_773B1369_98E1_4A0E_BE62_135FA19FF875

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf\OutputStreamBuffer.h"
#include "mcuf\RingBuffer.h"
#include "mcuf\Runnable.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  class RingBufferOutputStream;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::RingBufferOutputStream extends mcuf::RingBuffer implements
public mcuf::OutputStreamBuffer,
public mcuf::function::Runnable{

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
    mcuf::OutputBuffer* mOutputBuffer;
    void* mAttachment;
    mcuf::CompletionHandler<int, void*>* mHandler;
    int mResult;
    bool mHandling;  

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
     * @brief Construct a new RingBufferInputStream object
     * 
     * @param buffer 
     * @param bufferSize 
     */
    RingBufferOutputStream(void* buffer, uint32_t bufferSize);
      
    /**
     * @brief Construct a new RingBufferInputStream object
     * 
     * @param memory 
     */
    RingBufferOutputStream(const mcuf::Memory& memory);  

    /**
     * @brief Construct a new RingBufferInputStream object
     * 
     * @param length 
     */
    RingBufferOutputStream(uint32_t length);

    /**
     * @brief Destroy the Output Stream Buffer object
     * 
     */
    virtual ~RingBufferOutputStream(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::RingBuffer
   */
  public:
    /**
     * @brief pop buffer byte non blocking.
     * 
     * @param result 
     * @return true has data in buffer.
     * @return false no data in buffer.
     */
    virtual bool getByte(char& result) override;

    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @return int 
     */
    virtual int get(mcuf::InputBuffer& inputBuffer) override;
  
	  /**
	   * @brief 
	   * 
	   * @param byteBuffer 
	   * @return int 
	   */
	  virtual int get(mcuf::InputBuffer& inputBuffer, int length) override;

    /**
     * @brief 
     * 
     * @param buffer 
     * @param bufferSize 
     * @return int 
     */
    virtual int get(void* buffer, int bufferSize) override;

    /**
     * @brief 
     * 
     * @param value 
     * @return int 
     */
    virtual int skip(int value) override;

  /* **************************************************************************************
   * Public Method <Override> - mcuf::OutputStreamBuffer
   */
  public:
    /**
     * @brief Get the Input Buffer object
     * 
     * @return mcuf::InputBuffer& 
     */
    virtual mcuf::InputBuffer& getInputBuffer(void) override;

  /* **************************************************************************************
   * Public Method <Override> - mcuf::OutputStream
   */
  public:

    /**
     * @brief 
     * 
     * @return true successful.
     * @return false fail.
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
    virtual bool write(mcuf::OutputBuffer& outputBuffer, int timeout) override;
  
    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @param attachment 
     * @param handler 
     * @return true successful.
     * @return false fail.
     */
    virtual bool write(mcuf::OutputBuffer& byteBuffer, 
                       void* attachment,
                       mcuf::CompletionHandler<int, void*>* handler) override;
                       
    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @param future 
     * @return true 
     * @return false 
     */
    virtual bool write(mcuf::OutputBuffer& byteBuffer, mcuf::Future& future) override;

  /* **************************************************************************************
   * Public Method <Override> - mcuf::function::Runnable
   */
  public:
    /**
     * @brief 
     * 
     */
    virtual void run(void) override;
                       
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
  private:
    
    /**
     * @brief 
     *
     */
    void executeCompletionHandler(void);
  
};

/* ****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_773B1369_98E1_4A0E_BE62_135FA19FF875 */
