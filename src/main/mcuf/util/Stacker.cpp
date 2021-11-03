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
#include "mcuf.h"
 
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
Stacker::Stacker(Memory& memory) construct Memory(memory){
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
  this->stackPointer = 0;
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
void Stacker::forEach(mcuf::function::Consumer<mcuf::lang::Memory&>& action){
  return;
}

/**
 * Returns true if this collection contains no elements.
 * 
 * @return true if this collection contains no elements.
 */
bool Stacker::isEmpty(void){
  return !(this->stackPointer == 0);
}


uint32_t Stacker::size(void){
  return this->stackPointer;
}

/* ****************************************************************************************
 * Public Method
 */

/**
 * 
 */
uint32_t Stacker::getFree(void){
  return (this->mLength - this->stackPointer);
}

/**
 * 
 */
void* Stacker::alloc(uint32_t size){
  if(size & 0x00000003)
    size = (size & 0xFFFFFFFC) + 4;  
  
  if(this->getFree() < size)
    return nullptr;

  void* result = &static_cast<uint8_t*>(this->mPointer)[this->stackPointer];
  this->stackPointer += size;

  return result;
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
