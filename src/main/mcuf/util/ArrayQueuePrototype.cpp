/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "mcuf/util/ArrayQueuePrototype.h"
#include "mcuf/lang/System.h"

/* ****************************************************************************************
 * Macro
 */  

/* ****************************************************************************************
 * Using
 */  
using mcuf::util::ArrayQueuePrototype;
using mcuf::lang::ArrayPrototype;
using mcuf::lang::Memory;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Array Queue Prototype:: Array Queue Prototype object
 * 
 * @param memory 
 */
ArrayQueuePrototype::ArrayQueuePrototype(const Memory& memory) : Array<void*>(memory){
  this->clear();
  return;
}

/**
 * @brief Construct a new Array Queue Prototype:: Array Queue Prototype object
 * 
 * @param length 
 */
ArrayQueuePrototype::ArrayQueuePrototype(uint32_t size) : Array<void*>(size){
  this->clear();
  return;
}

/**
 * @brief Destroy the Array Queue Prototype:: Array Queue Prototype object
 * 
 */
ArrayQueuePrototype::~ArrayQueuePrototype(void){
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
  
/**
 *
 */
void ArrayQueuePrototype::clear(void){
  this->mHead = 0;
  this->mTail = 0;
  this->mEmpty = true;
  return;
}

/**
 * 
 */
bool ArrayQueuePrototype::offerPointer(void* pointer){
  if(this->isFull())
    return false;

  this->mEmpty = false;
  
  void** p = static_cast<void**>(this->Pointer::pointer());
  p[this->mHead] = pointer;  
  
  ++this->mHead;
  if(this->mHead >= this->mElementLength)
    this->mHead = 0;

  return true;
}

/**
 * 
 */
void* ArrayQueuePrototype::pollPointer(void){
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
void* ArrayQueuePrototype::peekPointer(void){
  if(this->isEmpty())
    return nullptr;
  
  void** p = static_cast<void**>(this->Pointer::pointer());
  
  return p[this->mTail];
}

/**
 *
 */
int ArrayQueuePrototype::size(void) const{
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
