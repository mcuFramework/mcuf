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
#include "mcuf/InputBufferLimit.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::InputBufferLimit;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */
/**
 * @brief Construct a new Input Buffer Limit object
 * 
 */
InputBufferLimit::InputBufferLimit(void){
  this->mPosition = 0;
  this->mLimit = 0;
  this->mInputBuffer = nullptr;
  return;
}

/**
 * @brief Destroy the Input Buffer Limit object
 * 
 */
InputBufferLimit::~InputBufferLimit(void){
  this->mPosition = 0;
  this->mLimit = 0;
  this->mInputBuffer = nullptr;
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - mcuf::InputBuffer
 */
/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool InputBufferLimit::isFull(void) const{
  if(this->mPosition >= this->mLimit)
    return true;

  if(this->mInputBuffer == nullptr)
    return true;

  return this->mInputBuffer->isFull();
}

/**
 * @brief 
 * 
 * @return int 
 */
int InputBufferLimit::remaining(void) const{
  if(this->mInputBuffer == nullptr)
    return 0;

  int max = (this->mLimit - this->mPosition);
  int result = this->mInputBuffer->remaining();
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
bool InputBufferLimit::putByte(const char result){
  if(this->mPosition >= this->mLimit)
    return false;

  if(this->mInputBuffer == nullptr)
    return false;

  bool r = this->mInputBuffer->putByte(result);
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
int InputBufferLimit::put(mcuf::OutputBuffer& outputBuffer){
  if(this->mInputBuffer == nullptr)
    return 0;

  int result = this->mInputBuffer->put(outputBuffer, this->remaining());
  this->mPosition += result;
  return result;    
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @param length 
 * @return int 
 */
int InputBufferLimit::put(OutputBuffer& outputBuffer, int length){
  if(this->mInputBuffer == nullptr)
    return 0;
  
  int max = this->remaining();
  if(length > max)
    length = max;

  int result = this->mInputBuffer->put(outputBuffer, length);
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
int InputBufferLimit::put(const void* buffer, int bufferSize){
  if(this->mInputBuffer == nullptr)
    return 0;

  int max = this->remaining();
  if(bufferSize > max)
    bufferSize = max;

  int result = this->mInputBuffer->put(buffer, bufferSize);
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
int InputBufferLimit::limit(int value){
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
int InputBufferLimit::limit(void){
  return this->mLimit;
}

/**
 * @brief 
 * 
 * @param value 
 * @return int 
 */
int InputBufferLimit::position(int value){
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
int InputBufferLimit::position(void){
  return this->mPosition;
}

/**
 * @brief 
 * 
 */
void InputBufferLimit::flush(void){
  this->mPosition = 0;
  return;
}

/**
 * @brief Get the Input Buffer object
 * 
 * @return mcuf::InputBuffer* 
 */
mcuf::InputBuffer* InputBufferLimit::getInputBuffer(void){
  return this->mInputBuffer;
}

/**
 * @brief 
 * 
 * @param inputBuffer 
 * @return mcuf::InputBuffer* 
 */
mcuf::InputBuffer* InputBufferLimit::setInputBuffer(mcuf::InputBuffer* inputBuffer){
  mcuf::InputBuffer* temp = this->mInputBuffer;
  this->mInputBuffer = inputBuffer;
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
