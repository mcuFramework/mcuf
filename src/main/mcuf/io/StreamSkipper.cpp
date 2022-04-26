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
#include "mcuf/io/StreamSkipper.h"
#include "mcuf/io/OutputBuffer.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::io::StreamSkipper;
using mcuf::io::OutputBuffer;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Stream Skipper object
 * 
 */
StreamSkipper::StreamSkipper(void){
  this->mPosition = 0;
  this->mCapacity = 0;
  return;
}

/**
 * @brief Destroy the Stream Skipper object
 * 
 */
StreamSkipper::~StreamSkipper(void){
  this->mPosition = 0;
  this->mCapacity = 0;
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - mcuf::io::InputBuffer
 */

/**
 * @brief pop buffer byte non blocking.
 * 
 * @param result 
 * @return true has data in buffer.
 * @return false no data in buffer.
 */
bool StreamSkipper::putByte(const char result){
  if(this->isFull())
    return false;

  ++this->mPosition;
  return true;
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @return int 
 */
int StreamSkipper::put(OutputBuffer& outputBuffer){
  int result = outputBuffer.skip(this->remaining());
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
int StreamSkipper::put(const void* buffer, int bufferSize){
  if(this->isFull())
    return 0;

  int result = this->remaining();
  if(result > bufferSize)
    result = bufferSize;

  this->mPosition += result;
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
