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
#include "mcuf/lang/number/Number.hpp"

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::number::Number;

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */
 
/* ****************************************************************************************
 * Public Method <Override>
 */

/**
 * 
 */
bool Number::booleanValue(void){
  return this->mValue;
}
  
/**
 * 
 */
char Number::byteValue(void){
  return this->mValue;
}

/**
 * 
 */
unsigned char Number::unsignedByteValue(void){
  return this->mValue;
}
  
/**
 * 
 */
short Number::shortValue(void){
  return this->mValue;
}

/**
 * 
 */                                  
unsigned short Number::unsignedShortValue(void){
  return this->mValue;
}

/**
 * 
 */
int Number::intValue(void){
  return this->mValue;
}

/**
 * 
 */
unsigned int Number::unsignedIntValue(void){
  return this->mValue;
}

/**
 * 
 */
float Number::floatValue(void){
  return this->mValue;
}

/**
 * 
 */
bool Number::equal(Number* object){
  return (this->intValue() == object->intValue());
}

/**
 * 
 */
bool Number::equal(Number& object){
  return (this->intValue() == object.intValue());
}

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