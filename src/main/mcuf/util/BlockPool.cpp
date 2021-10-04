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
using mcuf::util::BlockPool;
using mcuf::lang::Memory;
using mcuf::function::Consumer;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
BlockPool::BlockPool(void* flag, void* pointer, uint32_t elementSize, uint32_t capacity){
  this->init(flag, pointer, elementSize, capacity);
  return;
}

/**
 * 
 */
BlockPool::BlockPool(Memory& flags, Memory& memory, uint32_t elementSize){    
  uint32_t capacity = (memory.length() / elementSize);
  if(capacity >= (flags.length() << 3))
    this->mCapacity = (flags.length() << 3);
    
  this->init(flags.pointer(), memory.pointer(), elementSize, capacity);
  return;
}

/**
 * 
 */
BlockPool::BlockPool(Memory& memory, uint32_t elementSize){
  uint32_t capacity = (memory.length() / elementSize);
  uint32_t flags = (capacity >> 5);

  if(capacity & 0x0000001F) 
    ++flags;

  capacity = ((memory.length() - flags*4) / elementSize);
    
  this->init(memory.pointer(), &((uint8_t*)memory.pointer())[flags*4], elementSize, capacity);
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
 * 
 */
void* BlockPool::add(void* element){
  void* block = this->alloc();
  if(block == nullptr)
    return nullptr;
  
  memcpy(block, element, this->mElementSize);
  return block;
}

/**
 * 
 */
void* BlockPool::alloc(void){
  if(this->isFull())
    return nullptr;
  
  return this->getBlock(this->foundAndSetFlag());
}

/**
 * 
 */
Memory BlockPool::allocMemory(void){
  if(this->isFull())
    return Memory::nullMemory();
  
  return Memory(this->getBlock(this->foundAndSetFlag()), this->mElementSize);
}

/**
 * 
 */
uint32_t BlockPool::capacity(void){
  return this->mCapacity;
}

/**
 * 
 */
void BlockPool::clear(void){
  this->flagFormat();
}

/**
 * 
 */
uint32_t BlockPool::elementSize(void){
  return this->mElementSize;
}

/**
 * 
 */
void BlockPool::forEach(Consumer<Memory&>& consumer){
  for(int i = 0; i<this->mCapacity; i++){
    if(getFlag(i)){
      Memory memory = Memory(this->getBlock(i), this->elementSize());
      consumer.accept(memory);
    }
  }
}

/**
 * 
 */
bool BlockPool::isEmpty(void){
  return (this->mSize == 0);
}

/**
 * 
 */
bool BlockPool::remove(void* element){
  uint32_t shift = this->getBlockShift(element);
  if(shift >= this->mCapacity)
    return false;
  this->mLastFlag = shift;
  
  if(this->getFlag(shift)){
    this->setFlag(shift, false);
    --this->mSize;
    return true;
  }else{
    return false;
  }
}

/**
 * 
 */
uint32_t BlockPool::size(void){
  return this->mSize;
}

/* ****************************************************************************************
 * Public Method
 */

/**
 * 
 */
bool BlockPool::isFull(void){
  return (this->mSize == this->mCapacity);
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

/**
 * 
 */
void BlockPool::init(void* flag, void* pointer, uint32_t elementSize, uint32_t capacity){
  this->mLastFlag = 0xFFFFFFFF;
  this->mElementSize = elementSize;
  this->mFlags = (uint8_t*)flag;
  this->mPointer = (uint8_t*)pointer;
  this->mCapacity = capacity;
  this->mSize = 0;
  this->flagFormat();
}

/**
 *
 */
void BlockPool::flagFormat(void){
  uint32_t size = (this->mCapacity >> 3);
  if(this->mCapacity & 0x00000007)
    ++size;
  memset(this->mFlags, 0x00, size);
}

/**
 * 
 */
uint32_t BlockPool::getFixedSize(uint32_t capacity, uint32_t elementSize){
  uint32_t bytes;
  uint32_t result;
  
  bytes = (capacity/8);
  
  if(capacity%8)
    ++bytes;
  
  result = bytes/elementSize;
  if(bytes%elementSize)
    ++result;
  
  return result;
}

/**
 *
 */
void BlockPool::setFlag(uint32_t shift, bool enable){
  uint32_t bytes = shift >> 3;
  uint32_t bits = shift & 0x0000001F;
  
  if(enable)
    this->mFlags[bytes] |= (1<<bits);
  
  else
    this->mFlags[bytes] &= ~(1<<bits);
  
  return;
}

/**
 *
 */
void* BlockPool::getBlock(uint32_t shift){
  if(shift >= this->mCapacity)
    return nullptr;
  
  uint32_t bytes = shift * this->mElementSize;
  return &this->mPointer[bytes];
}

/**
 * 
 */
 uint32_t BlockPool::foundAndSetFlag(void){
  
  if(this->mLastFlag < this->mCapacity){
    uint32_t result = this->mLastFlag;
    this->mLastFlag = 0xFFFFFFFF;
    this->setFlag(result, true);
     ++this->mSize;
    return result;
  }
    
  for(int i=0, bytes=0; i<this->mCapacity; i+=8, ++bytes){
    if(this->mFlags[bytes] == 0xFF)
      continue;
      
    for(int j=0; j<8; j++){
      uint8_t mask = (1<<j);
      if(this->mFlags[bytes] & mask)
        continue;
      
      this->mFlags[bytes] |= mask;
       ++this->mSize;
      return i+j;
    } 
  }
  return 0xFFFFFFFF;
}

/**
 *
 */
bool BlockPool::getFlag(uint32_t shift){
  uint32_t bytes = (shift >> 3);
  uint8_t mask = (1 << (shift & 0x00000007));
  
  if(this->mFlags[bytes] & mask)
    return true;
  else
    return false;
}

/**
 *
 */
void* BlockPool::blockClear(uint32_t shift){
  void* block = this->getBlock(shift);
  memset(block, 0x00, this->mElementSize);
  return block;
}

/**
 *
 */
void* BlockPool::blockCopy(uint32_t shift, void* element){
  void* block = this->getBlock(shift);
  memcpy(block, element, this->mElementSize);
  return block;
}

/**
 *
 */
uint32_t BlockPool::getBlockShift(void* block){
  if((uint32_t)this->mPointer > (uint32_t)block)
    return 0xFFFFFFFF;
  uint32_t addressDelta = ((uint32_t)block - (uint32_t)this->mPointer);
  if((addressDelta % this->mElementSize) != 0)
    return 0xFFFFFFFF;
  uint32_t shift = (addressDelta / this->mElementSize);
  if(shift >= this->mCapacity)
    return 0xFFFFFFFF;
  
  else
    return shift;
}

/* ****************************************************************************************
 * End of file
 */ 
 