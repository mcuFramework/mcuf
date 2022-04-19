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
int Memory::copy(const void* source, int length){
  return Memory::copy(source, 0, 0, length);
}

/**
 * @brief 
 * 
 * @param source 
 * @param start 
 * @param length 
 * @return int32_t 
 */
int Memory::copy(const void* source, int start, int length){
  return Memory::copy(source, 0, start, length);
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
int Memory::copy(const void* source, int shift, int start, int length){
  if(length <= 0)
    return 0;
  
  if(this->isReadOnly())
    return 0;
  
  int max = this->length();
  
  if(shift > max)
    return 0;
  
  if(length > (max - shift))
    length = (max - shift);
  
  return Pointer::copy(source, shift, start, length);
}

/* ****************************************************************************************
 * Public Method
 */

/**
 * @brief 
 * 
 * @return int 
 */
int Memory::wipe(void){
  return this->wipe(0x00, 0, 0);
}

/**
 * @brief 
 * 
 * @param value 
 * @return int 
 */
int Memory::wipe(uint8_t value){
  return this->wipe(value, 0, 0);
}

/**
 * @brief 
 * 
 * @param value 
 * @param start 
 * @return int 
 */
int Memory::wipe(uint8_t value, int length){
  return this->wipe(value, 0, length);
}
  
/**
 * @brief 
 * 
 * @param value 
 * @param start 
 * @param length 
 * @return int 
 */
int Memory::wipe(uint8_t value, int start, int length){
  if(this->isReadOnly())
    return 0;
  
  if(length <= 0)
    return 0;
  
  int max = this->length();
  if((start + length) > max)
    length = max - start;
  
  memset(this->pointer(start), value, static_cast<size_t>(length));
  return length;
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

/**
 * @brief 
 * 
 * @param source 
 * @param shift 
 * @param start 
 * @param length 
 * @return int32_t 
 */
int Memory::insertArray(const void* source, int start, int length){
  return this->insertArray(source, 0, start, length);
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
int Memory::insertArray(const void* source, int shift, int start, int length){
  if(length <= 0)
    return 0;
  
  int max = this->length();
  
  if(start + length > max)
    length = max - start;
  
  int less = max - (start + length);
  
  if(less != 0)
    this->copy(this->pointer(start), 0, (start + length), less);
  
  this->copy(source, 0, start, length);
  
  return 0;
}

/**
 * @brief 
 * 
 * @param start 
 * @param length 
 * @return int32_t 
 */
int Memory::popArray(int start, int length){
  return this->popArray(nullptr, 0, start, length);
}

/**
 * @brief 
 * 
 * @param source 
 * @param start 
 * @param length 
 * @return int32_t 
 */
int Memory::popArray(void* source, int start, int length){
  return this->popArray(source, 0, start, length);
}

/**
 * @brief 
 * 
 * @param source 
 * @param shift 
 * @param start 
 * @param length 
 * @return true 
 * @return false 
 */
int Memory::popArray(void* source, int shift, int start, int length){
  if(length <= 0)
    return 0;
  
  int max = this->length();
  
  if(start + length > max)
    length = max - start;
  
  int less = max - (start + length);
  
  if(source != nullptr)
    this->copyTo(source, shift, start, length);
  
  if(less != 0)
    this->copy(this->pointer(start), 0, (start + length), less);
  
  this->wipe(0x00, (start + less), length);
  
  return length;
}

/**
 * @brief 
 * 
 * @param ch 
 * @return int 
 */
int Memory::indexOf(char ch) const{
  return this->indexOf(ch, 0);
}

/**
 * @brief 
 * 
 * @param ch 
 * @param offset 
 * @return int 
 */
int Memory::indexOf(char ch, int start) const{
  return Pointer::indexOf(ch, start, this->length());
}

/**
 * @brief 
 * 
 * @param destination 
 * @param destinationLen 
 * @param start 
 * @return int 
 */
int Memory::indexOfMemory(const void* destination, int destinationLen, int start) const{
  return Pointer::indexOfMemory(destination, destinationLen, start, this->length());
}

/**
 * @brief 
 * 
 * @param str 
 * @return int 
 */
int Memory::indexOfString(const char* str) const{
  return Pointer::indexOfString(str, this->length());
}

/**
 * @brief 
 * 
 * @param size 
 * @return true 
 * @return false 
 */
bool Memory::resize(int size){
  if(size <= 0)
    return false;

  if(!this->isHeapMemory())
    return false;
  
  char* newMemory = new char[size];
  if(newMemory == nullptr)
    return false;
  
  Pointer::move(newMemory, this->pointer(), Math::min(size, this->length()));
  char* oldPointer = static_cast<char*>(this->pointer());
  Memory* next = this;
  
  while(true){
    next->mPointer = newMemory;
    next->mLength = static_cast<uint32_t>(size);
    if(next->mNext == this)
      break;
    
    next = next->mNext;
  }
  
  delete[] oldPointer;
  return true;
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
