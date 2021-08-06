/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "Memory.hpp"

#include <string.h>

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::Memory;
using mcuf::lang::Pointer;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
Memory::Memory(void* pointer, uint32_t length){    
  this->mPointer = pointer;
  this->mLength = length;
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
  return mcuf::lang::Memory(nullptr, 0);
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
Memory& Memory::clear(void){
  memset(this->mPointer, 0x00, this->mLength);
  return *this;
}

/**
 * 
 */
Pointer Memory::getPointer(){
  return Pointer(this->mPointer);
}

/**
 * 
 */
Pointer Memory::getPointer(uint32_t offse){
  return Pointer(this->pointer(offse));
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
void* Memory::pointer(void){
  return this->mPointer;
}

/**
 * 
 */
void* Memory::pointer(uint32_t offset){
  return &((uint8_t*)this->mPointer)[offset];
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
