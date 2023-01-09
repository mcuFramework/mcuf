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
 * @brief 將data輸入至InputBuffer
 * 
 * @param data 資料來源
 * @return true 成功將data輸入至InputBuffer
 * @return false InputBuffer已滿
 */
bool StreamSkipper::putByte(const char result){
  if(this->isFull())
    return false;

  ++this->mPosition;
  return true;
}

/**
 * @brief 將outputBuffer內資料輸入至InputBuffer
 * 
 * @param byteBuffer 資料來源
 * @return int 移動資料數量(byte)
 */
int StreamSkipper::put(OutputBuffer& outputBuffer){
  int result = outputBuffer.skip(this->remaining());
  this->mPosition += result;
  return result;
}

/**
 * @brief 將outputBuffer內資料輸入至InputBuffer並指定輸入長度
 * 
 * @param byteBuffer 資料來源
 * @param length 輸入長度
 * @return int 移動資料數量(byte)
 */
int StreamSkipper::put(OutputBuffer& outputBuffer, int length){
  int max = this->remaining();
  if(length > max)
    length = max;
  
  int result = outputBuffer.skip(length);
  this->mPosition += result;
  return result;
}   

/**
 * @brief 將buffer內資料輸入至InputBuffer
 * 
 * @param buffer 資料來源
 * @param length 輸入長度
 * @return int 移動資料數量(byte)
 */
int StreamSkipper::put(const void* buffer, int length){
  if(this->isFull())
    return 0;

  int result = this->remaining();
  if(result > length)
    result = length;

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
