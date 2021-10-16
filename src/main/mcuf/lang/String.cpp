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
#include "mcuf.h"

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::String;
using mcuf::lang::System;
using mcuf::lang::Memory;
using mcuf::Resources;

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
  int len = vsnprintf((char*)Resources::system.string.point, Resources::system.string.size, format, args);
  String result = String(len);
  result.copy((char*)Resources::system.string.point, len);
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
