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
#include "mcuf/Resources.hpp"
#include "mcuf/lang/String.hpp"

/* ****************************************************************************************
 * Macro
 */  
#define STRING_MEMORY (static_cast<char*>(mcuf::Resources::STRING_FORMAT_MEMORY))
#define STRING_MEMORY_SIZE (mcuf::Resources::STRING_FORMAT_MEMORY_SIZE)

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
 * Construct.
 */
String::String(uint32_t size) construct Memory(size){
  return;
}

/**
 * Construct.
 */
String::String(const char* str) construct Memory(str, strlen(str)){
  return;
}

/**
 * Construct.
 */
String::String(Memory& memory) construct Memory(memory){
  return;
}

/**
 * Construct.
 */
String::String(Memory&& memory) construct Memory(memory){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/**
 * 
 */
String String::format(const char* format, va_list args){
  int len = vsnprintf(STRING_MEMORY, STRING_MEMORY_SIZE, format, args);
  String result = String(len);
  result.copy(STRING_MEMORY, len);
  return result;
}

/**
 * 
 */
String String::format(const char* format, ...){
  va_list args;
  va_start(args, format);
  String result = String::format(format, args);
  va_end(args);
  return result;
}
 
/* ****************************************************************************************
 * Public Method <Override>
 */

/**
 *
 */
uint32_t String::length(void){
  uint32_t result = strlen(static_cast<const char*>(this->mPointer));
  if(result >= this->Memory::mLength)
    result = this->Memory::mLength;
  
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
