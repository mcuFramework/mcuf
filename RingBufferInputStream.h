/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_A4DC217C_C29F_4947_B36B_0D55F49EB274
#define MCUF_A4DC217C_C29F_4947_B36B_0D55F49EB274

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf/mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/InputStreamBuffer.h"
#include "mcuf/RingBuffer.h"
#include "mcuf/Runnable.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  class RingBufferInputStream;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::RingBufferInputStream extends mcuf::RingBuffer implements
public mcuf::InputStreamBuffer,
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
    mcuf::InputBuffer* mInputBuffer;
    void* mAttachment;
    mcuf::CompletionHandler<int, void*>* mHandler;
    int mResult;
    int mSkip;
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
    RingBufferInputStream(void* buffer, uint32_t bufferSize);
      
    /**
     * @brief Construct a new RingBufferInputStream object
     * 
     * @param memory 
     */
    RingBufferInputStream(const mcuf::Memory& memory);  

    /**
     * @brief Construct a new RingBufferInputStream object
     * 
     * @param length 
     */
    RingBufferInputStream(uint32_t length);

    /**
     * @brief Destroy the RingBufferInputStream object
     * 
     */
    virtual ~RingBufferInputStream(void) override;

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
    using RingBuffer::avariable;
    using RingBuffer::skip;
   
    /**
     * @brief 將data輸入至InputBuffer
     * 
     * @param data 資料來源
     * @return true 成功將data輸入至InputBuffer
     * @return false InputBuffer已滿
     */
    virtual bool putByte(const char data) override;   
   
    /**
     * @brief 將outputBuffer內資料輸入至InputBuffer
     * 
     * @param byteBuffer 資料來源
     * @return int 移動資料數量(byte)
     */
    virtual int put(mcuf::OutputBuffer& outputBuffer) override;

    /**
     * @brief 將outputBuffer內資料輸入至InputBuffer並指定輸入長度
     * 
     * @param byteBuffer 資料來源
     * @param length 輸入長度
     * @return int 移動資料數量(byte)
     */
    virtual int put(mcuf::OutputBuffer& outputBuffer, int length) override;  

    /**
     * @brief 將buffer內資料輸入至InputBuffer
     * 
     * @param buffer 資料來源
     * @param length 輸入長度
     * @return int 移動資料數量(byte)
     */
    virtual int put(const void* buffer, int length) override;
    
  /* **************************************************************************************
   * Public Method <Override> - mcuf::InputStreamBuffer
   */
  public:
    /**
     * @brief Get the Output Buffer object
     * 
     * @return mcuf::OutputBuffer& 
     */
    virtual mcuf::OutputBuffer& getOutputBuffer(void) override;

  /* **************************************************************************************
   * Public Method <Override> - mcuf::InputStream 
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
     * @param inputBuffer 
     * @return int 
     */
    virtual bool read(mcuf::InputBuffer& inputBuffer, int timeout) override;        
    
    /**
     * @brief nonblocking
     * 
     * @param inputBuffer 
     * @param attachment 
     * @param handler 
     * @return true successful.
     * @return false fail.
     */
    virtual bool read(mcuf::InputBuffer& inputBuffer, 
                      void* attachment,
                      mcuf::CompletionHandler<int, void*>* handler) override;

    /**
     * @brief 
     * 
     * @param inputBuffer 
     * @param future 
     * @return true 
     * @return false 
     */
    virtual bool read(mcuf::InputBuffer& inputBuffer, mcuf::Future& future) override;

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
                      mcuf::CompletionHandler<int, void*>* handler) override;

    /**
     * @brief 
     * 
     * @param value 
     * @param future 
     * @return true 
     * @return false 
     */
    virtual bool skip(int value, mcuf::Future& future) override;
    

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

#endif /* MCUF_A4DC217C_C29F_4947_B36B_0D55F49EB274 */
