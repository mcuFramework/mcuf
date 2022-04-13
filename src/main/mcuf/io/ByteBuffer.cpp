/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  

#include <stdio.h>
//-----------------------------------------------------------------------------------------
#include "mcuf/io/ByteBuffer.h"

/* ****************************************************************************************
 * Using
 */  
using mcuf::io::ByteBuffer;
using mcuf::lang::Memory;
using mcuf::lang::System;
using mcuf::lang::String;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Byte Buffer:: Byte Buffer object
 * 
 * @param memory 
 */
ByteBuffer::ByteBuffer(const Memory& memory) : Memory(memory){
  this->clear();
  return;
}

/**
 * @brief Construct a new Byte Buffer:: Byte Buffer object
 * 
 * @param length 
 */
ByteBuffer::ByteBuffer(size_t length) : Memory(length){
  this->clear();
  return;
}

/**
 * @brief Destroy the Byte Buffer:: Byte Buffer object
 * 
 */
ByteBuffer::~ByteBuffer(void){
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
 * @brief 
 * 
 * @param newLimit 
 * @return true 
 * @return false 
 */
bool ByteBuffer::limit(uint32_t newLimit){
  if(static_cast<uint16_t>(newLimit) > this->length())
    return false;
  
  this->mLimit = static_cast<uint16_t>(newLimit);
  return true;
}

/**
 * @brief 
 * 
 * @param newPosition 
 * @return true 
 * @return false 
 */
bool ByteBuffer::position(uint32_t newPosition){
  this->mPosition = static_cast<uint16_t>(newPosition);
  if(this->mPosition >= this->mLimit){
     this->mPosition = this->mLimit;
    return true;
  }
    
  return false;
}

/**
 * @brief 
 * 
 */
void ByteBuffer::flip(void){
  this->mLimit = this->mPosition;
  this->mPosition = 0;
  return;
}

/**
 * @brief 
 * 
 * @param string 
 * @return true 
 * @return false 
 */
bool ByteBuffer::put(char const* string){
  return this->put(string, strlen(string));
}

/**
 * @brief 
 * 
 * @param ptr 
 * @param size 
 * @return true 
 * @return false 
 */
bool ByteBuffer::put(const void* ptr, uint32_t size){
  if(size <= 0)
    return false;  
  
  uint32_t rem = this->remaining();
  if(size > rem)
    size = rem;
  
  this->copy(ptr, this->mPosition, size);
  this->mPosition += size;
  return true;
}

/**
 * @brief 
 * 
 * @param string 
 * @return true 
 * @return false 
 */
bool ByteBuffer::put(const String& string){
  return this->put(string.pointer(), string.size());
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @return true 
 * @return false 
 */
bool ByteBuffer::put(ByteBuffer& byteBuffer){
  uint32_t rem = byteBuffer.remaining();
  if(rem == 0)
    return true;
  
  void* start = byteBuffer.pointer(byteBuffer.position());
  bool result = this->put(start, rem);
  
  if(result)
    byteBuffer.position(byteBuffer.position() + rem);
  
  return result;
  
}

/**
 * @brief 
 * 
 * @param value 
 * @return true 
 * @return false 
 */
bool ByteBuffer::putByte(char value){
  if(this->mPosition >= this->mLimit)
    return false;
  
  *static_cast<uint8_t*>(this->pointer(this->mPosition++)) = value;
  return true;
}

/**
 * @brief 
 * 
 * @param format 
 * @param ... 
 * @return int 
 */
int ByteBuffer::putFormat(const char* format, ...){
  if(this->isReadOnly())
    return 0;
  
  va_list args;
  va_start(args, format);
  int result = String::format(this->pointer(this->mPosition), static_cast<size_t>(this->remaining()), format, args);
  
  va_end(args);
  
  this->mPosition += result;
  return result;
}

/**
 * @brief 
 * 
 * @param format 
 * @param args 
 * @return int 
 */
int ByteBuffer::putFormat(const char* format, va_list args){
  int result = String::format(this->pointer(this->mPosition), static_cast<size_t>(this->remaining()), format, args);
  this->mPosition += result;
  return result; 
}

/**
 * @brief 
 * 
 * @param value 
 * @return true 
 * @return false 
 */
bool ByteBuffer::putShort(short value){
  if((this->mPosition + 1) >= this->mLimit)
    return false;
  
  *static_cast<short*>(this->pointer(this->mPosition)) = value;
  this->mPosition+=2;
  
  return true;
}
/**
 * @brief 
 * 
 * @param value 
 * @return true 
 * @return false 
 */
bool ByteBuffer::putShortMsb(short value){
  if((this->mPosition + 1) >= this->mLimit)
    return false;
  
  uint8_t* ptr = static_cast<uint8_t*>(this->pointer());
  
  ptr[this->mPosition++] = static_cast<uint8_t>(value >> 8);
  ptr[this->mPosition++] = static_cast<uint8_t>(value);
  
  return true;
}

/**
 * @brief 
 * 
 * @param value 
 * @return true 
 * @return false 
 */
bool ByteBuffer::putInt(int value){
  if((this->mPosition + 3) >= this->mLimit)
    return false;
  
  *static_cast<int*>(this->pointer(this->mPosition)) = value;
  this->mPosition+=4;
  
  return true;
}

/**
 * @brief 
 * 
 * @param value 
 * @return true 
 * @return false 
 */
bool ByteBuffer::putIntMsb(int value){
  if((this->mPosition + 3) >= this->mLimit)
    return false;
  
  uint8_t* ptr = static_cast<uint8_t*>(this->pointer());
  
  ptr[this->mPosition++] = static_cast<uint8_t>(value >> 24);
  ptr[this->mPosition++] = static_cast<uint8_t>(value >> 16);
  ptr[this->mPosition++] = static_cast<uint8_t>(value >> 8);
  ptr[this->mPosition++] = static_cast<uint8_t>(value);
  
  return true;
}

/**
 * @brief 
 * 
 * @param result 
 * @return true 
 * @return false 
 */
bool ByteBuffer::getByte(char& result){
  if(this->mPosition >= this->mLimit)
    return false;
  
  result = *static_cast<uint8_t*>(this->pointer(this->mPosition));
  this->mPosition += 1;
  return true;
}

/**
 * @brief 
 * 
 * @param result 
 * @return true 
 * @return false 
 */
bool ByteBuffer::getShort(short& result){
  if((this->mPosition + 1) >= this->mLimit)
    return false;
  
  result = *static_cast<short*>(this->pointer(this->mPosition));
  this->mPosition += 2;
  
  return true;
}

/**
 * @brief 
 * 
 * @param result 
 * @return true 
 * @return false 
 */
bool ByteBuffer::getShortMsb(short& result){
  if((this->mPosition + 1) >= this->mLimit)
    return false;
  
  uint8_t* ptr = static_cast<uint8_t*>(this->pointer());
  
  result = 0;
  result |= (static_cast<short>(ptr[this->mPosition++]) << 8);
  result |= (static_cast<short>(ptr[this->mPosition++]));
  
  return true;
}

/**
 * @brief 
 * 
 * @param result 
 * @return true 
 * @return false 
 */
bool ByteBuffer::getInt(int& result){
  if((this->mPosition + 3) >= this->mLimit)
    return false;
  
  result = *static_cast<int*>(this->pointer(this->mPosition));
  this->mPosition+=4;

  return true;
}

/**
 * @brief 
 * 
 * @param result 
 * @return true 
 * @return false 
 */
bool ByteBuffer::getIntMsb(int& result){
  if((this->mPosition + 3) >= this->mLimit)
    return false;
  
  uint8_t* ptr = static_cast<uint8_t*>(this->pointer());
  
  result = 0;
  result |= (static_cast<int>(ptr[this->mPosition++]) << 24);
  result |= (static_cast<int>(ptr[this->mPosition++]) << 16);
  result |= (static_cast<int>(ptr[this->mPosition++]) << 8);
  result |= (static_cast<int>(ptr[this->mPosition++]));
  
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
