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
#include "mcuf.h"

/* ****************************************************************************************
 * Using
 */  
using mcuf::io::channel::ByteBuffer;
using mcuf::lang::Memory;
using mcuf::lang::System;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
ByteBuffer::ByteBuffer(Memory&& memory) construct Memory(memory){
  this->mLimit = this->mLength;
  this->mPosition = 0;
  this->mMark = 0;
  return;
}

/**
 * 
 */
ByteBuffer::ByteBuffer(Memory& memory) construct ByteBuffer(&memory){
  return;
}

/**
 *
 */
ByteBuffer::ByteBuffer(size_t size) construct ByteBuffer(System::allocMemory(size)){
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
 * 
 */
uint8_t* ByteBuffer::lowerArray(void){
  return static_cast<uint8_t*>(this->mPointer);
}

/**
 * 
 */
uint8_t* ByteBuffer::lowerArray(uint32_t offset){
  if(offset >= this->mCapacity)
    return nullptr;
  
  return &static_cast<uint8_t*>(this->mPointer)[offset];
}

/**
 * 
 */
uint32_t ByteBuffer::limit(void){
  return this->mLimit;
}

/**
 * 
 */
ByteBuffer& ByteBuffer::limit(uint32_t newLimit){
  this->mLimit = newLimit;
  
  if(this->mLimit >= this->mCapacity)
    this->mLimit = this->mCapacity;
  
  return *this;
}

/**
 * 
 */
uint32_t ByteBuffer::capacity(void){
  return this->mCapacity;
}

/**
 * 
 */
uint32_t ByteBuffer::position(void){
  return this->mPosition;
}

/**
 * 
 */
ByteBuffer& ByteBuffer::position(uint32_t newPosition){
  this->mPosition = newPosition;
  if(this->mPosition >= this->mLimit)
     this->mPosition = this->mLimit;
    
  return *this;
}

/**
 * 
 */
bool ByteBuffer::readOnly(void){
  return false;
}

/**
 * 
 */
ByteBuffer& ByteBuffer::reset(void){
  this->mPosition = 0;
  this->mLimit = this->mCapacity;
  return *this;
}

/**
 * 
 */
ByteBuffer& ByteBuffer::flip(void){
  this->mLimit = this->mPosition;
  this->mPosition = 0;
  return *this;
}
/**
 * 
 */
uint32_t ByteBuffer::remaining(void){
  return this->mLimit - this->mPosition;
}

/**
 * 
 */
bool ByteBuffer::hasRemaining(void){
  return (this->mLimit > this->mPosition);
}

/**
 * 
 */
ByteBuffer& ByteBuffer::rewind(void){
  this->mPosition = 0;
  this->mMark = 0;
  return *this;
}

/**
 * 
 */
ByteBuffer& ByteBuffer::putByte(char value){
  if(this->mPosition >= this->mLimit)
    return *this;
  static_cast<uint8_t*>(this->mPointer)[this->mPosition] = value;
  this->mPosition++;
  return *this;
}

/**
 * 
 */
char ByteBuffer::getByte(void){
  if(this->mPosition >= this->mLimit)
    return 0;
  
  return static_cast<uint8_t*>(this->mPointer)[this->mPosition++];
}

/**
 * 
 */
ByteBuffer& ByteBuffer::putShort(short value){
  if((this->mPosition + 1) >= this->mLimit)
    return *this;
  static_cast<uint8_t*>(this->mPointer)[this->mPosition++] = (uint8_t)(value >> 8);
  static_cast<uint8_t*>(this->mPointer)[this->mPosition++] = (uint8_t)(value);
  return *this;
}

/**
 * 
 */
short ByteBuffer::getShort(void){
  if((this->mPosition + 1) >= this->mLimit)
    return 0;
  short result = 0;
  result |= (((short)static_cast<uint8_t*>(this->mPointer)[this->mPosition++]) << 8);
  result |= (((short)static_cast<uint8_t*>(this->mPointer)[this->mPosition++]));
  return result;
}

/**
 * 
 */
ByteBuffer& ByteBuffer::putInt(int value){
  if((this->mPosition + 3) >= this->mLimit)
    return *this;
  
  static_cast<uint8_t*>(this->mPointer)[this->mPosition++] = (uint8_t)(value >> 24);
  static_cast<uint8_t*>(this->mPointer)[this->mPosition++] = (uint8_t)(value >> 16);
  static_cast<uint8_t*>(this->mPointer)[this->mPosition++] = (uint8_t)(value >> 8);
  static_cast<uint8_t*>(this->mPointer)[this->mPosition++] = (uint8_t)(value);
  return *this;
}

/**
 * 
 */
int ByteBuffer::getInt(void){
  if((this->mPosition + 3) >= this->mLimit)
    return 0;
  
  int result = 0;
  result |= (((int)static_cast<uint8_t*>(this->mPointer)[this->mPosition++]) << 24);
  result |= (((int)static_cast<uint8_t*>(this->mPointer)[this->mPosition++]) << 16);
  result |= (((int)static_cast<uint8_t*>(this->mPointer)[this->mPosition++]) << 8);
  result |= (((int)static_cast<uint8_t*>(this->mPointer)[this->mPosition++]));
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
 