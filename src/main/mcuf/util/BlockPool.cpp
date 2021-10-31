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
using mcuf::lang::Math;
using mcuf::util::BlockPool;
using mcuf::lang::Memory;
using mcuf::function::Consumer;

/* ****************************************************************************************
 * Construct Method
 */

/**
 *
 */
BlockPool::BlockPool(uint32_t pageSize, uint32_t elementSize) construct Memory(pageSize), mMemoryFlag(){
  this->init(elementSize);
  return;
}

/**
 * 
 */
BlockPool::BlockPool(Memory& page, uint32_t elementSize, Memory& flag) construct Memory(page), mMemoryFlag(flag){    
  this->init(elementSize);
  return;
}

/**
 * 
 */
BlockPool::BlockPool(Memory& memory, uint32_t elementSize) construct Memory(memory), mMemoryFlag(){
  this->init(elementSize);
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
  this->mMemoryFlag.clear();
  this->mSize = 0;
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
void BlockPool::init(uint32_t elementSize){
  this->mElementSize = elementSize;
  this->mCapacity = this->mLength / this->mElementSize;
  
  
  if(this->mMemoryFlag.isEmpty()){    
    uint32_t requirmentFlagSize = Math::ceil(this->mCapacity, 8U);
    uint32_t remainingSize = this->mLength - (this->mElementSize * this->mCapacity);
    
    if((requirmentFlagSize*3) < this->mElementSize){
      this->mMemoryFlag.~Memory();
      this->mMemoryFlag = Memory(requirmentFlagSize);
    }
    
    if(this->mMemoryFlag.isEmpty()){
      uint32_t requirmentBlockQuantity = Math::ceil((requirmentFlagSize - remainingSize), this->mElementSize);
      this->mCapacity -= requirmentBlockQuantity;
      this->mMemoryFlag = this->subMemory((this->mElementSize * this->mCapacity));   
    }
  }
   
  this->mFlags = static_cast<uint8_t*>(this->mMemoryFlag.pointer());
  this->mMemoryFlag.clear();
  this->mLastFlag = 0xFFFFFFFF;
  this->mSize = 0;
  return;
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
  return &static_cast<uint8_t*>(this->mPointer)[bytes];
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
 