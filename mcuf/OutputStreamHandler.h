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
#include "./mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "./RingBufferOutputStream.h"
#include "./CompletionHandler.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  class OutputStreamHandler;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::OutputStreamHandler extends mcuf::RingBufferOutputStream implements
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
    mcuf::OutputStream& mOutputStream;

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
    OutputStreamHandler(mcuf::OutputStream& OutputStream, void* buffer, uint32_t bufferSize);
      
    /**
     * @brief Construct a new Output Stream Buffer object
     * 
     * @param outputStream 
     * @param memory 
     */
    OutputStreamHandler(mcuf::OutputStream& OutputStream, const mcuf::Memory& memory);  

    /**
     * @brief Construct a new Output Stream Buffer object
     * 
     * @param outputStream 
     * @param length 
     */
    OutputStreamHandler(mcuf::OutputStream& OutputStream, uint32_t length);

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
   * Public Method <Override> - mcuf::RingBuffer
   */
  public:
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
    void writePacket(void);
};

/* ****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_DEBBE420_CC2F_4D95_AD55_B08F0EDCDC0C */
