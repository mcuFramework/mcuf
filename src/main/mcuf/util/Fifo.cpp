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
#include "mcuf/util/Fifo.hpp"
 
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
Fifo::Fifo(Memory& memory, uint32_t elementSize) construct Memory(memory){
  this->mElementSize = elementSize;
  this->mElementLength = (memory.length() / elementSize);
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
void Fifo::forEach(Consumer<Memory*>& action){
  if(this->isEmpty())
    return;
  
  for(int i=this->mTail; i!=this->mHead; i++){
    if(i>=this->mElementLength)
      i=0;

    Memory memory = this->subMemory((this->mElementSize * i), this->mElementSize);
    action.accept(&memory);
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
    return this->mElementLength;

  if(this->mTail > this->mHead)
    return this->mTail - this->mHead;

  else
    return (this->mElementLength - this->mHead) + this->mTail;
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
  
  return this->pointer(this->mHead * this->mElementSize);
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
  
  return this->pointer(this->mTail * this->mElementSize);
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
  this->copy(pointer, (this->mElementSize * this->mHead), 0, this->mElementSize);
  
  ++this->mHead;
  if(this->mHead >= this->mElementLength)
    this->mHead = 0;

  return true;
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
  return this->mElementLength;
}

/**
 * 
 */
bool Fifo::popTail(Memory& memory){
  return this->popTail(memory.pointer());
}

/**
 * 
 */
bool Fifo::popTail(void* pointer){
  if(this->isEmpty())
    return false;
  
  Pointer p = pointer;
  p.copy(this->pointer(this->mElementSize * this->mTail), 0, 0, this->mElementSize);

  ++this->mTail;
  if(this->mTail >= this->mElementLength)
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
