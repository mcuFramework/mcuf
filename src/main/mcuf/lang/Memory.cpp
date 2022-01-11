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
Memory::Memory(const Memory& memory){
  *this = memory;  
  return;
}

/**
 * 
 */
Memory::Memory(const void* pointer, uint32_t length) construct Pointer(const_cast<void*>(pointer)){
  if(length & 0x80000000)
    length = 0;
  
  this->mLength = (length | 0x80000000);
  return;
}

/**
 * 
 */
Memory::Memory(void* pointer, uint32_t length) construct Pointer(const_cast<void*>(pointer)){
  if(length & 0x80000000)
    length = 0;
  
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
  if(this->isReadOnly())
    return *this;
  
  memset(this->pointer(), 0x00, this->length());
  return *this;
}

/**
 * 
 */
Memory& Memory::clear(uint8_t value){
  if(this->isReadOnly())
    return *this;
  
  memset(this->pointer(), 0x00, this->length());
  return *this;
}

/**
 * 
 */
int Memory::copyMemory(Memory& sourec){
  if(this->isReadOnly())
    return 0;
  
  uint32_t length = Math::min(this->length(), sourec.length());
  return this->copy(sourec.pointer(), length);
}

/**
 * 
 */
int Memory::copyMemory(Memory& sourec, uint32_t shift){
  if(this->isReadOnly())
    return 0;
  
  return this->copy(sourec.pointer(), shift, sourec.length());
}

/**
 * 
 */
int Memory::copyMemory(Memory& sourec, uint32_t shift, uint32_t length){
  if(this->isReadOnly())
    return 0;
  
  return this->copy(sourec.pointer(), shift, length);
}

/**
 * 
 */
int Memory::copyMemory(Memory& sourec, uint32_t shift, uint32_t start, uint32_t length){
  if(this->isReadOnly())
    return 0;
  
  return this->copy(sourec.pointer(), shift, start, length);
}

/**
 *
 */
bool Memory::inRange(void* address) const{
  uint32_t start = reinterpret_cast<uint32_t>(this->pointer());
  uint32_t end = start + this->length();
  uint32_t adr = reinterpret_cast<uint32_t>(address);
  
  if((adr < start) && (adr >= end))
    return false;
  
  return true; 
}

/**
 * 
 */
Memory Memory::subMemory(uint32_t beginIndex) const{
  if(beginIndex >= this->length())
    return Memory::nullMemory();
  
  uint32_t length = this->length() - beginIndex;

  return Memory(this->pointer(beginIndex), length);
}

/**
 * 
 */
Memory Memory::subMemory(uint32_t beginIndex, uint32_t length) const{
  if(beginIndex >= this->length())
    return Memory::nullMemory();

  uint32_t remainingLength = (this->length() - beginIndex);
  if(length >= remainingLength)
    length = remainingLength;
  

  return Memory(this->pointer(beginIndex), length);
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
