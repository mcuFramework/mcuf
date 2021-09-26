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
using mcuf::lang::number::Byte;

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Byte::operator Method
 */

/**
 * 
 */
Byte::Byte(char value){
  this->mValue = value;
  return;
}

/**
 * 
 */
Byte::operator char(void){
  return this->mValue;
}

/**
 * 
 */  
bool Byte::operator==(int v){
  return (this->mValue == static_cast<int>(v));
}

/**
 * 
 */
bool Byte::operator==(Byte& v){
  return (this->mValue == v.mValue);
}

/**
 * 
 */
bool Byte::operator==(Number& v){
  return (this->mValue == v.intValue());
}

/**
 * 
 */
char Byte::operator=(char v){
  this->mValue = v;
  return this->mValue;
}

/**
 * 
 */
Byte Byte::operator+=(int v){
  this->mValue += v;
  return *this;
}

/**
 * 
 */
Byte Byte::operator-=(int v){
  this->mValue -= v;
  return *this;
}

/**
 * 
 */
Byte Byte::operator*=(int v){
  this->mValue *= v;
  return *this;
}

/**
 * 
 */
Byte Byte::operator/=(int v){
  this->mValue /= v;
  return *this;
}

/**
 * 
 */
Byte Byte::operator++(int){
  Byte tmp = *this;
  ++this->mValue;
  return tmp;
}

/**
 * 
 */
Byte Byte::operator++(){
  ++this->mValue;
  return *this;
}

/**
 * 
 */
Byte Byte::operator--(int){
  Byte tmp = *this;
  --this->mValue;
  return tmp;
}

/**
 * 
 */
Byte& Byte::operator--(void){
  --this->mValue;
  return *this;
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