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
#include "mcuf/io/OutputBufferLimit.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::io::OutputBufferLimit;
using mcuf::io::OutputBuffer;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */
/**
 * @brief Construct a new Output Buffer Limit object
 * 
 */
OutputBufferLimit::OutputBufferLimit(void){
  this->mPosition = 0;
  this->mLimit = 0;
  this->mOutputBuffer = nullptr;
  return;
}
/**
 * @brief Destroy the Output Buffer Limit object
 * 
 */
OutputBufferLimit::~OutputBufferLimit(void){
  this->mPosition = 0;
  this->mLimit = 0;
  this->mOutputBuffer = nullptr;
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - mcuf::io::OutputBuffer
 */
/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool OutputBufferLimit::isEmpty(void) const{
  if(this->mPosition >= this->mLimit)
    return true;

  if(this->mOutputBuffer == nullptr)
    return true;

  return this->mOutputBuffer->isEmpty();
}

/**
 * @brief 
 * 
 * @return int 
 */
int OutputBufferLimit::avariable(void) const{
  if(this->mOutputBuffer == nullptr)
    return 0;

  int max = (this->mLimit - this->mPosition);
  int result = this->mOutputBuffer->avariable();
  if(result > max)
    return max;

  return result;
}

/**
 * @brief pop buffer byte non blocking.
 * 
 * @param result 
 * @return true has data in buffer.
 * @return false no data in buffer.
 */
bool OutputBufferLimit::getByte(char& result){
  if(this->mPosition >= this->mLimit)
    return false;

  if(this->mOutputBuffer == nullptr)
    return false;

  bool r = this->mOutputBuffer->getByte(result);
  if(r)
    ++this->mPosition;

  return r;
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @return int 
 */
int OutputBufferLimit::get(mcuf::io::InputBuffer& inputBuffer){
  if(this->mOutputBuffer == nullptr)
    return 0;

  int result = this->mOutputBuffer->get(inputBuffer, this->avariable());
  this->mPosition += result;
  return result;    
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @return int 
 */
int OutputBufferLimit::get(mcuf::io::InputBuffer& inputBuffer, int length){
  if(this->mOutputBuffer == nullptr)
    return 0;
  
  int max = this->avariable();
  if(length > max)
    length = max;

  int result = this->mOutputBuffer->get(inputBuffer, length);
  this->mPosition += result;
  return result;   
}

/**
 * @brief 
 * 
 * @param buffer 
 * @param bufferSize 
 * @return int 
 */
int OutputBufferLimit::get(void* buffer, int bufferSize){
  if(this->mOutputBuffer == nullptr)
    return 0;

  int max = this->avariable();
  if(bufferSize > max)
    bufferSize = max;

  int result = this->mOutputBuffer->get(buffer, bufferSize);
  this->mPosition += result;
  return result;
}

/**
 * @brief 
 * 
 * @param value 
 * @return int 
 */
int OutputBufferLimit::skip(int value){
  if(this->mOutputBuffer == nullptr)
    return 0;

  int max = this->avariable();
  if(value > max)
    value = max;

  int result = this->mOutputBuffer->skip(value);
  this->mPosition += result;
  return result;
}

/* ****************************************************************************************
 * Public Method
 */
/**
 * @brief 
 * 
 * @param value 
 * @return int 
 */
int OutputBufferLimit::limit(int value){
  if(value < 0)
    return this->mLimit;

  this->mLimit = value;
  if(value > this->mPosition)
    this->mPosition = value;

  return this->mLimit;
}

/**
 * @brief 
 * 
 * @return int 
 */
int OutputBufferLimit::limit(void){
  return this->mLimit;
}

/**
 * @brief 
 * 
 * @param value 
 * @return int 
 */
int OutputBufferLimit::position(int value){
  if(value < 0)
    return this->mPosition;

  if(value > this->mLimit)
    value = this->mLimit;

  this->mPosition = value;
  return this->mPosition;
}

/**
 * @brief 
 * 
 * @return int 
 */
int OutputBufferLimit::position(void){
  return this->mPosition;
}

/**
 * @brief 
 * 
 */
void OutputBufferLimit::flush(void){
  this->mPosition = 0;
  return;
}

/**
 * @brief Get the Output Buffer object
 * 
 * @return mcuf::io::OutputBuffer* 
 */
mcuf::io::OutputBuffer* OutputBufferLimit::getOutputBuffer(void){
  return this->mOutputBuffer;
}

/**
 * @brief Set the Output Buffer object
 * 
 * @param outputBuffer 
 * @return mcuf::io::OutputBuffer* 
 */
mcuf::io::OutputBuffer* OutputBufferLimit::setOutputBuffer(mcuf::io::OutputBuffer* outputBuffer){
  mcuf::io::OutputBuffer* temp = this->mOutputBuffer;
  this->mOutputBuffer = outputBuffer;
  return temp;
}

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

/* ****************************************************************************************
 * End of file
 */
