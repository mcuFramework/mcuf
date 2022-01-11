/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */ 

#include <string.h>

//-----------------------------------------------------------------------------------------
#include "mcuf/lang/Pointer.hpp"

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::Pointer;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
Pointer::Pointer(void){
  this->mPointer = nullptr;
  return;
}

/**
 * 
 */
Pointer::Pointer(void* pointer){
  this->mPointer = (uint8_t*)pointer;
  return;
}

/**
 * 
 */
Pointer::Pointer(uint32_t pointer){
  this->mPointer = (uint8_t*)pointer;
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/**
 * 
 */
bool Pointer::operator==(const void* pointer){
  return (this->mPointer == pointer);
}
  
/**
 * 
 */
bool Pointer::operator==(const Pointer& pointer){
  return (this->mPointer == pointer.mPointer);
}

/* ****************************************************************************************
 * Public Method <Static>
 */

/**
 * 
 */
Pointer Pointer::nullPointer(void){
  return Pointer();
}

/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

/**
 * 
 */
int Pointer::copy(const void* source, uint32_t length){
  return this->copy(source, 0, 0, length);
}

/**
 * 
 */
int Pointer::copy(const void* source, uint32_t shift, uint32_t length){
  return this->copy(source, shift, 0, length);
}

/**
 * 
 */
int Pointer::copy(const void* source, uint32_t shift, uint32_t start, uint32_t length){
  if((source == nullptr) || (this->mPointer == nullptr))
    return 0;  
  
  memcpy(this->pointer(shift), &((uint8_t*)source)[start], length);
  return length;
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
