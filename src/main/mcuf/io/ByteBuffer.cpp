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
using mcuf::io::InputBuffer;
using mcuf::io::OutputBuffer;
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
  this->flush();
  return;
}

/**
 * @brief Construct a new Byte Buffer:: Byte Buffer object
 * 
 * @param length 
 */
ByteBuffer::ByteBuffer(size_t length) : Memory(length){
  this->flush();
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
 * Public Method <Override> - mcuf::lang::Memory
 */

/**
 * @brief 
 * 
 * @param ch 
 * @return int 
 */
int ByteBuffer::indexOf(char ch) const{
  return ByteBuffer::indexOf(ch, 0);
}

/**
 * @brief 
 * 
 * @param ch 
 * @param offset 
 * @return int 
 */
int ByteBuffer::indexOf(char ch, int start) const{
  return Pointer::indexOf(ch, start, this->limit());
}

/**
 * @brief 
 * 
 * @param destination 
 * @param destinationLen 
 * @param start 
 * @return int 
 */
int ByteBuffer::indexOfData(const void* destination, int destinationLen, int start) const{
  return Pointer::indexOfData(destination, destinationLen, start, this->limit());
}

/**
 * @brief 
 * 
 * @param str 
 * @return int 
 */
int ByteBuffer::indexOfString(const char* str) const{
  return Pointer::indexOfString(str, this->limit());
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::io::OutputBufferBuffer
 */

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
  this->position(this->position() + 1);
  return true;
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @return int 
 */
int ByteBuffer::get(InputBuffer& inputBuffer){
  int len = this->avariable();
  len = inputBuffer.put(this->pointer(this->mPosition), len);
  this->position(this->position() + len);

  return len;
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @return int 
 */
int ByteBuffer::get(mcuf::io::InputBuffer& inputBuffer, int length){
  int max = this->avariable();
  if(length > max)
    length = max;
  
  int result = inputBuffer.put(this->pointer(this->mPosition), length);
  this->position(this->position() + result);

  return result;
}

/**
 * @brief 
 * 
 * @param buffer 
 * @param bufferSize 
 * @return int 
 */
int ByteBuffer::get(void* buffer, int bufferSize){
  int max = this->avariable();
  int pos = this->position();
  if(bufferSize > max)
    bufferSize = max;

  this->copyTo(buffer, pos, bufferSize);
  this->position(pos + bufferSize);
  return bufferSize;
}

/**
 * @brief 
 * 
 * @param value 
 * @return int 
 */
int ByteBuffer::skip(int value){
  int max = this->avariable();
  if(value > max)
    value = max;
  
  this->position(this->position() + value);
  return value;
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::io::InputBuffer
 */

/**
 * @brief 
 * 
 * @param value 
 * @return true 
 * @return false 
 */
bool ByteBuffer::putByte(const char value){
  if(this->mPosition >= this->mLimit)
    return false;
  
  *static_cast<uint8_t*>(this->pointer(this->mPosition++)) = value;
  return true;
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @return int 
 */
int ByteBuffer::put(OutputBuffer& outputBuffer){
  int len = this->remaining();
  len = outputBuffer.get(this->pointer(this->mPosition), len);
  this->position(this->position() + len);
  return len;
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @param length 
 * @return int 
 */
int ByteBuffer::put(OutputBuffer& outputBuffer, int length){
  if(length <= 0)
    return 0;
  
  int max = this->remaining();
  if(length > max)
    length = max;
  
  int result = outputBuffer.get(this->pointer(this->mPosition), length);
  this->position(this->position() + result);
  return result;
}

/**
 * @brief 
 * 
 * @param ptr 
 * @param size 
 * @return true 
 * @return false 
 */
int ByteBuffer::put(const void* buffer, int bufferSize){
  if(bufferSize <= 0)
    return false;  
  
  int max = this->remaining();
  
  if(bufferSize > max)
    bufferSize = max;
  
  this->copy(buffer, 0, this->mPosition, bufferSize);
  this->position(this->position() + bufferSize);
  
  return bufferSize;
}

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
bool ByteBuffer::limit(int newLimit){
  if(newLimit < 0)
    return false;
  
  if(newLimit > this->length())
    return false;
  
  this->mLimit = newLimit;
  return true;
}

/**
 * @brief 
 * 
 * @param newPosition 
 * @return true 
 * @return false 
 */
bool ByteBuffer::position(int newPosition){
  if(newPosition < 0)
    return false;
  
  if(newPosition > this->limit())
    return false;
  
  this->mPosition = newPosition;
  return true;
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
  return this->put(string, static_cast<int>(strlen(string)));
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
 * @param value 
 * @return true 
 * @return false 
 */
bool ByteBuffer::putFloat(const float value){
  const int* i = reinterpret_cast<const int*>(&value);
  return this->putInt(*i);
}

/**
 * @brief 
 * 
 * @param value 
 * @return true 
 * @return false 
 */
bool ByteBuffer::putFloatMsb(const float value){
  const int* i = reinterpret_cast<const int*>(&value);
  return this->putIntMsb(*i);
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

/**
 * @brief Get the Float object
 * 
 * @param result 
 * @return true 
 * @return false 
 */
bool ByteBuffer::getFloat(float& result){
  int* r = reinterpret_cast<int*>(&result);
  return this->getInt(*r);
}

/**
 * @brief 
 * 
 */
bool ByteBuffer::getFloatMsb(float& result){
  int* r = reinterpret_cast<int*>(&result);
  return this->getIntMsb(*r);
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
