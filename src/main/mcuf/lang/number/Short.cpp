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
using mcuf::lang::number::Short;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
Short::Short(short value){
  this->mValue = value;
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/**
 * 
 */
Short::operator short(void){
  return this->mValue;
}

/**
 * 
 */  
bool Short::operator==(int v){
  return (this->mValue == static_cast<int>(v));
}

/**
 * 
 */
bool Short::operator==(Short& v){
  return (this->mValue == v.mValue);
}

/**
 * 
 */
bool Short::operator==(Number& v){
  return (this->mValue == v.intValue());
}

/**
 * 
 */
Short Short::operator=(Short v){
  this->mValue = v;
  return this->mValue;
}

/**
 * 
 */
Short Short::operator+=(int v){
  this->mValue += v;
  return *this;
}

/**
 * 
 */
Short Short::operator-=(int v){
  this->mValue -= v;
  return *this;
}

/**
 * 
 */
Short Short::operator*=(int v){
  this->mValue *= v;
  return *this;
}

/**
 * 
 */
Short Short::operator/=(int v){
  this->mValue /= v;
  return *this;
}

/**
 * 
 */
Short Short::operator++(int){
  Short tmp = *this;
  ++this->mValue;
  return tmp;
}

/**
 * 
 */
Short Short::operator++(void){
  ++this->mValue;
  return *this;
}

/**
 * 
 */
Short Short::operator--(int){
  Short tmp = *this;
  --this->mValue;
  return tmp;
}

/**
 * 
 */
Short& Short::operator--(void){
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