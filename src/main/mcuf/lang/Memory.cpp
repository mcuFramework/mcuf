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
#include "mcuf/lang/Math.h"
#include "mcuf/lang/Memory.h"
#include "mcuf/lang/Pointer.h"
#include "mcuf/lang/System.h"

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
  if(length & 0xC0000000)
    length = 0;
  
  this->mLength = (length | 0x80000000);
  return;
}

/**
 * 
 */
Memory::Memory(void* pointer, uint32_t length) construct Pointer(const_cast<void*>(pointer)){
  if(length & 0xC0000000)
    length = 0;
  
  this->mLength = length;
  return;
}

/**
 * @brief Destroy the Memory:: Memory object
 * 
 * @param size 
 */
Memory::Memory(uint32_t size) construct Pointer(new uint8_t[(size & 0x3FFFFFFF)]){
  size &= 0x3FFFFFFF;
  size |= 0x40000000;
  this->mLength = size;
}

/**
 * @brief Destroy the Memory:: Memory object
 * 
 */
Memory::~Memory(void){
  if(this->mLength & 0x40000000)
    delete[] static_cast<uint8_t*>(this->pointer());
    
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
 * @return Memory 
 */
Memory Memory::nullMemory(void){
  return Memory((const void*)nullptr, 0);
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::lang::Pointer
 */

/**
 * @brief 
 * 
 * @param source 
 * @param length 
 * @return int 
 */
int Memory::copy(const void* source, uint32_t length){
  if(this->isReadOnly())
    return 0;
  
  if(length > this->mLength)
    return Pointer::copy(source, this->mLength);

  return Pointer::copy(source, length);
}

/**
 * @brief 
 * 
 * @param source 
 * @param shift 
 * @param length 
 * @return int 
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
 * @brief 
 * 
 * @param source 
 * @param shift 
 * @param start 
 * @param length 
 * @return int 
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
 * @brief 
 * 
 * @return Memory& 
 */
Memory& Memory::clear(void){
  if(this->isReadOnly())
    return *this;
  
  memset(this->pointer(), 0x00, this->length());
  return *this;
}

/**
 * @brief 
 * 
 * @param value 
 * @return Memory& 
 */
Memory& Memory::clear(uint8_t value){
  if(this->isReadOnly())
    return *this;
  
  memset(this->pointer(), 0x00, this->length());
  return *this;
}

/**
 * @brief 
 * 
 * @param sourec 
 * @return int 
 */
int Memory::copyMemory(Memory& sourec){
  if(this->isReadOnly())
    return 0;
  
  uint32_t length = Math::min(this->length(), sourec.length());
  return this->copy(sourec.pointer(), length);
}

/**
 * @brief 
 * 
 * @param sourec 
 * @param shift 
 * @return int 
 */
int Memory::copyMemory(Memory& sourec, uint32_t shift){
  if(this->isReadOnly())
    return 0;
  
  return this->copy(sourec.pointer(), shift, sourec.length());
}

/**
 * @brief 
 * 
 * @param sourec 
 * @param shift 
 * @param length 
 * @return int 
 */
int Memory::copyMemory(Memory& sourec, uint32_t shift, uint32_t length){
  if(this->isReadOnly())
    return 0;
  
  return this->copy(sourec.pointer(), shift, length);
}

/**
 * @brief 
 * 
 * @param sourec 
 * @param shift 
 * @param start 
 * @param length 
 * @return int 
 */
int Memory::copyMemory(Memory& sourec, uint32_t shift, uint32_t start, uint32_t length){
  if(this->isReadOnly())
    return 0;
  
  return this->copy(sourec.pointer(), shift, start, length);
}

/**
 * @brief 
 * 
 * @param address 
 * @return true 
 * @return false 
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
 * @brief 
 * 
 * @param beginIndex 
 * @return Memory 
 */
Memory Memory::subMemory(uint32_t beginIndex) const{
  if(beginIndex >= this->length())
    return Memory::nullMemory();
  
  uint32_t length = this->length() - beginIndex;

  return Memory(this->pointer(beginIndex), length);
}

/**
 * @brief 
 * 
 * @param beginIndex 
 * @param length 
 * @return Memory 
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
