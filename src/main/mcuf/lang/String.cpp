/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */

#include <string.h>
#include <stdio.h>
//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "mcuf/lang/String.h"

/* ****************************************************************************************
 * Macro
 */  

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::String;
using mcuf::lang::System;
using mcuf::lang::Memory;

/* ****************************************************************************************
 * Variable
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new String:: String object
 * 
 * @param pointer 
 * @param size 
 */
String::String(void* pointer, uint32_t size) : Memory(pointer, size){
  return;
}

/**
 * @brief Construct a new String:: String object
 * 
 * @param str 
 */
String::String(const char* str) : Memory(str, strlen(str) + 1){
  return;
}

/**
 * @brief Construct a new String:: String object
 * 
 * @param length 
 */
String::String(size_t length) : Memory(length){
  return;
}

/**
 * @brief Construct a new String:: String object
 * 
 * @param memory 
 */
String::String(const Memory& memory) : Memory(memory){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/**
 * @brief 
 * 
 * @param buffer 
 * @param bufferSize 
 * @param format 
 * @param arg 
 * @return int 
 */
int String::format(void* buffer, size_t bufferSize, const char* format, va_list args){
  return vsnprintf(static_cast<char*>(buffer), bufferSize, format, args);
}

/**
 * @brief 
 * 
 * @param memory 
 * @param format 
 * @param arg 
 * @return int 
 */
int String::format(const mcuf::lang::Memory& memory, const char* format, va_list args){
  if(memory.isReadOnly())
    return 0;

  return vsnprintf(static_cast<char*>(memory.pointer()), static_cast<size_t>(memory.length()), format, args);
}

/**
 * @brief 
 * 
 * @param buffer 
 * @param bufferSize 
 * @param format 
 * @param ... 
 * @return int 
 */
int String::format(void* buffer, uint32_t bufferSize, const char* format, ...){
  va_list args;
  va_start(args, format);
  int result = vsnprintf(static_cast<char*>(buffer), bufferSize, format, args);
  va_end(args);
  return result;
}

/**
 * @brief 
 * 
 * @param memory 
 * @param format 
 * @param ... 
 * @return int 
 */
int String::format(const mcuf::lang::Memory& memory, const char* format, ...){
  if(memory.isReadOnly())
    return 0;
  
  va_list args;
  va_start(args, format);
  int result = vsnprintf(static_cast<char*>(memory.pointer()), static_cast<size_t>(memory.length()), format, args);
  va_end(args);
  return result;
}

/**
 * @brief 
 * 
 * @param bufferSize 
 * @param format 
 * @param ... 
 * @return String 
 */
String String::format(int bufferSize, const char* format, ...){
  String buffer = String(static_cast<size_t>(bufferSize));

  va_list args;
  va_start(args, format);  
  buffer.format(format, args);
  va_end(args);
  
  if(buffer.size() >= static_cast<uint32_t>((static_cast<float>(buffer.length()) * 0.9f)))
    return buffer;

  String result = String(buffer.size());
  result.copy(buffer, result.length());
  return result;
}

/**
 * @brief 
 * 
 * @return String 
 */
String String::empty(void){
  return String("\0");
}

/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

/**
 * @brief 
 * 
 * @param format 
 * @param args 
 * @return int 
 */
int String::format(const char* format, va_list args){
  if(this->isReadOnly())
    return 0;  
  
  int result = vsnprintf(static_cast<char*>(this->pointer()), static_cast<size_t>(this->length()), format, args);
  return result;
}

/**
 * @brief 
 * 
 * @param format 
 * @param ... 
 * @return int 
 */
int String::format(const char* format, ...){
  if(this->isReadOnly())
    return 0;
  
  va_list args;
  va_start(args, format);
  int result = vsnprintf(static_cast<char*>(this->pointer()), static_cast<size_t>(this->length()), format, args);
  va_end(args);
  return result;
}

/**
 * @brief 
 * 
 */
void String::convertUpper(void){
  uint32_t max = this->size();
  char* ptr = static_cast<char*>(this->pointer());

  for(uint32_t i=0; i<max; ++i){
    if((ptr[i] >= 'a') && (ptr[i] <= 'z')){
			ptr[i] -= 32;
		}
  }
}

/**
 * @brief 
 * 
 */
void String::convertLower(void){
  uint32_t max = this->size();
  char* ptr = static_cast<char*>(this->pointer());

  for(uint32_t i=0; i<max; ++i){
    if((ptr[i] >= 'A') && (ptr[i] <= 'Z')){
			ptr[i] += 32;
		}
  }
}

/**
 * @brief 
 * 
 * @return String 
 */
String String::toUpper(void) const{
  uint32_t max = this->size();
  String result = String(max + 1);

  const char* src = static_cast<char*>(this->pointer());
  char* dst = static_cast<char*>(result.pointer());

  for(uint32_t i=0; i<max; ++i){
    if((src[i] >= 'a') && (src[i] <= 'z'))
			dst[i] -= 32;

		else
      dst[i] = src[i];

  }
  result[max] = 0x00;
  return result;
}

/**
 * @brief 
 * 
 * @return String 
 */
String String::toLower(void) const{
  uint32_t max = this->size();
  String result = String(max + 1);

  const char* src = static_cast<char*>(this->pointer());
  char* dst = static_cast<char*>(result.pointer());

  for(uint32_t i=0; i<max; ++i){
    if((src[i] >= 'A') && (src[i] <= 'Z'))
			dst[i] -= 32;
      
		else
      dst[i] = src[i];

  }
  result[max] = 0x00;
  return result;
}

/**
 * @brief 
 * 
 * @param ch 
 * @return int 
 */
int String::indexOf(char ch) const{
  return this->indexOf(ch, 0);
}

/**
 * @brief 
 * 
 * @param ch 
 * @param offset 
 * @return int 
 */
int String::indexOf(char ch, uint32_t offset) const{
  uint32_t max = this->size();
  if(offset > static_cast<uint32_t>(max))
    return -1;
  
  const char* ptr = static_cast<const char*>(this->pointer(offset));
  max -= offset;
  for(uint32_t i=0; i<max; ++i){
    if(ptr[i] == ch)
      return static_cast<int>(i + offset);
  }
  return -1;
}

/**
 * @brief 
 * 
 * @return String 
 */
String String::clone(void) const{
  return this->clone(0, 0);
}

/**
 * @brief 
 * 
 * @param length 
 * @return String 
 */
String String::clone(uint32_t length) const{
  return this->clone(0, length);
}

/**
 * @brief 
 * 
 * @param offset 
 * @return String 
 */
String String::clone(uint32_t offset, uint32_t length) const{
  uint32_t size = this->size();
  if(offset >= size)
    return String::empty();

  if(length > size)
    length = size;

  String result = String(static_cast<size_t>(length + 1));
  result.copy(this->pointer(offset), 0, length);
  result[length] = 0x00;
  return result;
}

/**
 * @brief 
 * 
 * @return uint32_t 
 */
size_t String::size(void) const{
  uint32_t result = strlen(static_cast<const char*>(this->pointer()));
  
  if(result >= this->length())
    result = this->length();

  return static_cast<size_t>(result);
}

/**
 * @brief 
 * 
 * @param oldChar 
 * @param newChar 
 * @return int 
 */
int String::replace(char oldChar, char newChar){
  int result = 0;
  if(this->isReadOnly())
    return 0;
  
  uint32_t max = this->size();
  char* ptr = static_cast<char*>(this->pointer());
  for(uint32_t i=0; i<max; ++i){
    if(ptr[i] == oldChar){
      ptr[i] = newChar;
      ++result;
    }
  }
  
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
