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
#include "mcuf/io/LinkedInputBuffer.h"
#include "mcuf/lang/Pointer.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::io::LinkedInputBuffer;
using mcuf::io::InputBuffer;
using mcuf::lang::Pointer;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Linked Input Buffer object
 * 
 * @param current 
 */
LinkedInputBuffer::LinkedInputBuffer(InputBuffer& current) : 
mCurrent(current){
  this->mNext = nullptr;
  return;
}

/**
 * @brief Construct a new Linked Input Buffer object
 * 
 * @param current 
 * @param next 
 */
LinkedInputBuffer::LinkedInputBuffer(InputBuffer& current, InputBuffer* next) : 
mCurrent(current){
  this->mNext = next;
  return;
}

/**
 * @brief Destroy the Linked Input Buffer object
 * 
 */
LinkedInputBuffer::~LinkedInputBuffer(void){
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
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

/**
 * @brief 取得InputBuffer是否已滿
 * 
 * @return true 已滿
 * @return false 未滿，仍有空間
 */
bool LinkedInputBuffer::isFull(void) const {
  if(this->mCurrent.isFull() == false)
    return false;

  if(this->mNext == nullptr)
    return true;

  return this->mNext->isFull();
}

/**
 * @brief 取得InputBuffer內資料數量
 * 
 * @return int InputBuffer內資料數量
 */
int LinkedInputBuffer::remaining(void) const {
  int result = this->mCurrent.remaining();

  if(this->mNext != nullptr)
    result += this->mNext->remaining();

  return result;
}

/**
 * @brief 將data輸入至InputBuffer
 * 
 * @param data 資料來源
 * @return true 成功將data輸入至InputBuffer
 * @return false InputBuffer已滿
 */
bool LinkedInputBuffer::putByte(const char result){
  if(this->mCurrent.putByte(result) == true)
    return true;

  if(this->mNext == nullptr)
    return false;

  return this->mNext->putByte(result);
}

/**
 * @brief 將outputBuffer內資料輸入至InputBuffer
 * 
 * @param byteBuffer 資料來源
 * @return int 移動資料數量(byte)
 */
int LinkedInputBuffer::put(mcuf::io::OutputBuffer& outputBuffer){
  int result = this->mCurrent.put(outputBuffer);
  if(this->mNext != nullptr)
    result += this->mNext->put(outputBuffer);

  return result;
}

/**
 * @brief 將outputBuffer內資料輸入至InputBuffer並指定輸入長度
 * 
 * @param byteBuffer 資料來源
 * @param length 輸入長度
 * @return int 移動資料數量(byte)
 */
int LinkedInputBuffer::put(OutputBuffer& outputBuffer, int length){
  int result = this->mCurrent.put(outputBuffer, length);
  length -= result;
  
  if(this->mNext != nullptr)
    result += this->mNext->put(outputBuffer);

  return result;
}

/**
 * @brief 將buffer內資料輸入至InputBuffer
 * 
 * @param buffer 資料來源
 * @param length 輸入長度
 * @return int 移動資料數量(byte)
 */
int LinkedInputBuffer::put(const void* buffer, int bufferSize){
  int result = this->mCurrent.put(buffer, bufferSize);
  if(this->mNext != nullptr)
    result += this->mNext->put(Pointer::pointShift(buffer, result), bufferSize - result);

  return result;
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
