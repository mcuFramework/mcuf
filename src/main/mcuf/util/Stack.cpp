/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "Stack.hpp"
 
/* ****************************************************************************************
 * Using
 */  
using mcuf::util::Stack;
using mcuf::lang::Memory;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
Stack::Stack(void* buffer, uint32_t size){
  this->buffer = (uint8_t*)buffer;
  this->bufferSize = size;
  this->pointer = 0;

  return;
}

/**
 * 
 */
Stack::Stack(Memory& memory){
  this->buffer = (uint8_t*)memory.pointer();
  this->bufferSize = memory.length();
  this->pointer = 0;

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
 * Removes all of the elements from this collection. The collection will be empty after 
 * this method returns.
 */
void Stack::clear(void){
  this->pointer = 0;
}

/**
 * Performs the given action for each element of the Iterable until all elements have 
 * been processed or the action throws an exception. Unless otherwise specified by the 
 * implementing class, actions are performed in the order of iteration (if an iteration 
 * order is specified). 
 *
 * @param Consumer<Memory&>-action The action to be performed for each element.
 */
void Stack::forEach(mcuf::function::Consumer<mcuf::lang::Memory&>& action){
  return;
}

/**
 * Returns true if this collection contains no elements.
 * 
 * @return true if this collection contains no elements.
 */
bool Stack::isEmpty(void){
  return !(this->pointer == 0);
}


uint32_t Stack::size(void){
  return this->pointer;
}

/* ****************************************************************************************
 * Public Method
 */

/**
 * 
 */
uint32_t Stack::getFree(void){
  return (this->bufferSize - this->pointer);
}

/**
 * 
 */
uint32_t Stack::length(void){
  return this->bufferSize;
}

/**
 * 
 */
void* Stack::alloc(uint32_t size){
  if(this->getFree() < size)
    return nullptr;

  void* result = &this->buffer[this->pointer];
  this->pointer += size;

  return result;
}

/**
 * 
 */
Memory Stack::allocMemory(uint32_t size){
  return Memory(this->alloc(size), size);
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
