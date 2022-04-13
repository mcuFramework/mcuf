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
 * @brief Construct a new Memory:: Memory object
 * 
 * @param memory 
 */
Memory::Memory(const Memory& memory){
  *this = memory;

  if(this->mNext != nullptr)
    const_cast<Memory&>(memory).mNext = this;
  
  return;
}

/**
 * @brief Construct a new Memory:: Memory object
 * 
 * @param pointer 
 * @param length 
 */
Memory::Memory(const void* pointer, size_t length) : Pointer(const_cast<void*>(pointer)){
  if(length & 0x80000000)
    length = 0;
  
  this->mNext = nullptr;
  this->mLength = (length | 0x80000000);
  return;
}

/**
 * @brief Construct a new Memory:: Memory object
 * 
 * @param pointer 
 * @param length 
 */
Memory::Memory(void* pointer, size_t length) : Pointer(const_cast<void*>(pointer)){
  if(length & 0x80000000)
    length = 0;
  
  this->mNext = nullptr;
  this->mLength = length;
  return;
}

/**
 * @brief Destroy the Memory:: Memory object
 * 
 * @param length 
 */
Memory::Memory(size_t length) : Pointer(new uint8_t[(length & 0x7FFFFFFF)]){
  length &= 0x7FFFFFFF;

  this->mNext = this;
  this->mLength = length;
}

/**
 * @brief Destroy the Memory:: Memory object
 * 
 */
Memory::~Memory(void){
  if(this->mNext == nullptr)
    return;

  if(this->mNext == this){
    delete[] static_cast<uint8_t*>(this->pointer());
  }else{
    Memory* next = this;
    
    while(true){
      if(next->mNext == nullptr)
        System::error(this, mcuf::lang::ErrorCode::NULL_POINTER);
      
      if(next->mNext == this){
        next->mNext = this->mNext;
        break;
      }
      
      next = next->mNext;
    }
  }
  
  this->mNext = nullptr;
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
  return Memory(static_cast<const void*>(nullptr), 0);
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::lang::Pointer
 */

/**
 * @brief 
 * 
 * @param source 
 * @param length 
 * @return int32_t 
 */
int Memory::copy(const void* source, uint32_t length){
  if(this->isReadOnly())
    return 0;
  
  uint32_t max = this->length();
  
  if(length > max)
    return Pointer::copy(source, max);

  return Pointer::copy(source, length);
}

/**
 * @brief 
 * 
 * @param source 
 * @param shift 
 * @param length 
 * @return int32_t 
 */
int Memory::copy(const void* source, int32_t shift, uint32_t length){
  if(this->isReadOnly())
    return 0; 
  
  uint32_t max = this->length();
  
  if((shift + static_cast<int>(length)) > static_cast<int>(max)){
    if(shift > static_cast<int>(max))
      return 0;
    
    length = static_cast<uint32_t>(static_cast<int>(max) - shift);
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
 * @return int32_t 
 */
int Memory::copy(const void* source, int32_t shift, int32_t start, uint32_t length){
  if(this->isReadOnly())
    return 0;
  
  int32_t max = static_cast<int32_t>(this->length());
  
  if(shift > max)
    return 0;
  
  if(length > static_cast<uint32_t>((max - shift)))
    length = static_cast<uint32_t>((max - shift));
  
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
bool Memory::wipe(void){
  if(this->isReadOnly())
    return false;
  
  memset(this->pointer(), 0x00, static_cast<size_t>(this->length()));
  return true;
}

/**
 * @brief 
 * 
 * @param value 
 * @return Memory& 
 */
bool Memory::wipe(uint8_t value){
  if(this->isReadOnly())
    return false;
  
  memset(this->pointer(), value, static_cast<size_t>(this->length()));
  return true;
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
  uint32_t end = start + static_cast<uint32_t>(this->length());
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
  uint32_t max = static_cast<size_t>(this->length());
  
  if(beginIndex >= max)
    return Memory::nullMemory();
  
  uint32_t length = max - beginIndex;

  return Memory(this->pointer(static_cast<int>(beginIndex)), length);
}

/**
 * @brief 
 * 
 * @param beginIndex 
 * @param length 
 * @return Memory 
 */
Memory Memory::subMemory(uint32_t beginIndex, uint32_t length) const{
  uint32_t max = static_cast<size_t>(this->length());
  
  if(beginIndex >= max)
    return Memory::nullMemory();

  uint32_t remainingLength = (max - beginIndex);
  if(length >= remainingLength)
    length = remainingLength;
  

  return Memory(this->pointer(static_cast<int>(beginIndex)), length);
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
