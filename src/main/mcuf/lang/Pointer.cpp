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
#include "mcuf/lang/Pointer.h"

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
 * @brief 
 * 
 * @param source 
 * @param length 
 * @return int 
 */
int Pointer::copy(const void* source, uint32_t length){
  return this->copy(source, 0, 0, length);
}

/**
 * @brief 
 * 
 * @param source 
 * @param shift 
 * @param length 
 * @return int 
 */
int Pointer::copy(const void* source, uint32_t shift, uint32_t length){
  return this->copy(source, shift, 0, length);
}

/**
 * @brief 
 * 
 * @param source 
 * @param shift 
 * @param start 
 * @param length 
 * @return int 
 */
int Pointer::copy(const void* source, uint32_t shift, uint32_t start, uint32_t length){
  if((source == nullptr) || (this->mPointer == nullptr))
    return 0;  
  
  memcpy(this->pointer(shift), &(static_cast<const char*>(source))[start], length);
  return length;
}

/**
 * @brief 
 * 
 * @param destination 
 * @param length 
 * @return int 
 */
int Pointer::copyTo(void* destination, uint32_t length) const{
  return this->copyTo(destination, 0, 0, length);
}

/**
 * @brief 
 * 
 * @param destination 
 * @param shift 
 * @param length 
 * @return int 
 */
int Pointer::copyTo(void* destination, uint32_t shift, uint32_t length) const{
  return this->copyTo(destination, shift, 0, length);
}

/**
 * @brief 
 * 
 * @param destination 
 * @param shift 
 * @param start 
 * @param length 
 * @return int 
 */
int Pointer::copyTo(void* destination, uint32_t shift, uint32_t start, uint32_t length) const{
  if((destination == nullptr) || (this->mPointer == nullptr))
    return 0;  
  
  memcpy(&(static_cast<char*>(destination))[shift], this->pointer(start), length);
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
