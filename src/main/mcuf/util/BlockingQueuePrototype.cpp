/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "mcuf/util/BlockingQueuePrototype.hpp"

/* ****************************************************************************************
 * Macro
 */  

/* ****************************************************************************************
 * Using
 */  
using mcuf::util::BlockingQueuePrototype;
using mcuf::lang::ArrayPrototype;
using mcuf::lang::Memory;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * Construct.
 */
BlockingQueuePrototype::BlockingQueuePrototype(Memory& memory) construct Array<void*>(memory){
  return;
}
  
/**
 * Construct.
 */
BlockingQueuePrototype::BlockingQueuePrototype(uint32_t length) construct Array<void*>(length){
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

/* ****************************************************************************************
 * Public Method
 */

/**
 *
 */
bool mcuf::util::BlockingQueuePrototype::isEmpty(){
  return this->mEmpty;
}

/**
 * 
 */
bool BlockingQueuePrototype::isFull(void){
  return ((this->mHead == this->mTail) == !this->mEmpty);
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
  
/**
 *
 */
void BlockingQueuePrototype::clear(void){
  this->mHead = 0;
  this->mTail = 0;
  this->mEmpty = true;
  return;
}

/**
 * 
 */
bool BlockingQueuePrototype::offerPointer(void* pointer){
  if(this->isFull())
    return false;

  this->mEmpty = false;
  
  void** p = static_cast<void**>(this->Pointer::mPointer);
  p[this->mHead] = pointer;;  
  
  ++this->mHead;
  if(this->mHead >= this->mElementLength)
    this->mHead = 0;

  return true;
}

/**
 * 
 */
void* BlockingQueuePrototype::pollPointer(void){
  void* result = this->peekPointer();
  if(result == nullptr)
    return nullptr;

  ++this->mTail;
  if(this->mTail >= this->mElementLength)
    this->mTail = 0;
  
  if(this->mHead == this->mTail)
    this->mEmpty = true;
  
  return result;
}

/**
 *
 */
void* BlockingQueuePrototype::peekPointer(void){
  if(this->isEmpty())
    return nullptr;
  
  void** p = static_cast<void**>(this->Pointer::mPointer);
  
  return p[this->mTail];
}

/**
 *
 */
uint32_t BlockingQueuePrototype::size(void){
  if(this->mEmpty)
    return 0;
  
  if(this->isFull())
    return this->mElementLength;

  if(this->mTail > this->mHead)
    return this->mTail - this->mHead;

  else
    return (this->mElementLength - this->mHead) + this->mTail;
}

/* ****************************************************************************************
 * Private Method
 */
 
/* ****************************************************************************************
 * End of file
 */ 
