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
#include "mcuf/io/OutputStreamHandler.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::io::OutputStreamHandler;
using mcuf::io::OutputStream;
using mcuf::lang::Memory;

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
 * Public Method <Override> - mcuf::io::RingBuffer
 */

/**
 * @brief ???data?????????InputBuffer
 * 
 * @param data ????????????
 * @return true ?????????data?????????InputBuffer
 * @return false InputBuffer??????
 */
bool OutputStreamHandler::putByte(const char data){
  bool result = RingBufferOutputStream::putByte(data);
  if(this->mOutputStream.writeBusy() == false)
    this->writePacket();
  
  return result;
}

/**
 * @brief ???outputBuffer??????????????????InputBuffer
 * 
 * @param byteBuffer ????????????
 * @return int ??????????????????(byte)
 */
int OutputStreamHandler::put(OutputBuffer& outputBuffer){
  int result = RingBufferOutputStream::put(outputBuffer);
  if(this->mOutputStream.writeBusy() == false)
    this->writePacket();
  
  return result;
}

/**
 * @brief ???outputBuffer??????????????????InputBuffer?????????????????????
 * 
 * @param byteBuffer ????????????
 * @param length ????????????
 * @return int ??????????????????(byte)
 */
int OutputStreamHandler::put(OutputBuffer& outputBuffer, int length){
  int result = RingBufferOutputStream::put(outputBuffer, length);
  if(this->mOutputStream.writeBusy() == false)
    this->writePacket();
  
  return result;
}

/**
 * @brief ???buffer??????????????????InputBuffer
 * 
 * @param buffer ????????????
 * @param length ????????????
 * @return int ??????????????????(byte)
 */
int OutputStreamHandler::put(const void* buffer, int length){
  int result = RingBufferOutputStream::put(buffer, length);
  if(this->mOutputStream.writeBusy() == false)
    this->writePacket();
  
  return result;
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::io::CompletionHandler<int, void*>
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
