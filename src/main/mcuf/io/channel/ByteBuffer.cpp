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
#include "mcuf/io/channel/ByteBuffer.hpp"

/* ****************************************************************************************
 * Using
 */  
using mcuf::io::channel::ByteBuffer;
using mcuf::lang::Memory;
using mcuf::lang::System;
using mcuf::lang::String;

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
ByteBuffer::ByteBuffer(Memory& memory) construct Memory(memory){
  this->mLimit = this->mLength;
  this->mPosition = 0;
  this->mMark = 0;  
  return;
}

/**
 *
 */
ByteBuffer::ByteBuffer(uint32_t size) construct Memory(size){
  this->mLimit = this->mLength;
  this->mPosition = 0;
  this->mMark = 0;  
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
  if(offset >= this->mLength)
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
  
  if(this->mLimit >= this->mLength)
    this->mLimit = this->mLength;
  
  return *this;
}

/**
 * 
 */
uint32_t ByteBuffer::capacity(void){
  return this->mLength;
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
  this->mLimit = this->mLength;
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
ByteBuffer& ByteBuffer::put(char const* string){
  return this->put(string, strlen(string));
}

/**
 *
 */
ByteBuffer& ByteBuffer::put(const void* ptr, uint32_t size){
  if(size == 0)
    return *this;  
  
  uint32_t rem = this->remaining();
  if(size > rem)
    size = rem;
  
  this->copy(ptr, size);
  this->mPosition += size;
  return *this;
}

/**
 *
 */
ByteBuffer& ByteBuffer::put(String& string){
  return this->put(string.pointer(), string.length());
}

/**
 *
 */
ByteBuffer& ByteBuffer::putArray(mcuf::lang::ArrayPrototype& arrayPrototype){
  uint32_t size = arrayPrototype.getElementSize() * arrayPrototype.getElementLength();
  return this->put(arrayPrototype.pointer(), size);
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
ByteBuffer& ByteBuffer::putShort(short value){
  if((this->mPosition + 1) >= this->mLimit)
    return *this;
  
  uint8_t* ptr = static_cast<uint8_t*>(this->mPointer);
  
  ptr[this->mPosition++] = (uint8_t)(value >> 8);
  ptr[this->mPosition++] = (uint8_t)(value);
  
  return *this;
}

/**
 * 
 */
ByteBuffer& ByteBuffer::putShortLsb(short value){
  if((this->mPosition + 1) >= this->mLimit)
    return *this;
  
  *static_cast<short*>(this->pointer(this->mPosition)) = value;
  this->mPosition+=2;
  
  return *this;
}

/**
 * 
 */
ByteBuffer& ByteBuffer::putInt(int value){
  if((this->mPosition + 3) >= this->mLimit)
    return *this;
  
  uint8_t* ptr = static_cast<uint8_t*>(this->mPointer);
  
  ptr[this->mPosition++] = (uint8_t)(value >> 24);
  ptr[this->mPosition++] = (uint8_t)(value >> 16);
  ptr[this->mPosition++] = (uint8_t)(value >> 8);
  ptr[this->mPosition++] = (uint8_t)(value);
  
  return *this;
}

/**
 * 
 */
ByteBuffer& ByteBuffer::putIntLsb(int value){
  if((this->mPosition + 3) >= this->mLimit)
    return *this;
  
  *static_cast<int*>(this->pointer(this->mPosition)) = value;
  this->mPosition+=4;
  
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
short ByteBuffer::getShort(void){
  if((this->mPosition + 1) >= this->mLimit)
    return 0;
  
  uint8_t* ptr = static_cast<uint8_t*>(this->mPointer);
  short result = 0;
  
  result |= (((short)ptr[this->mPosition++]) << 8);
  result |= (((short)ptr[this->mPosition++]));
  
  return result;
}

/**
 *
 */
short ByteBuffer::getShortLsb(void){
  if((this->mPosition + 1) >= this->mLimit)
    return 0;
  
  void* ptr = &static_cast<uint8_t*>(this->mPointer)[this->mPosition];
  this->mPosition+=2;

  return *static_cast<short*>(ptr);
}

/**
 * 
 */
int ByteBuffer::getInt(void){
  if((this->mPosition + 3) >= this->mLimit)
    return 0;
  
  uint8_t* ptr = static_cast<uint8_t*>(this->mPointer);
  int result = 0;
  result |= (((int)ptr[this->mPosition++]) << 24);
  result |= (((int)ptr[this->mPosition++]) << 16);
  result |= (((int)ptr[this->mPosition++]) << 8);
  result |= (((int)ptr[this->mPosition++]));
  return result;
}

/**
 *
 */
int ByteBuffer::getIntLsb(void){
  if((this->mPosition + 3) >= this->mLimit)
    return 0;
  
  void* ptr = &static_cast<uint8_t*>(this->mPointer)[this->mPosition];
  this->mPosition+=4;

  return *static_cast<int*>(ptr);
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
 