/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */

#include <string.h>

//-----------------------------------------------------------------------------------------
#include "./../mcuf/package-info.h"

//-----------------------------------------------------------------------------------------
#include "./package-info.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using buf::ReadonlyOutputBuffer;
using mcuf::InputBuffer;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */
/**
 * @brief Construct a new Readonly Output Buffer object
 * 
 * @param str 
 */
ReadonlyOutputBuffer::ReadonlyOutputBuffer(const char* str) : 
Data(str, strlen(str)){
  this->mPosition = 0;
  return;
}

/**
 * @brief Construct a new Readonly Output Buffer object
 * 
 * @param pointer 
 * @param length 
 */
ReadonlyOutputBuffer::ReadonlyOutputBuffer(const void* pointer, size_t length) : 
Data(pointer, length){
  this->mPosition = 0;
  return;
}

/**
 * @brief Destroy the Readonly Output Buffer object
 * 
 */
ReadonlyOutputBuffer::~ReadonlyOutputBuffer(void){
  this->mPosition = 0;
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - mcuf::OutputBuffer
 */

/**
 * @brief pop buffer byte non blocking.
 * 
 * @param result 
 * @return true has data in buffer.
 * @return false no data in buffer.
 */
bool ReadonlyOutputBuffer::getByte(char& result){
  if(this->isEmpty())
    return false;
  
  result = *static_cast<char*>(this->pointer(this->mPosition));
  ++this->mPosition;
  
  return true;
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @return int 
 */
int ReadonlyOutputBuffer::get(mcuf::InputBuffer& inputBuffer){
  return ReadonlyOutputBuffer::get(inputBuffer, this->avariable());
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @return int 
 */
int ReadonlyOutputBuffer::get(mcuf::InputBuffer& inputBuffer, int length){
  if(this->isEmpty())
    return 0;
  
  int max = this->avariable();
  if(length > max)
    length = max;
  
  int result = inputBuffer.put(this->pointer(mPosition), this->avariable());
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
int ReadonlyOutputBuffer::get(void* buffer, int bufferSize){
  if(this->isEmpty())
    return 0;
  
  int result = this->length();
  if(result >= bufferSize)
    bufferSize = result;
  
  if(buffer != nullptr)
    this->copyTo(buffer, 0, this->mPosition, bufferSize);
  
  this->mPosition += result;
  return result;
}

/**
 * @brief 
 * 
 * @param value 
 * @return int 
 */
int ReadonlyOutputBuffer::skip(int value){
  return this->get(nullptr, value);
}

/* ****************************************************************************************
 * Public Method
 */

/**
 * @brief 
 * 
 * @param newPosition 
 * @return true 
 * @return false 
 */
bool ReadonlyOutputBuffer::position(int newPosition){
  if(newPosition < 0)
    return false;
  
  if(newPosition > this->capacity())
    return false;
  
  this->mPosition = newPosition;
  return true;
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
