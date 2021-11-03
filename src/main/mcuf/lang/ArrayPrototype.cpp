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
using mcuf::lang::ArrayPrototype;
using mcuf::lang::Memory;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/** 
 * 
 */
ArrayPrototype::ArrayPrototype(Memory& memory, uint32_t elementSize) construct Memory(memory){
  this->mElementSize = elementSize;
  this->mElementLength = (this->mLength / this->mElementSize); 
  return;
}

/**
 *
 */
ArrayPrototype::ArrayPrototype(void* pointer, uint32_t size, uint32_t elementSize) construct Memory(pointer, size){
  this->mElementSize = elementSize;
  this->mElementLength = (this->mLength / this->mElementSize); 
  return;
}

/**
 *
 */
ArrayPrototype::ArrayPrototype(const void* pointer, uint32_t size, uint32_t elementSize) construct Memory(pointer, size){
  this->mElementSize = elementSize;
  this->mElementLength = (this->mLength / this->mElementSize);
  return;
}


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
void ArrayPrototype::set(const void* src, uint32_t shift){
  uint32_t location = shift * this->mElementSize;
  this->copy(src, location, this->mElementSize);
}

/**
 * 
 */
void* ArrayPrototype::get(uint32_t shift){
  uint32_t location = shift * this->mElementSize;
  if(location >= this->mLength)
    return nullptr;
  
  return this->pointer(location);
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
