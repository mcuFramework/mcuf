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
#include "mcuf/lang/number/Integer.h"

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::number::Integer; 

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/**
 * 
 */
Integer::Integer(int value){
  this->mValue = value;
  return;
}

/**
 * 
 */
Integer::operator int(){
  return this->mValue;
}

/**
 * 
 */  
bool Integer::operator==(int v){
  return (this->mValue == static_cast<int>(v));
}

/**
 * 
 */
bool Integer::operator==(Integer& v){
  return (this->mValue == v.mValue);
}

/**
 * 
 */
bool Integer::operator==(Number& v){
  return (this->mValue == v.intValue());
}

/**
 * 
 */
int Integer::operator=(int v){
  this->mValue = v;
  return this->mValue;
}

/**
 * 
 */
Integer Integer::operator+=(int v){
  this->mValue += v;
  return *this;
}

/**
 * 
 */
Integer Integer::operator-=(int v){
  this->mValue -= v;
  return *this;
}

/**
 * 
 */
Integer Integer::operator*=(int v){
  this->mValue *= v;
  return *this;
}

/**
 * 
 */
Integer Integer::operator/=(int v){
  this->mValue /= v;
  return *this;
}

/**
 * 
 */
Integer Integer::operator++(int){
  Integer tmp = *this;
  ++this->mValue;
  return tmp;
}

/**
 * 
 */
Integer Integer::operator++(){
  ++this->mValue;
  return *this;
}

/**
 * 
 */
Integer Integer::operator--(int){
  Integer tmp = *this;
  --this->mValue;
  return tmp;
}

/**
 * 
 */
Integer& Integer::operator--(void){
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