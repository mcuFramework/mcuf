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
#include "./InputStreamHandler.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using buf::InputStreamHandler;
using mcuf::InputStream;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Input Stream Handler object
 * 
 * @param inputStream 
 * @param buffer 
 * @param bufferSize 
 */
InputStreamHandler::InputStreamHandler(InputStream& inputStream ,void* buffer, uint32_t bufferSize) :
RingBufferInputStream(buffer, bufferSize),
mInputStream(inputStream){
  return;
}
  
/**
 * @brief Construct a new Input Stream Handler object
 * 
 * @param inputStream 
 * @param memory 
 */
InputStreamHandler::InputStreamHandler(InputStream& inputStream ,const mcuf::Memory& memory) :
RingBufferInputStream(memory),
mInputStream(inputStream){
  return;
}

/**
 * @brief Construct a new Input Stream Handler object
 * 
 * @param inputStream 
 * @param length 
 */
InputStreamHandler::InputStreamHandler(InputStream& inputStream ,uint32_t length) :
RingBufferInputStream(length),
mInputStream(inputStream){
  return;
}

/**
 * @brief Destroy the Input Stream Handler object
 * 
 */
InputStreamHandler::~InputStreamHandler(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override>  - mcuf::RingBuffer
 */

/**
 * @brief pop buffer byte non blocking.
 * 
 * @param result 
 * @return true has data in buffer.
 * @return false no data in buffer.
 */
bool InputStreamHandler::getByte(char& result){
  bool r = RingBufferInputStream::getByte(result);
  if(this->mInputStream.readBusy() == false)
    this->readPacket();

  return r;
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @return int 
 */
int InputStreamHandler::get(mcuf::InputBuffer& inputBuffer){
  int result = RingBufferInputStream::get(inputBuffer);
  if(this->mInputStream.readBusy() == false)
    this->readPacket();

  return result;  
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @return int 
 */
int InputStreamHandler::get(mcuf::InputBuffer& inputBuffer, int length){
  int result = RingBufferInputStream::get(inputBuffer, length);
  if(this->mInputStream.readBusy() == false)
    this->readPacket();

  return result;  
}

/**
 * @brief 
 * 
 * @param buffer 
 * @param bufferSize 
 * @return int 
 */
int InputStreamHandler::get(void* buffer, int bufferSize){
  int result = RingBufferInputStream::get(buffer, bufferSize);
  if(this->mInputStream.readBusy() == false)
    this->readPacket();

  return result;  
}

/**
 * @brief 
 * 
 * @param value 
 * @return int 
 */
int InputStreamHandler::skip(int value){
  int result = RingBufferInputStream::skip(value);
  if(this->mInputStream.readBusy() == false)
    this->readPacket();

  return result;  
}

/* ****************************************************************************************
 * Public Method <Override>  - mcuf::RingBuffer
 */

/**
 * @brief 
 * 
 * @param result 
 * @param attachment 
 */
void InputStreamHandler::completed(int result, void* attachment){
  if(this->mInputStream.readBusy() == false)
    this->readPacket();
}

/**
 * @brief 
 * 
 * @param exc 
 * @param attachment 
 */
void InputStreamHandler::failed(void* exc, void* attachment){
  if(this->mInputStream.readBusy() == false)
    this->readPacket();
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
void InputStreamHandler::readPacket(void){
  if(this->isFull())
    return;

  this->mInputStream.read(*this, this, this);
  return;
}

/* ****************************************************************************************
 * End of file
 */
