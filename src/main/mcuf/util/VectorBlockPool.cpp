/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "mcuf.h"
 
/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::Memory;
using mcuf::lang::Vector;
using mcuf::util::VectorBlockPool;
using mcuf::function::Consumer;
 
/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/**
 * 
 */
VectorBlockPool::VectorBlockPool(void* flag, void* pointer, uint32_t elementSize, uint32_t capacity) :
                 BlockPool(flag, pointer, elementSize, capacity){
  
  return;
}
/**
 * 
 */

VectorBlockPool::VectorBlockPool(Memory flags, Memory memory, uint32_t elementSize) : 
                 BlockPool(flags, memory, elementSize){
  
  return;
}

/**
 * 
 */
VectorBlockPool::VectorBlockPool(Memory memory, uint32_t elementSize) :
                 BlockPool(memory, elementSize){
  
  return;
}

/* ****************************************************************************************
 * Public Method <Static>
 */
 
/* ****************************************************************************************
 * Public Method <Override>
 */

/**
 * 
 */
void* VectorBlockPool::add(void* element){
  void* result = BlockPool::add(element);
  if((result == nullptr) & (this->nextVector != nullptr))
    return this->nextVector->getBase()->add(element);
  
  return result;
}

/**
 * 
 */
void* VectorBlockPool::alloc(void){
  void* result = BlockPool::alloc();
  if((result == nullptr) & (this->nextVector != nullptr))
    return this->nextVector->getBase()->alloc();

  return result;
}

/**
 * 
 */
Memory VectorBlockPool::allocMemory(void){
  Memory result = BlockPool::allocMemory();
  if(result.isEmpty() & (this->nextVector != nullptr))
    return this->nextVector->getBase()->allocMemory();

  return result;
}

/**
 * 
 */
uint32_t VectorBlockPool::capacity(void){
  uint32_t result = BlockPool::mCapacity;
  if((this->nextVector != nullptr))
    result += this->nextVector->getBase()->capacity();

  return result;
}

/**
 * 
 */
void VectorBlockPool::clear(void){
  BlockPool::clear();
  if((this->nextVector != nullptr))
    this->nextVector->getBase()->clear();
  
  return;
}

/**
 * 
 */
void VectorBlockPool::forEach(Consumer<Memory&>& consumer){
  BlockPool::forEach(consumer);
  if((this->nextVector) != nullptr)
    this->nextVector->getBase()->forEach(consumer);
  
  return;
}

/**
 * 
 */
VectorBlockPool* VectorBlockPool::getBase(void){
  return this;
}

/**
 * 
 */
bool VectorBlockPool::isEmpty(void){
  bool result = BlockPool::isEmpty();
  if(this->nextVector != nullptr)
    result &= this->nextVector->getBase()->isEmpty();
  
  return result;
}

/**
 * 
 */
bool VectorBlockPool::isFull(void){
  bool result = BlockPool::isFull();
  if(this->nextVector != nullptr)
    result &= this->nextVector->getBase()->isFull();
  
  return result;
}

/**
 * 
 */
uint32_t VectorBlockPool::size(void){
  uint32_t result = BlockPool::mSize;
  if(this->nextVector != nullptr)
    result += this->nextVector->getBase()->size();
  
  return result;
}

/**
 * 
 */
bool VectorBlockPool::remove(void* element){
  bool result = BlockPool::remove(element);
  if((result == false) & (this->nextVector != nullptr))
    result |= this->nextVector->getBase()->remove(element);

  return result;
}

/* ****************************************************************************************
 * Public Method
 */

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
