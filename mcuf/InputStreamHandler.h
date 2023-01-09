/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_982C7EEA_0B24_4D5E_9563_C4E01EE5084B
#define MCUF_982C7EEA_0B24_4D5E_9563_C4E01EE5084B

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf\RingBufferInputStream.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  class InputStreamHandler;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::InputStreamHandler extends mcuf::RingBufferInputStream implements
  public mcuf::CompletionHandler<int, void*>{

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
    mcuf::InputStream& mInputStream;

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
     * @brief Construct a new Input Stream Handler object
     * 
     * @param inputStream 
     * @param buffer 
     * @param bufferSize 
     */
    InputStreamHandler(mcuf::InputStream& inputStream ,void* buffer, uint32_t bufferSize);
      
    /**
     * @brief Construct a new Input Stream Handler object
     * 
     * @param inputStream 
     * @param memory 
     */
    InputStreamHandler(mcuf::InputStream& inputStream ,const mcuf::Memory& memory);  

    /**
     * @brief Construct a new Input Stream Handler object
     * 
     * @param inputStream 
     * @param length 
     */
    InputStreamHandler(mcuf::InputStream& inputStream ,uint32_t length);

    /**
     * @brief Destroy the Input Stream Handler object
     * 
     */
    virtual ~InputStreamHandler(void) override;

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
    using mcuf::RingBufferInputStream::skip;
  
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
   * Public Method <Override> - mcuf::CompletionHandler<int, void*>
   */
  public:

    /**
     * @brief 
     * 
     * @param result 
     * @param attachment 
     */
    virtual void completed(int result, void* attachment) override;
    
    /**
     * @brief 
     * 
     * @param exc 
     * @param attachment 
     */
    virtual void failed(void* exc, void* attachment) override;
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
    void readPacket(void);
};

/* ****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_982C7EEA_0B24_4D5E_9563_C4E01EE5084B */
