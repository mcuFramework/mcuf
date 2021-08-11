/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "../util/Fifo.hpp"
 
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
Fifo::Fifo(Memory memory, uint32_t elementSize) :
      mMemory(memory){
  
  this->mElementSize = elementSize;
  this->mHead = 0;
  this->mTail = 0;
  this->mCapacity = (memory.length() / elementSize);
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
  return;
}

/**
 *
 */
void Fifo::forEach(Consumer<Memory>& action){

}

/**
 *
 */
bool Fifo::isEmpty(void){

}

/**
 *
 */
uint32_t Fifo::size(void){

}

/* ****************************************************************************************
 * Public Method
 */

/**
 * 
 */
void Fifo::flush(void){

}

/**
 * 
 */
Memory Fifo::getHead(void){

}

/**
 * 
 */
void* Fifo::getHeadPointer(void){

}

/**
 * 
 */
Memory Fifo::getTail(void){

}

/**
 * 
 */
void* Fifo::getTailPointer(void){

}
  
/**
 * 
 */
bool Fifo::insert(Memory memory){

}

/**
 * 
 */
bool Fifo::insert(void* pointer){

}

/**
 * 
 */
bool Fifo::isFull(void){

}

/**
 * 
 */
bool Fifo::pop(Memory memory){

}

/**
 * 
 */
bool Fifo::pop(void* pointer){

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
