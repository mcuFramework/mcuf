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
ByteBuffer::ByteBuffer(const Memory& memory) construct Memory(memory){
  this->mLimit = this->length();
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
bool ByteBuffer::limit(uint32_t newLimit){
  if(newLimit > this->length())
    return false;  
  
  this->mLimit = newLimit;
  return true;
}

/**
 * 
 */
bool ByteBuffer::position(uint32_t newPosition){
  this->mPosition = newPosition;
  if(this->mPosition >= this->mLimit){
     this->mPosition = this->mLimit;
    return true;
  }
    
  return false;
}

/**
 * 
 */
void ByteBuffer::flip(void){
  this->mLimit = this->mPosition;
  this->mPosition = 0;
  return;
}

/**
 *
 */
bool ByteBuffer::put(char const* string){
  return this->put(string, strlen(string));
}

/**
 *
 */
bool ByteBuffer::put(const void* ptr, uint32_t size){
  if(size == 0)
    return false;  
  
  uint32_t rem = this->remaining();
  if(size > rem)
    size = rem;
  
  this->copy(ptr, size);
  this->mPosition += size;
  return true;
}

/**
 *
 */
bool ByteBuffer::put(const String& string){
  return this->put(string.pointer(), string.length());
}

/**
 * 
 */
bool ByteBuffer::putByte(char value){
  if(this->mPosition >= this->mLimit)
    return false;
  
  static_cast<uint8_t*>(this->pointer())[this->mPosition] = value;
  this->mPosition++;
  return true;
}

/**
 * 
 */
bool ByteBuffer::putShort(short value){
  if((this->mPosition + 1) >= this->mLimit)
    return false;
  
  uint8_t* ptr = static_cast<uint8_t*>(this->pointer());
  
  ptr[this->mPosition++] = (uint8_t)(value >> 8);
  ptr[this->mPosition++] = (uint8_t)(value);
  
  return true;
}

/**
 * 
 */
bool ByteBuffer::putShortLsb(short value){
  if((this->mPosition + 1) >= this->mLimit)
    return false;
  
  *static_cast<short*>(this->pointer(this->mPosition)) = value;
  this->mPosition+=2;
  
  return true;
}

/**
 * 
 */
bool ByteBuffer::putInt(int value){
  if((this->mPosition + 3) >= this->mLimit)
    return false;
  
  uint8_t* ptr = static_cast<uint8_t*>(this->pointer());
  
  ptr[this->mPosition++] = (uint8_t)(value >> 24);
  ptr[this->mPosition++] = (uint8_t)(value >> 16);
  ptr[this->mPosition++] = (uint8_t)(value >> 8);
  ptr[this->mPosition++] = (uint8_t)(value);
  
  return true;
}

/**
 * 
 */
bool ByteBuffer::putIntLsb(int value){
  if((this->mPosition + 3) >= this->mLimit)
    return false;
  
  *static_cast<int*>(this->pointer(this->mPosition)) = value;
  this->mPosition+=4;
  
  return true;
}

/**
 * 
 */
bool ByteBuffer::getByte(char& result){
  if(this->mPosition >= this->mLimit)
    return false;
  
  result = static_cast<uint8_t*>(this->pointer())[this->mPosition++];
  return true;
}

/**
 * 
 */
bool ByteBuffer::getShort(short& result){
  if((this->mPosition + 1) >= this->mLimit)
    return false;
  
  uint8_t* ptr = static_cast<uint8_t*>(this->pointer());
  
  result = 0;
  result |= (((short)ptr[this->mPosition++]) << 8);
  result |= (((short)ptr[this->mPosition++]));
  
  return true;
}

/**
 *
 */
bool ByteBuffer::getShortLsb(short& result){
  if((this->mPosition + 1) >= this->mLimit)
    return false;
  
  result = *static_cast<short*>(this->pointer(this->mPosition));
  this->mPosition+=2;
  
  return true;
}

/**
 * 
 */
bool ByteBuffer::getInt(int& result){
  if((this->mPosition + 3) >= this->mLimit)
    return false;
  
  uint8_t* ptr = static_cast<uint8_t*>(this->pointer());
  
  result = 0;
  result |= (((int)ptr[this->mPosition++]) << 24);
  result |= (((int)ptr[this->mPosition++]) << 16);
  result |= (((int)ptr[this->mPosition++]) << 8);
  result |= (((int)ptr[this->mPosition++]));
  
  return true;
}

/**
 *
 */
bool ByteBuffer::getIntLsb(int& result){
  if((this->mPosition + 3) >= this->mLimit)
    return false;
  
  result = *static_cast<int*>(this->pointer(this->mPosition));
  this->mPosition+=4;

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
 