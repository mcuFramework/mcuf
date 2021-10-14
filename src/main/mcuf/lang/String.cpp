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
char String::emptyString = 0x00;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * Construct.
 */
String::String(const char* str) construct Memory(str){
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
  Memory memory = System::allocMemory(len);
  memory.copy((char*)Resources::system.string.point, len);
  return String(memory);
}

/**
 * 
 */
String String::format(const char* format, ...){
  va_list args;
  va_start(args, format);
  Memory memory = String::formatMemory(format, args);
  va_end(args);
  return String(memory);
}

/**
 *
 */
Memory String::formatMemory(const char* format, va_list args){
  int len = vsnprintf((char*)Resources::system.string.point, Resources::system.string.size, format, args);
  Memory memory = System::allocMemory(len);
  memory.copy((char*)Resources::system.string.point, len);
  return memory;
}

/**
 *
 */
Memory String::formatMemory(const char* format, ...){
  va_list args;
  va_start (args, format);
  Memory memory = String::formatMemory(format, args);
  va_end (args);
  return memory;
}
 
/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

/**
 * 
 */
const char* String::toPointer(void){
  if(this->mPointer == nullptr)
    return &String::emptyString;

  return static_cast<const char*>(this->mPointer);
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
