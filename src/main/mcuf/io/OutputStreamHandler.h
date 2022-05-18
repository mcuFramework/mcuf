/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_DEBBE420_CC2F_4D95_AD55_B08F0EDCDC0C
#define MCUF_DEBBE420_CC2F_4D95_AD55_B08F0EDCDC0C

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/io/RingBufferOutputStream.h"
#include "mcuf/io/CompletionHandler.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    class OutputStreamHandler;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::io::OutputStreamHandler extends mcuf::io::RingBufferOutputStream implements
  public mcuf::io::CompletionHandler<int, void*>{

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
    mcuf::io::OutputStream& mOutputStream;

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
     * @brief Construct a new Output Stream Buffer object
     * 
     * @param outputStream 
     * @param buffer 
     * @param bufferSize 
     */
    OutputStreamHandler(mcuf::io::OutputStream& OutputStream, void* buffer, uint32_t bufferSize);
      
    /**
     * @brief Construct a new Output Stream Buffer object
     * 
     * @param outputStream 
     * @param memory 
     */
    OutputStreamHandler(mcuf::io::OutputStream& OutputStream, const mcuf::lang::Memory& memory);  

    /**
     * @brief Construct a new Output Stream Buffer object
     * 
     * @param outputStream 
     * @param length 
     */
    OutputStreamHandler(mcuf::io::OutputStream& OutputStream, uint32_t length);

    /**
     * @brief Destroy the Output Stream Buffer object
     * 
     */
    virtual ~OutputStreamHandler(void) override;

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
     * @brief pop buffer byte non blocking.
     * 
     * @param result 
     * @return true has data in buffer.
     * @return false no data in buffer.
     */
    virtual bool putByte(const char result) override;

    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @return int 
     */
    virtual int put(mcuf::io::OutputBuffer& outputBuffer) override;
  
    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @param length 
     * @return int 
     */
    virtual int put(mcuf::io::OutputBuffer& outputBuffer, int length) override;  

    /**
     * @brief 
     * 
     * @param buffer 
     * @param bufferSize 
     * @return int 
     */
    virtual int put(const void* buffer, int bufferSize) override;

  /* **************************************************************************************
   * Public Method <Override> - mcuf::io::CompletionHandler<int, void*>
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
    void writePacket(void);
};

/* ****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_DEBBE420_CC2F_4D95_AD55_B08F0EDCDC0C */
