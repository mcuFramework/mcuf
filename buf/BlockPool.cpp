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
#include "./BlockPool.h"

/* ****************************************************************************************
 * Using
 */  
using mcuf::Maths;
using buf::BlockPool;
using mcuf::Memory;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
BlockPool::BlockPool(const Memory& memory, uint32_t elementSize) : Memory(memory){
  this->mElementSize = elementSize;
  this->mCapacity = static_cast<uint32_t>(this->length()) / this->mElementSize;
  this->mFlagSize = Maths::ceil(this->mCapacity, 8U);
  this->mFlags = static_cast<uint8_t*>(this->pointer(static_cast<uint32_t>(this->length()) - this->mFlagSize));
  this->mLastFlag = 0xFFFFFFFF;
  this->mSize = 0;
  
  if((this->mCapacity * this->mElementSize) + this->mFlagSize > static_cast<uint32_t>(this->length()))
    --this->mCapacity;
  
  return;
}

/**
 *
 */
BlockPool::~BlockPool(void){
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
    
  for(uint32_t i=0, bytes=0; i < this->mCapacity; i+=8, ++bytes){
    if(this->mFlags[bytes] == 0xFF)
      continue;
      
    for(uint32_t j=0; j<8; j++){
      uint8_t mask = static_cast<uint8_t>(1<<j);
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
uint32_t BlockPool::capacity(void) const{
  return this->mCapacity;
}

/**
 * 
 */
void BlockPool::clear(void){
  this->mSize = 0;
  memset(this->mFlags, 0x00, this->mFlagSize);
  return;
}

/**
 * 
 */
uint32_t BlockPool::elementSize(void) const{
  return this->mElementSize;
}

/**
 * 
 */
bool BlockPool::isEmpty(void) const{
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
int BlockPool::size(void) const{
  return static_cast<int>(this->mSize);
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
void* BlockPool::getBlock(uint32_t shift) const{
  if(shift >= this->mCapacity)
    return nullptr;
  
  uint32_t bytes = shift * this->mElementSize;
  return this->pointer(static_cast<int>(bytes));
}

/**
 *
 */
bool BlockPool::getFlag(uint32_t shift) const{
  
  uint32_t bytes = (shift >> 3);
  uint8_t mask = static_cast<uint8_t>(1 << (shift & 0x00000007));
  
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
