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
 * @brief ??????InputBuffer????????????
 * 
 * @return true ??????
 * @return false ?????????????????????
 */
bool LinkedInputBuffer::isFull(void) const {
  if(this->mCurrent.isFull() == false)
    return false;

  if(this->mNext == nullptr)
    return true;

  return this->mNext->isFull();
}

/**
 * @brief ??????InputBuffer???????????????
 * 
 * @return int InputBuffer???????????????
 */
int LinkedInputBuffer::remaining(void) const {
  int result = this->mCurrent.remaining();

  if(this->mNext != nullptr)
    result += this->mNext->remaining();

  return result;
}

/**
 * @brief ???data?????????InputBuffer
 * 
 * @param data ????????????
 * @return true ?????????data?????????InputBuffer
 * @return false InputBuffer??????
 */
bool LinkedInputBuffer::putByte(const char result){
  if(this->mCurrent.putByte(result) == true)
    return true;

  if(this->mNext == nullptr)
    return false;

  return this->mNext->putByte(result);
}

/**
 * @brief ???outputBuffer??????????????????InputBuffer
 * 
 * @param byteBuffer ????????????
 * @return int ??????????????????(byte)
 */
int LinkedInputBuffer::put(mcuf::io::OutputBuffer& outputBuffer){
  int result = this->mCurrent.put(outputBuffer);
  if(this->mNext != nullptr)
    result += this->mNext->put(outputBuffer);

  return result;
}

/**
 * @brief ???outputBuffer??????????????????InputBuffer?????????????????????
 * 
 * @param byteBuffer ????????????
 * @param length ????????????
 * @return int ??????????????????(byte)
 */
int LinkedInputBuffer::put(OutputBuffer& outputBuffer, int length){
  int result = this->mCurrent.put(outputBuffer, length);
  length -= result;
  
  if(this->mNext != nullptr)
    result += this->mNext->put(outputBuffer);

  return result;
}

/**
 * @brief ???buffer??????????????????InputBuffer
 * 
 * @param buffer ????????????
 * @param length ????????????
 * @return int ??????????????????(byte)
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
