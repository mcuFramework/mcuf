/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */ 
#include "Pointer.hpp"

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
 * Operator equal
 */
void* Pointer::operator=(void* pointer){
  this->mPointer = (uint8_t*)pointer;

  return this->mPointer;
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
Pointer Pointer::getPointer(void){
  return *this;
}

/**
 * 
 */
Pointer Pointer::getPointer(uint32_t offset){
  return Pointer(&((uint8_t*)this->mPointer)[offset]);
}

/**
 * 
 */
uint32_t Pointer::getValue(void){
  return reinterpret_cast<uint32_t>(this->mPointer);
}

/**
 * 
 */
bool Pointer::isNull(void){
  return (this->mPointer == nullptr);
}

/**
 * 
 */
void* Pointer::pointer(void){
  return this->mPointer;
}

/**
 * 
 */
void* Pointer::pointer(uint32_t offset){
  return &((uint8_t*)this->mPointer)[offset];
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
