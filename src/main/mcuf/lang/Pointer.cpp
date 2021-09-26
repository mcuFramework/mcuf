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

//-----------------------------------------------------------------------------------------
#include "mcuf.h"

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::Pointer;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
Pointer::Pointer(void){
  this->mPointer = nullptr;
  return;
}

/**
 * 
 */
Pointer::Pointer(void* pointer){
  this->mPointer = (uint8_t*)pointer;
  return;
}

/**
 * 
 */
Pointer::Pointer(uint32_t pointer){
  this->mPointer = (uint8_t*)pointer;
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/**
 * Operator equal
 */
void* Pointer::operator=(void* pointer){
  this->mPointer = (uint8_t*)pointer;

  return this->mPointer;
}

/* ****************************************************************************************
 * Public Method <Static>
 */

/**
 * 
 */
Pointer Pointer::nullPointer(void){
  return Pointer();
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
Pointer& Pointer::copy(const void* source, uint32_t length){
  memcpy(this->mPointer, source, length);
  return *this;
}

/**
 * 
 */
Pointer& Pointer::copy(const void* source, uint32_t shift, uint32_t length){
  memcpy(this->pointer(shift), source, length);
  return *this;
}

/**
 * 
 */
Pointer& Pointer::copy(const void* source, uint32_t shift, uint32_t start, uint32_t length){
  memcpy(this->pointer(shift), &((uint8_t*)source)[start], length);
  return *this;
}

/**
 * 
 */
char Pointer::getByte(uint32_t shift){
  return *(char*)this->pointer(shift);
}

/**
 * 
 */
int Pointer::getInteger(uint32_t shift){
  return *(int*)this->pointer(shift);
}

/**
 * 
 */
short Pointer::getShort(uint32_t shift){
  return *(short*)this->pointer(shift);
}

/**
 * 
 */
Pointer Pointer::getPointer(uint32_t offset){
  return Pointer(&((uint8_t*)this->mPointer)[offset]);
}

/**
 * 
 */
uint32_t Pointer::getPointerValue(void){
  return reinterpret_cast<uint32_t>(this->mPointer);
}

/**
 * 
 */
bool Pointer::isNull(void){
  return (this->mPointer == nullptr);
}

/**
 * 
 */
void* Pointer::pointer(void){
  return this->mPointer;
}

/**
 * 
 */
void* Pointer::pointer(uint32_t offset){
  return &((uint8_t*)this->mPointer)[offset];
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
