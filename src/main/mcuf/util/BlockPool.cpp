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
#include "mcuf/lang/Math.h"
#include "mcuf/util/BlockPool.h"

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
BlockPool::BlockPool(const Memory& memory, uint32_t elementSize) construct Memory(memory){
  this->mElementSize = elementSize;
  this->mCapacity = this->length() / this->mElementSize;
  this->mFlagSize = Math::ceil(this->mCapacity, 8U);
  this->mFlags = static_cast<uint8_t*>(this->pointer(this->length() - this->mFlagSize));
  this->mLastFlag = 0xFFFFFFFF;
  this->mSize = 0;
  
  if((this->mCapacity * this->mElementSize) + this->mFlagSize > this->length())
    --this->mCapacity;
  
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
void* BlockPool::add(const void* element){
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
  
  if(this->mLastFlag < this->mCapacity){
    uint32_t result = this->mLastFlag;
    this->mLastFlag = 0xFFFFFFFF;
    this->setFlag(result, true);
     ++this->mSize;
    
    return this->getBlock(result);
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
      return this->getBlock(i+j);
    } 
  }
  
  return nullptr;  
}

/**
 * 
 */
Memory BlockPool::allocMemory(void){
  if(this->isFull())
    return Memory::nullMemory();
  
  return Memory(this->alloc(), this->mElementSize);
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
  this->mSize = 0;
  memset(this->mFlags, 0x00, this->mFlagSize);
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
void BlockPool::forEach(Consumer<Memory*>& consumer){
  for(int i = 0; i<this->mCapacity; i++){
    if(getFlag(i)){
      Memory memory = Memory(this->getBlock(i), this->elementSize());
      consumer.accept(&memory);
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
  return this->pointer(bytes);
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
  if(!this->inRange(block))
    return 0xFFFFFFFF;
  
  uint32_t addressDelta = (reinterpret_cast<uint32_t>(block) - this->getAddress());
  
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
 