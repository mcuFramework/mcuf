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
 * Construct.
 */
String::String(void* pointer, uint32_t size) : Memory(pointer, size){
  this->mSize = 0;
  return;
}

/**
 * Construct.
 */
String::String(const char* str) : Memory(str, strlen(str)){
  this->mSize = this->length();
  return;
}

/**
 * Construct.
 */
String::String(const Memory& memory) : Memory(memory){
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
 * @brief 
 * 
 * @param buffer 
 * @param bufferSize 
 * @param format 
 * @param arg 
 * @return int 
 */
int String::format(void* buffer, uint32_t bufferSize, const char* format, va_list args){
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
int format(const mcuf::lang::Memory& memory, const char* format, va_list args){
  if(memory.isReadOnly())
    return 0;

  return vsnprintf(static_cast<char*>(memory.pointer()), memory.length(), format, args);
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
  int result = vsnprintf(static_cast<char*>(memory.pointer()), memory.length(), format, args);
  va_end(args);
  return result;
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
  
  this->mSize = vsnprintf(static_cast<char*>(this->pointer()), this->length(), format, args);
  return this->mSize;
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
  this->mSize = vsnprintf(static_cast<char*>(this->pointer()), this->length(), format, args);
  va_end(args);
  return this->mSize;
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
