/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "Fifo.hpp"
 
/* ****************************************************************************************
 * Using
 */  
using mcuf::function::Consumer;
using mcuf::lang::Memory;
using mcuf::lang::Pointer;
using mcuf::util::Fifo;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
Fifo::Fifo(void* memory, uint32_t size, uint32_t elementSize) :
      mMemory(memory, size){

  this->mElementSize = elementSize;
  this->mLength = (size / elementSize);
  this->mHead = 0;
  this->mTail = 0;
  this->mEmpty = true;
  return;
}

/**
 * 
 */
Fifo::Fifo(Memory& memory, uint32_t elementSize) :
      mMemory(memory){
  
  this->mElementSize = elementSize;
  this->mLength = (memory.length() / elementSize);
  this->mHead = 0;
  this->mTail = 0;
  this->mEmpty = true;
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
void Fifo::clear(void){
  this->mHead = 0;
  this->mTail = 0;
  this->mEmpty = true;
  return;
}

/**
 *
 */
void Fifo::forEach(Consumer<Memory>& action){
  if(this->isEmpty())
    return;
  
  for(int i=this->mTail; i!=this->mHead; i++){
    if(i>=this->mLength)
      i=0;

    Memory memory = this->mMemory.subMemory((this->mElementSize * i), this->mElementSize);
    action.accept(memory);
  }
}

/**
 *
 */
bool Fifo::isEmpty(void){
  return this->mEmpty;
}

/**
 *
 */
uint32_t Fifo::size(void){
  if(this->mEmpty)
    return 0;
  
  if(this->isFull())
    return this->mLength;

  if(this->mTail > this->mHead)
    return this->mTail - this->mHead;

  else
    return (this->mLength - this->mHead) + this->mTail;
}

/* ****************************************************************************************
 * Public Method
 */

/**
 * 
 */
Memory Fifo::getHead(void){
  void* result = this->getHeadPointer();
  if(result == nullptr)
    return Memory::nullMemory();
  
  return Memory(result, this->mElementSize);
}

/**
 * 
 */
void* Fifo::getHeadPointer(void){
  if(this->mEmpty)
    return nullptr;
  
  return mMemory.pointer(this->mHead * this->mElementSize);
}

/**
 * 
 */
Memory Fifo::getTail(void){
  void* result = this->getTailPointer();
  if(result == nullptr)
    return Memory::nullMemory();
  
  return Memory(result, this->mElementSize);
}

/**
 * 
 */
void* Fifo::getTailPointer(void){
  if(this->mEmpty)
    return nullptr;
  
  return mMemory.pointer(this->mTail * this->mElementSize);
}
  
/**
 * 
 */
bool Fifo::insertHead(Memory& memory){
  return this->insertHead(memory.pointer());
}

/**
 * 
 */
bool Fifo::insertHead(void* pointer){
  if(this->isFull())
    return false;

  this->mEmpty = false;
  mMemory.copy(pointer, (this->mElementSize * this->mHead), 0, this->mElementSize);
  
  ++this->mHead;
  if(this->mHead >= this->mLength)
    this->mHead = 0;

  return false;
}

/**
 * 
 */
bool Fifo::isFull(void){
  return ((this->mHead == this->mTail) == !this->mEmpty);
}

/**
 * 
 */
uint32_t Fifo::length(void){
  return this->mLength;
}

/**
 * 
 */
bool Fifo::popTail(Memory& memory){
  return popTail(memory.pointer());
}

/**
 * 
 */
bool Fifo::popTail(void* pointer){
  if(this->isEmpty())
    return false;
  
  Pointer p = pointer;
  p.copy(mMemory.pointer(this->mElementSize * this->mTail), 0, 0, this->mElementSize);

  ++this->mTail;
  if(this->mTail >= this->mLength)
    this->mTail = 0;
  
  if(this->mHead == this->mTail)
    this->mEmpty = true;
  
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
