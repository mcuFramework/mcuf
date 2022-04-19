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
#include "mcuf/lang/ArrayPrototype.h"

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
 * @brief Construct a new Array Prototype:: Array Prototype object
 * 
 * @param memory 
 * @param elementSize 
 */
ArrayPrototype::ArrayPrototype(const Memory& memory, size_t elementSize) : Memory(memory){
  this->mElementSize = static_cast<int>(elementSize);
  this->mElementLength = (this->length() / this->mElementSize); 
  return;
}

/**
 * @brief Construct a new Array Prototype:: Array Prototype object
 * 
 * @param length 
 * @param elementSize 
 */
ArrayPrototype::ArrayPrototype(size_t length, size_t elementSize) : Memory(length * elementSize){
  this->mElementSize = static_cast<int>(elementSize);
  this->mElementLength = this->length() / static_cast<int>(elementSize);
}

/**
 * @brief Destroy the Array Prototype:: Array Prototype object
 * 
 */
ArrayPrototype::~ArrayPrototype(void){
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
int ArrayPrototype::getElementLength(void){
  return this->mElementLength;
}

/**
 *
 */
int ArrayPrototype::getElementSize(void){
  return this->mElementSize;
}

/**
 *
 */
int ArrayPrototype::indexOf(const void* element) const{
  int result = -1;
  
  for(int i=0; i<this->mElementLength; i++){
    const void* dst = &static_cast<uint8_t*>(this->pointer())[i * this->mElementSize];
    
    if(memcmp(dst, element, static_cast<size_t>(this->mElementSize)) != 0)
      continue;

    result = static_cast<int>(i);
    break;
  }

  return result;
}

/**
 * 
 */
void ArrayPrototype::set(const void* src, int shift){
  int location = static_cast<int>(shift * this->mElementSize);
  this->copy(src, 0, location, static_cast<int>(this->mElementSize));
}

/**
 * 
 */
void* ArrayPrototype::get(int shift){
  int location = shift * this->mElementSize;
  if(location >= this->length())
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
