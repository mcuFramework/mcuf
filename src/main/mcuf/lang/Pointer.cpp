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
  this->mPointer = static_cast<uint8_t*>(pointer);
  return;
}

/**
 * 
 */
Pointer::Pointer(uint32_t pointer){
  this->mPointer = reinterpret_cast<uint8_t*>(pointer);
  return;
}

/**
 * @brief Destroy the Pointer object
 * 
 */
Pointer::~Pointer(void){
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
int Pointer::copy(const void* source, int length){
  return this->copy(source, 0, 0, length);
}

/**
 * @brief 
 * 
 * @param source 
 * @param start 
 * @param length 
 * @return int 
 */
int Pointer::copy(const void* source, int start, int length){
  return this->copy(source, 0, start, length);
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
int Pointer::copy(const void* source, int shift, int start, int length){
  if(length <= 0)
    return 0;  
  
  if((source == nullptr) || (this->mPointer == nullptr))
    return 0;  
  
  if(length <= 0)
    return 0;
  
  memcpy(this->pointer(start), (static_cast<const char*>(source) + shift), static_cast<size_t>(length));
  return length;
}

/**
 * @brief 
 * 
 * @param destination 
 * @param length 
 * @return int 
 */
int Pointer::copyTo(void* destination, int length) const{
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
int Pointer::copyTo(void* destination, int start, int length) const{
  return this->copyTo(destination, 0, start, length);
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
int Pointer::copyTo(void* destination, int shift, int start, int length) const{
  if(length <= 0)
    return 0;
  
  if((destination == nullptr) || (this->mPointer == nullptr))
    return 0;  
  
  if(length <= 0)
    return 0;
  
  memcpy((static_cast<char*>(destination) + shift), this->pointer(start), static_cast<size_t>(length));
  return static_cast<int>(length);
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
