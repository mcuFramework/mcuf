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
#include "./Fifo.h"
 
/* ****************************************************************************************
 * Using
 */  
using mcuf::BiConsumer;
using mcuf::Memory;
using mcuf::Pointer;
using mcuf::Fifo;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
Fifo::Fifo(const Memory& memory, uint32_t elementSize) :
Memory(memory){
  this->mElementSize = static_cast<uint16_t>(elementSize);
  this->mElementLength = static_cast<uint16_t>(static_cast<uint32_t>(memory.length()) / elementSize);
  this->mHead = 0;
  this->mTail = 0;
  this->mEmpty = true;
  return;
}

/**
 * @brief Construct a new Fifo object
 * 
 * @param size 
 * @param elementSize 
 */
Fifo::Fifo(uint32_t size, uint32_t elementSize) : 
Memory(size * elementSize){
  this->mElementSize = static_cast<uint16_t>(elementSize);
  this->mElementLength = static_cast<uint16_t>(size);
  this->mHead = 0;
  this->mTail = 0;
  this->mEmpty = true;
}


/**
 *
 */
Fifo::~Fifo(void){
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
void Fifo::forEach(void* attachment, BiConsumer<Memory*, void*>& action) const{
  if(this->isEmpty())
    return;
  
  for(uint32_t i=this->mTail; i!=this->mHead; i++){
    if(i>=this->mElementLength)
      i=0;

    Memory memory = this->subMemory((this->mElementSize * i), this->mElementSize);
    action.accept(&memory, attachment);
  }
}

/**
 *
 */
bool Fifo::isEmpty(void) const{
  return this->mEmpty;
}

/**
 *
 */
int Fifo::size(void) const{
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
bool Fifo::insertHead(const Memory& memory){
  return this->insertHead(memory.pointer());
}

/**
 * 
 */
bool Fifo::insertHead(void* pointer){
  if(this->isFull())
    return false;

  this->mEmpty = false;
  this->copy(pointer, 0, (this->mElementSize * this->mHead),  this->mElementSize);
  
  ++this->mHead;
  if(this->mHead >= this->mElementLength)
    this->mHead = 0;

  return true;
}

/**
 * 
 */
bool Fifo::isFull(void) const{
  return ((this->mHead == this->mTail) == !this->mEmpty);
}

/**
 * 
 */
uint32_t Fifo::length(void) const{
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
  
  this->copyTo(pointer, 0, (this->mElementSize * this->mTail), this->mElementSize);

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
