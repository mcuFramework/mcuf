/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf/util/Stacker.hpp"
 
/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::Memory;
using mcuf::util::Stacker;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
Stacker::Stacker(void* buffer, uint32_t size) construct Memory(buffer, size){
  this->clear();
  return;
}

/**
 * 
 */
Stacker::Stacker(const Memory& memory) construct Memory(memory){
  this->clear();
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */
 
/* ****************************************************************************************
 * Public Method <Override>
 */

/**
 * Removes all of the elements from this collection. The collection will be empty after 
 * this method returns.
 */
void Stacker::clear(void){
  this->mStackPointer = static_cast<uint8_t*>(this->Memory::pointer());
  this->Memory::clear();
}

/**
 * Performs the given action for each element of the Iterable until all elements have 
 * been processed or the action throws an exception. Unless otherwise specified by the 
 * implementing class, actions are performed in the order of iteration (if an iteration 
 * order is specified). 
 *
 * @param Consumer<Memory&>-action The action to be performed for each element.
 */
void Stacker::forEach(mcuf::function::Consumer<mcuf::lang::Memory*>& action){
  return;
}

/**
 * Returns true if this collection contains no elements.
 * 
 * @return true if this collection contains no elements.
 */
bool Stacker::isEmpty(void){
  return (this->mStackPointer == this->Memory::pointer());
}

/**
 *
 */
uint32_t Stacker::size(void){
  return (reinterpret_cast<uint32_t>(this->mStackPointer) - 
    reinterpret_cast<uint32_t>(this->Memory::pointer()));
}

/* ****************************************************************************************
 * Public Method
 */

/**
 * 
 */
uint32_t Stacker::getFree(void){
  return (this->length() - this->size());
}

/**
 * 
 */
void* Stacker::alloc(uint32_t size){
  if(this->getFree() < size)
    return nullptr;

  void* result = this->mStackPointer;
  this->mStackPointer += size;

  return result;
}

/**
 *
 */
void* Stacker::allocAlignment32(uint32_t size){
  uint32_t alignment = (reinterpret_cast<uint32_t>(this->mStackPointer) & 0x00000003);
  
  if(alignment){
    if(this->alloc(0x00000004 - alignment) == nullptr)
      return nullptr;
  }
  
  return this->alloc(size);
}
  
/**
 *
 */
void* Stacker::allocAlignment64(uint32_t size){
  uint32_t alignment = (reinterpret_cast<uint32_t>(this->mStackPointer) & 0x00000007);
  
  if(alignment){
    if(this->alloc(0x00000008 - alignment) == nullptr)
      return nullptr;
  }
  
  return this->alloc(size);
}

/**
 * 
 */
Memory Stacker::allocMemory(uint32_t size){
  void* result = this->alloc(size);
  if(result == nullptr)
    return Memory::nullMemory();
  
  return Memory(result, size);
}

/**
 * 
 */
Memory Stacker::allocMemoryAlignment32(uint32_t size){
  void* result = this->allocAlignment32(size);
  if(result == nullptr)
    return Memory::nullMemory();
  
  return Memory(result, size);
}

/**
 * 
 */
Memory Stacker::allocMemoryAlignment64(uint32_t size){
  void* result = this->allocAlignment64(size);
  if(result == nullptr)
    return Memory::nullMemory();
  
  return Memory(result, size);
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
