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
  this->mFlag = 0x00000000;
  return;
}

/**
 *
 */
Memory::Memory(const char* pointer) construct Memory(pointer, strlen(pointer)){
  return;
}

/**
 *
 */
Memory::Memory(const void* pointer, uint32_t length) construct Memory(){
  this->mPointer = const_cast<void*>(pointer);
  this->mLength = length;
  this->mFlag |= this->MEMORY_FLAG_CONST;
}

/**
 * 
 */
Memory::Memory(void* pointer, uint32_t length) construct Memory(){
  this->mPointer = pointer;
  this->mLength = length;
  return;
}

/**
 * 
 */
Memory::Memory(Memory* memory){
  *this = memory;
  return;
}

/**
 *
 */
Memory::Memory(size_t size) construct Memory(System::allocMemory(size)){
  this->mFlag |= this->MEMORY_FLAG_HEAP_MEMORY;
  return;
}

/**
 *
 */
Memory::~Memory(void){
  if(this->mFlag & this->MEMORY_FLAG_HEAP_MEMORY)
    System::freeMemory(*this);
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
 * Public Method <Override>
 */

/**
 * 
 */
Pointer& Memory::copy(const void* source, uint32_t length){
  if(this->mFlag & this->MEMORY_FLAG_CONST)
    return *this;
  
  if(length > this->mLength)
    return Pointer::copy(source, this->mLength);

  return Pointer::copy(source, length);
}

/**
 * 
 */
Pointer& Memory::copy(const void* source, uint32_t shift, uint32_t length){
  if(this->mFlag & this->MEMORY_FLAG_CONST)
    return *this;  
  
  if((shift + length) > this->mLength){
    if(shift > this->mLength)
      return *this;
    
    length = this->mLength - shift;
  }

  return Pointer::copy(source, shift, length);
}

/**
 * 
 */
Pointer& Memory::copy(const void* source, uint32_t shift, uint32_t start, uint32_t length){
  if(this->mFlag & this->MEMORY_FLAG_CONST)
    return *this;  
  
  if(shift > this->mLength)
    return *this;
  
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
  if(!(this->mFlag & this->MEMORY_FLAG_CONST))
    memset(this->mPointer, 0x00, this->mLength);
  
  return *this;
}

/**
 * 
 */
Memory& Memory::copyMemory(Memory& sourec){
  if(!(this->mFlag & this->MEMORY_FLAG_CONST))
    this->copy(sourec.mPointer, sourec.mLength);
  
  return *this;
}

/**
 * 
 */
Memory& Memory::copyMemory(Memory& sourec, uint32_t shift){
  if(!(this->mFlag & this->MEMORY_FLAG_CONST))
    this->copy(sourec.mPointer, shift, sourec.mLength);
  
  return *this;
}

/**
 * 
 */
Memory& Memory::copyMemory(Memory& sourec, uint32_t shift, uint32_t length){
  if(!(this->mFlag & this->MEMORY_FLAG_CONST))
    this->copy(sourec.mPointer, shift, length);
  
  return *this;
}

/**
 * 
 */
Memory& Memory::copyMemory(Memory& sourec, uint32_t shift, uint32_t start, uint32_t length){
  if(!(this->mFlag & this->MEMORY_FLAG_CONST))
    this->copy(sourec.mPointer, shift, start, length);
  
  return *this;
}

/**
 * 
 */
mcuf::lang::Pointer& Memory::getPointer(void){
  return *this;
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
  return this->mLength;
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
  
  Memory result = System::allocMemory(remainingLength);
  

  return result;
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
