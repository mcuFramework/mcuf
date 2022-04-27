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
Memory::Memory(const void* pointer, size_t length) : 
Data(const_cast<void*>(pointer), length){
 
  this->mNext = nullptr;
  return;
}

/**
 * @brief Construct a new Memory:: Memory object
 * 
 * @param pointer 
 * @param length 
 */
Memory::Memory(void* pointer, size_t length) : 
Data(const_cast<void*>(pointer), length){

  this->mNext = nullptr;
  return;
}

/**
 * @brief Destroy the Memory:: Memory object
 * 
 * @param length 
 */
Memory::Memory(size_t length) : 
Data(new uint8_t[(length & 0x7FFFFFFF)], (length & 0x7FFFFFFF)){

  this->mNext = this;
  return;
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
 * Public Method
 */

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
