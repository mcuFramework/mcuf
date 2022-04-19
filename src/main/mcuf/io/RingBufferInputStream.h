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
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/io/InputStream.h"
#include "mcuf/io/RingBuffer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    class RingBufferInputStream;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::io::RingBufferInputStream extends mcuf::io::RingBuffer implements
  public mcuf::io::InputStream{

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
    mcuf::io::ByteBuffer* mByteBuffer;
    void* mAttachment;
    mcuf::io::CompletionHandler<int, void*>* mHandler;
    int mSkip;
  
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
    RingBufferInputStream(const mcuf::lang::Memory& memory);  

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
   * Public Method <Override> - mcuf::io::RingBuffer 
   */
   public:
    /**
     * @brief 
     * 
     * @param data 
     * @return true 
     * @return false 
     */
    virtual bool insert(const void* data) override;
    
    /**
     * @brief 
     * 
     * @param data 
     * @param num 
     * @return int 
     */
    virtual int insertMult(const void *data, int num) override;

  /* **************************************************************************************
   * Public Method <Override> - mcuf::io::InputStream 
   */
  public:
    /**
     * @brief 
     * 
     * @return int 
     */
    virtual int avariable(void) override;    
  
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
    virtual int get(mcuf::io::ByteBuffer& byteBuffer) override;

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
     * @param byteBuffer 
     * @return int 
     */
    virtual bool read(mcuf::io::ByteBuffer& byteBuffer) override;        
    
    /**
     * @brief nonblocking
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
     * @brief 
     * 
     * @param byteBuffer 
     * @param future 
     * @return true 
     * @return false 
     */
    virtual bool read(mcuf::io::ByteBuffer& byteBuffer, mcuf::io::Future& future) override;

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
