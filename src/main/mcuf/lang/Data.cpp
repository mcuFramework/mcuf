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

//-----------------------------------------------------------------------------------------
#include "mcuf/lang/Data.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::lang::Data;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Data object
 * 
 */
Data::Data(void) :
Pointer(){
  this->mLength = 0;
  return;
}

/**
 * @brief Construct a new Memory object
 * 
 * @param pointer 
 * @param length 
 */
Data::Data(const void* pointer, size_t length) : 
Pointer(pointer){
  
  if(length & 0x80000000)
    length = 0;
  
  this->mLength = (length | 0x80000000);
  return;
}

/**
 * @brief Construct a new Memory object
 * 
 * @param pointer 
 * @param length 
 */
Data::Data(void* pointer, size_t length) : 
Pointer(pointer){
  if(length & 0x80000000)
    length = 0;
  
  this->mLength = length;
}

/**
 * @brief Construct a new Data:: Data object
 * 
 * @param other 
 */
Data::Data(const Data& other){
  *this = other;
  return;
}

/**
 * @brief Destroy the Data object
 * 
 */
Data::~Data(void){
  this->mLength = 0;
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/**
 * @brief 
 * 
 * @param pointer 
 * @param value 
 * @param length 
 */
void Data::wipe(void* pointer, uint8_t value, int length){
  if(length <= 0)
    return;

  memset(pointer, value, static_cast<uint32_t>(length));
  return;
}

/**
 * @brief 
 * 
 * @param pointer 
 * @param length 
 */
void Data::wipe(void* pointer, int length){
  Data::wipe(pointer, 0x00, length);
  return;
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::lang::Pointer
 */

/**
 * @brief 
 * 
 * @param source 
 * @param length 
 * @return int32_t 
 */
int Data::copy(const void* source, int length){
  return Data::copy(source, 0, 0, length);
}

/**
 * @brief 
 * 
 * @param source 
 * @param start 
 * @param length 
 * @return int32_t 
 */
int Data::copy(const void* source, int start, int length){
  return Data::copy(source, 0, start, length);
}

/**
 * @brief 
 * 
 * @param source 
 * @param shift 
 * @param start 
 * @param length 
 * @return int32_t 
 */
int Data::copy(const void* source, int shift, int start, int length){
  if(length <= 0)
    return 0;
  
  if(this->isReadOnly())
    return 0;
  
  int max = this->length();
  
  if(shift > max)
    return 0;
  
  if(length > (max - shift))
    length = (max - shift);
  
  return Pointer::copy(source, shift, start, length);
}

/* ****************************************************************************************
 * Public Method
 */

/**
 * @brief 
 * 
 * @return int 
 */
int Data::wipe(void){
  return this->wipe(0x00, 0, 0);
}

/**
 * @brief 
 * 
 * @param value 
 * @return int 
 */
int Data::wipe(uint8_t value){
  return this->wipe(value, 0, 0);
}

/**
 * @brief 
 * 
 * @param value 
 * @param start 
 * @return int 
 */
int Data::wipe(uint8_t value, int length){
  return this->wipe(value, 0, length);
}
  
/**
 * @brief 
 * 
 * @param value 
 * @param start 
 * @param length 
 * @return int 
 */
int Data::wipe(uint8_t value, int start, int length){
  if(this->isReadOnly())
    return 0;
  
  if(length <= 0)
    return 0;
  
  int max = this->length();
  if((start + length) > max)
    length = max - start;
  
  memset(this->pointer(start), value, static_cast<size_t>(length));
  return length;
}

/**
 * @brief 
 * 
 * @param address 
 * @return true 
 * @return false 
 */
bool Data::inRange(void* address) const{
  uint32_t start = reinterpret_cast<uint32_t>(this->pointer());
  uint32_t end = start + static_cast<uint32_t>(this->length());
  uint32_t adr = reinterpret_cast<uint32_t>(address);
  
  if((adr < start) && (adr >= end))
    return false;
  
  return true; 
}

/**
 * @brief 
 * 
 * @param beginIndex 
 * @return Memory 
 */
Data Data::subData(uint32_t beginIndex) const{
  uint32_t max = static_cast<size_t>(this->length());
  
  if(beginIndex >= max)
    return Data();
  
  uint32_t length = max - beginIndex;

  return Data(this->pointer(static_cast<int>(beginIndex)), length);
}

/**
 * @brief 
 * 
 * @param beginIndex 
 * @param length 
 * @return Memory 
 */
Data Data::subData(uint32_t beginIndex, uint32_t length) const{
  uint32_t max = static_cast<size_t>(this->length());
  
  if(beginIndex >= max)
    return Data();

  uint32_t remainingLength = (max - beginIndex);
  if(length >= remainingLength)
    length = remainingLength;
  

  return Data(this->pointer(static_cast<int>(beginIndex)), length);
}

/**
 * @brief 
 * 
 * @param source 
 * @param shift 
 * @param start 
 * @param length 
 * @return int32_t 
 */
int Data::insertArray(const void* source, int start, int length){
  return this->insertArray(source, 0, start, length);
}

/**
 * @brief 
 * 
 * @param source 
 * @param shift 
 * @param start 
 * @param length 
 * @return int32_t 
 */
int Data::insertArray(const void* source, int shift, int start, int length){
  if(length <= 0)
    return 0;
  
  int max = this->length();
  
  if(start + length > max)
    length = max - start;
  
  int less = max - (start + length);
  
  if(less != 0)
    this->copy(this->pointer(start), 0, (start + length), less);
  
  this->copy(source, 0, start, length);
  
  return 0;
}

/**
 * @brief 
 * 
 * @param start 
 * @param length 
 * @return int32_t 
 */
int Data::popArray(int start, int length){
  return this->popArray(nullptr, 0, start, length);
}

/**
 * @brief 
 * 
 * @param source 
 * @param start 
 * @param length 
 * @return int32_t 
 */
int Data::popArray(void* source, int start, int length){
  return this->popArray(source, 0, start, length);
}

/**
 * @brief 
 * 
 * @param source 
 * @param shift 
 * @param start 
 * @param length 
 * @return true 
 * @return false 
 */
int Data::popArray(void* source, int shift, int start, int length){
  if(length <= 0)
    return 0;
  
  int max = this->length();
  
  if(start + length > max)
    length = max - start;
  
  int less = max - (start + length);
  
  if(source != nullptr)
    this->copyTo(source, shift, start, length);
  
  if(less != 0)
    this->copy(this->pointer(start), 0, (start + length), less);
  
  this->wipe(0x00, (start + less), length);
  
  return length;
}

/**
 * @brief 
 * 
 * @param ch 
 * @return int 
 */
int Data::indexOf(char ch) const{
  return this->indexOf(ch, 0);
}

/**
 * @brief 
 * 
 * @param ch 
 * @param offset 
 * @return int 
 */
int Data::indexOf(char ch, int start) const{
  return Pointer::indexOf(ch, start, this->length());
}

/**
 * @brief 
 * 
 * @param destination 
 * @param destinationLen 
 * @param start 
 * @return int 
 */
int Data::indexOfData(const void* destination, int destinationLen, int start) const{
  return Pointer::indexOfData(destination, destinationLen, start, this->length());
}

/**
 * @brief 
 * 
 * @param str 
 * @return int 
 */
int Data::indexOfString(const char* str) const{
  return Pointer::indexOfString(str, this->length());
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
