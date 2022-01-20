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
#include "mcuf/lang/String.hpp"

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
 * Construct.
 */
String::String(void* pointer, uint32_t size) construct Memory(pointer, size){
  this->mSize = 0;
  return;
}

/**
 * Construct.
 */
String::String(const char* str) construct Memory(str, strlen(str)){
  this->mSize = this->length();
  return;
}

/**
 * Construct.
 */
String::String(const Memory& memory) construct Memory(memory){
  if(this->isReadOnly())
    this->mSize = strlen(static_cast<const char*>(this->pointer()));
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
int String::format(const char* format, va_list args){
  if(this->isReadOnly())
    return 0;  
  
  this->mSize = vsnprintf(static_cast<char*>(this->pointer()), this->length(), format, args);
  return this->mSize;
}

/**
 * 
 */
int String::format(const char* format, ...){
  if(this->isReadOnly())
    return 0;
  
  va_list args;
  va_start(args, format);
  this->mSize = vsnprintf(static_cast<char*>(this->pointer()), this->length(), format, args);
  va_end(args);
  return this->mSize;
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
