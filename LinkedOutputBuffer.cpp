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
#include "mcuf/LinkedOutputBuffer.h"
#include "mcuf/Pointer.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::LinkedOutputBuffer;
using mcuf::OutputBuffer;
using mcuf::Pointer;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Linked Output Buffer object
 * 
 * @param current 
 */
LinkedOutputBuffer::LinkedOutputBuffer(OutputBuffer& current) : 
mCurrent(current){
  this->mNext = nullptr;
  return;
}

/**
 * @brief Construct a new Linked Output Buffer object
 * 
 * @param current 
 * @param next 
 */
LinkedOutputBuffer::LinkedOutputBuffer(OutputBuffer& current, OutputBuffer& next) : 
mCurrent(current){
  this->mNext = &next;
  return;
}

/**
 * @brief Destroy the Linked Output Buffer object
 * 
 */
LinkedOutputBuffer::~LinkedOutputBuffer(void){
  this->mNext = nullptr;
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
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool LinkedOutputBuffer::isEmpty(void) const{
  if(this->mCurrent.isEmpty() == false)
    return false;

  if(this->mNext == nullptr)
    return false;
  
  return this->mNext->isEmpty();
}
/**
 * @brief 
 * 
 * @return int 
 */
int LinkedOutputBuffer::avariable(void) const{
  int result = this->mCurrent.avariable();
  if(this->mNext != nullptr)
    result += this->mNext->avariable();

  return result;
}
/**
 * @brief pop buffer byte non blocking.
 * 
 * @param result 
 * @return true has data in buffer.
 * @return false no data in buffer.
 */
bool LinkedOutputBuffer::getByte(char& result){
  if(this->mCurrent.getByte(result))
    return true;

  if(this->mNext == nullptr)
    return false;

  return this->mNext->getByte(result);
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @return int 
 */
int LinkedOutputBuffer::get(mcuf::InputBuffer& inputBuffer){
  int result = this->mCurrent.get(inputBuffer);
  if(this->mNext != nullptr)
    result += this->mNext->get(inputBuffer);
  
  return result;
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @return int 
 */
int LinkedOutputBuffer::get(mcuf::InputBuffer& inputBuffer, int length){
  int result = this->mCurrent.get(inputBuffer, length);
  length -= result;
  
  if(this->mNext != nullptr)
    result += this->mNext->get(inputBuffer, length);
  
  return result;
}

/**
 * @brief 
 * 
 * @param buffer 
 * @param bufferSize 
 * @return int 
 */
int LinkedOutputBuffer::get(void* buffer, int bufferSize){
  int result = this->mCurrent.get(buffer, bufferSize);
  if(this->mNext != nullptr)
    result += this->mNext->get(Pointer::pointShift(buffer, result), bufferSize - result);

  return result;
}

/**
 * @brief 
 * 
 * @param value 
 * @return int 
 */
int LinkedOutputBuffer::skip(int value){
  int result = this->mCurrent.skip(value);
  if(this->mNext != nullptr)
    result += this->mNext->skip(value - result);
  
  return result;
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

/* ****************************************************************************************
 * End of file
 */
