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
#include "mcuf/lang/Math.hpp"
#include "mcuf/lang/Memory.hpp"
#include "mcuf/lang/Pointer.hpp"
#include "mcuf/lang/System.hpp"

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::Math;
using mcuf::lang::Memory;
using mcuf::lang::Pointer;

/* ****************************************************************************************
 * Construct Method
 */

/**
 *
 */
Memory::Memory(void){
  this->mPointer = nullptr;
  this->mLength = 0;
  return;
}

/**
 *
 */
Memory::Memory(const Memory& memory){
  *this = memory;  
  return;
}

/**
 * 
 */
Memory::Memory(const void* pointer, uint32_t length) construct Memory(){
  if(length & 0x80000000)
    return;
  
  this->mPointer = const_cast<void*>(pointer);
  this->mLength = length | 0x80000000;
  return;
}

/**
 * 
 */
Memory::Memory(void* pointer, uint32_t length) construct Memory(){
  if(length & 0x80000000)
    return;
  
  this->mPointer = pointer;
  this->mLength = length;
  return;
}

/**
 *
 */
Memory::~Memory(void){
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
Memory Memory::nullMemory(void){
  return Memory((const void*)nullptr, 0);
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::lang::Pointer
 */

/**
 * 
 */
int Memory::copy(const void* source, uint32_t length){
  if(this->isReadOnly())
    return 0;
  
  if(length > this->mLength)
    return Pointer::copy(source, this->mLength);

  return Pointer::copy(source, length);
}

/**
 * 
 */
int Memory::copy(const void* source, uint32_t shift, uint32_t length){
  if(this->isReadOnly())
    return 0; 
  
  if((shift + length) > this->mLength){
    if(shift > this->mLength)
      return 0;
    
    length = this->mLength - shift;
  }

  return Pointer::copy(source, shift, length);
}

/**
 * 
 */
int Memory::copy(const void* source, uint32_t shift, uint32_t start, uint32_t length){
  if(this->isReadOnly())
    return 0;
  
  if(shift > this->mLength)
    return 0;
  
  if(length > (this->mLength - shift))
    length = (this->mLength - shift);
  
  return Pointer::copy(source, shift, start, length);
}

/* ****************************************************************************************
 * Public Method
 */

/**
 * 
 */
Memory& Memory::clear(void){
  if(!this->isReadOnly())
    memset(this->mPointer, 0x00, this->mLength);
  
  return *this;
}

/**
 * 
 */
int Memory::copyMemory(Memory& sourec){
  if(this->isReadOnly())
    return 0;
  
  uint32_t length = Math::min(this->length(), sourec.length());
  return this->copy(sourec.mPointer, length);
}

/**
 * 
 */
int Memory::copyMemory(Memory& sourec, uint32_t shift){
  if(this->isReadOnly())
    return 0;
  
  return this->copy(sourec.mPointer, shift, sourec.mLength);
}

/**
 * 
 */
int Memory::copyMemory(Memory& sourec, uint32_t shift, uint32_t length){
  if(this->isReadOnly())
    return 0;
  
  return this->copy(sourec.mPointer, shift, length);
}

/**
 * 
 */
int Memory::copyMemory(Memory& sourec, uint32_t shift, uint32_t start, uint32_t length){
  if(this->isReadOnly())
    return 0;
  
  return this->copy(sourec.mPointer, shift, start, length);
}

/**
 *
 */
bool Memory::inRange(void* address){
  uint32_t start = reinterpret_cast<uint32_t>(this->mPointer);
  uint32_t end = start + this->mLength;
  uint32_t adr = reinterpret_cast<uint32_t>(address);
  
  if((adr < start) && (adr >= end))
    return false;
  
  return true; 
}

/**
 *
 */
bool Memory::isReadOnly(void){
  return (this->mLength & 0x80000000);
}

/**
 * 
 */
bool Memory::isEmpty(void){
  return (this->mPointer == nullptr) | (this->mLength == 0);
}

/**
 * 
 */
uint32_t Memory::length(void){
  return (this->mLength & 0x7FFFFFFF);
}

/**
 * 
 */
Memory Memory::subMemory(uint32_t beginIndex){
  if(beginIndex >= this->mLength)
    return Memory::nullMemory();

  return Memory(this->pointer(beginIndex), this->mLength-beginIndex);
}

/**
 * 
 */
Memory Memory::subMemory(uint32_t beginIndex, uint32_t length){
  if(beginIndex >= this->mLength)
    return Memory::nullMemory();

  uint32_t remainingLength = (this->mLength - beginIndex);
  if(length >= remainingLength)
    length = remainingLength;
  

  return Memory(this->pointer(beginIndex), this->mLength-beginIndex);
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
