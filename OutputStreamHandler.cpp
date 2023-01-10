/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "mcuf/OutputStreamHandler.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::OutputStreamHandler;
using mcuf::OutputStream;
using mcuf::Memory;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Output Stream Buffer object
 * 
 * @param outputStream 
 * @param buffer 
 * @param bufferSize 
 */
OutputStreamHandler::OutputStreamHandler(OutputStream& outputStream, void* buffer, uint32_t bufferSize) :
RingBufferOutputStream(buffer, bufferSize),
mOutputStream(outputStream){

  return;
}
  
/**
 * @brief Construct a new Output Stream Buffer object
 * 
 * @param outputStream 
 * @param memory 
 */
OutputStreamHandler::OutputStreamHandler(OutputStream& outputStream, const Memory& memory) :
RingBufferOutputStream(memory),
mOutputStream(outputStream){

  return;
}

/**
 * @brief Construct a new Output Stream Buffer object
 * 
 * @param outputStream 
 * @param length 
 */
OutputStreamHandler::OutputStreamHandler(OutputStream& outputStream, uint32_t length) :
RingBufferOutputStream(length),
mOutputStream(outputStream){

  return;
}

/**
 * @brief Destroy the Output Stream Buffer object
 * 
 */
OutputStreamHandler::~OutputStreamHandler(void){
  this->abortWrite();
  return;
}
/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - mcuf::RingBuffer
 */

/**
 * @brief 將data輸入至InputBuffer
 * 
 * @param data 資料來源
 * @return true 成功將data輸入至InputBuffer
 * @return false InputBuffer已滿
 */
bool OutputStreamHandler::putByte(const char data){
  bool result = RingBufferOutputStream::putByte(data);
  if(this->mOutputStream.writeBusy() == false)
    this->writePacket();
  
  return result;
}

/**
 * @brief 將outputBuffer內資料輸入至InputBuffer
 * 
 * @param byteBuffer 資料來源
 * @return int 移動資料數量(byte)
 */
int OutputStreamHandler::put(OutputBuffer& outputBuffer){
  int result = RingBufferOutputStream::put(outputBuffer);
  if(this->mOutputStream.writeBusy() == false)
    this->writePacket();
  
  return result;
}

/**
 * @brief 將outputBuffer內資料輸入至InputBuffer並指定輸入長度
 * 
 * @param byteBuffer 資料來源
 * @param length 輸入長度
 * @return int 移動資料數量(byte)
 */
int OutputStreamHandler::put(OutputBuffer& outputBuffer, int length){
  int result = RingBufferOutputStream::put(outputBuffer, length);
  if(this->mOutputStream.writeBusy() == false)
    this->writePacket();
  
  return result;
}

/**
 * @brief 將buffer內資料輸入至InputBuffer
 * 
 * @param buffer 資料來源
 * @param length 輸入長度
 * @return int 移動資料數量(byte)
 */
int OutputStreamHandler::put(const void* buffer, int length){
  int result = RingBufferOutputStream::put(buffer, length);
  if(this->mOutputStream.writeBusy() == false)
    this->writePacket();
  
  return result;
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::CompletionHandler<int, void*>
 */

/**
 * @brief 
 * 
 * @param result 
 * @param attachment 
 */
void OutputStreamHandler::completed(int result, void* attachment){
  if(this->mOutputStream.writeBusy() == false)
    this->writePacket();
}

/**
 * @brief 
 * 
 * @param exc 
 * @param attachment 
 */
void OutputStreamHandler::failed(void* exc, void* attachment){
  if(this->mOutputStream.writeBusy() == false)
    this->writePacket();
}

/* ****************************************************************************************
 * Public Method
 */

/* ****************************************************************************************
 * Protected Method <Static>
 */

/* ****************************************************************************************
 * Protected Method <Override>
 */

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */

/**
 * @brief 
 * 
 */
void OutputStreamHandler::writePacket(void){
  if(this->avariable() <= 0)
    return;
  
  this->mOutputStream.write(*this, this, this);
  return;
}

/* ****************************************************************************************
 * End of file
 */
