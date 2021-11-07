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
 * Using
 */  
using mcuf::lang::String;
using mcuf::lang::System;
using mcuf::lang::Memory;

/* ****************************************************************************************
 * Variable
 */

Memory String::mCache = Memory(mcuf::Resources::STRING_FORMAT_MEMORY, 
                               mcuf::Resources::STRING_FORMAT_MEMORY_SIZE);

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
  int len = vsnprintf((char*)mCache.pointer(), mCache.length(), format, args);
  String result = String(len);
  result.copy(mCache.pointer(), len);
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
