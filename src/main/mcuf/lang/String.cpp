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

#include "String.hpp"

#include "../lang/Memory.hpp"
#include "../lang/System.hpp"


/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::String;
using mcuf::lang::System;

/* ****************************************************************************************
 * Variable
 */
char String::handleMemory[MCUF_STRING_HANDLE_MEMORY_SIZE];
char String::emptyString = 0x00;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * Construct.
 */
String::String(char* str, uint32_t size){
  this->mPointer = str;
  this->mSize = size;
  return;
}

/**
 * Construct.
 */
String::String(const char* original){
  this->mPointer = (char*) original;
  this->mSize = 0;
  return;
}

/**
 * Construct.
 */
String::String(void){
  this->mPointer = nullptr;
  this->mSize = 0;
  return;
}

/**
 * Disconstruct.
 */
String::~String(void){
  if(this->mSize != 0)
    System::freePointer(this->mPointer, this->mSize);
  
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
  int len = vsnprintf(String::handleMemory, MCUF_STRING_HANDLE_MEMORY_SIZE, format, args);
  Memory memory = System::allocMemory(len);
  memory.copy(String::handleMemory, len);
  return String((char*)memory.mPointer, memory.mLength);
}

/**
 * 
 */
String String::format(const char* format, ...){
  va_list args;
  va_start (args, format);
  int len = vsnprintf(String::handleMemory, MCUF_STRING_HANDLE_MEMORY_SIZE, format, args);
  va_end (args);
  Memory memory = System::allocMemory(len);
  memory.copy(String::handleMemory, len);
  return String((char*)memory.mPointer, memory.mLength);
}

/**
 * 
 */
char* String::formatChar(const char* format, va_list args){
  int len = vsnprintf(String::handleMemory, MCUF_STRING_HANDLE_MEMORY_SIZE, format, args);
  Memory memory = System::allocMemory(len);
  memory.copy(String::handleMemory, len);
  return (char*)memory.pointer();
}

/**
 * 
 */
char* String::formatChar(const char* format, ...){
  va_list args;
  va_start (args, format);
  int len = vsnprintf(String::handleMemory, MCUF_STRING_HANDLE_MEMORY_SIZE, format, args);
  va_end (args);
  Memory memory = System::allocMemory(len);
  memory.copy(String::handleMemory, len);
  return (char*)memory.pointer();
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
bool String::isConst(void){
  if(this->mSize != 0)
    return false;

  if(this->mPointer == nullptr)
    return false;
  
  return true;
}

/**
 * 
 */
uint32_t String::length(void){
  if(this->mSize == 0){
    if(this->mPointer == nullptr)
      return 0;
    else
      return strlen(this->mPointer);
  }

  return strlen(this->mPointer);
}

/**
 * 
 */
const char* String::toPointer(void){
  if(this->mPointer == nullptr)
    return &String::emptyString;

  return this->mPointer;
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
