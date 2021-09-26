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
using mcuf::lang::number::Boolean;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
Boolean::Boolean(void){
  this->mValue = 0;
  return;
}

/**
 * 
 */
Boolean::Boolean(bool valuealue){
  this->mValue = valuealue;
  return;
}


/* ****************************************************************************************
 * Boolean::operator Method
 */

/**
 * 
 */
Boolean::operator bool(void){
  return this->mValue;
}

/**
 * 
 */
bool Boolean::operator==(bool valuealue){
  return (static_cast<bool>(this->mValue) == valuealue);
}

/**
 * 
 */
bool Boolean::operator==(Boolean& value){
  return (this->mValue == value.mValue);
}

/**
 * 
 */
bool Boolean::operator==(Number& value){
  return (this->mValue == value.intValue());
}

/**
 * 
 */
bool Boolean::operator=(bool value){
  this->mValue = value;
  return this->mValue;
}

/**
 * 
 */
Boolean Boolean::operator+=(int value){
  if(value > 0)
    this->mValue = 1;
  
  else if(value < 0)
    this->mValue = 0;
  
  return *this;
}

/**
 * 
 */
Boolean Boolean::operator-=(int value){
  if(value < 0)
    this->mValue = 1;
  
  else if(value > 0)
    this->mValue = 0;
  
  return *this;
}

/**
 * 
 */
Boolean Boolean::operator*=(int value){
  this->mValue *= value;
  return *this;
}

/**
 * 
 */
Boolean Boolean::operator/=(int value){
  this->mValue /= value;
  return *this;
}

/**
 * 
 */
Boolean Boolean::operator++(int){
  Boolean tmp = *this;
  ++this->mValue;
  return tmp;
}

/**
 * 
 */
Boolean Boolean::operator++(){
  ++this->mValue;
  return *this;
}

/**
 * 
 */
Boolean Boolean::operator--(int){
  Boolean tmp = *this;
  --this->mValue;
  return tmp;
}
  
/**
 * 
 */
Boolean& Boolean::operator--(){
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