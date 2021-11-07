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
#include "mcuf/lang/Throwable.hpp"
 
/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::Throwable;
using mcuf::lang::String;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 *
 */
Throwable::Throwable(const char* path, mcuf::lang::String& message) construct mMessage(message){
  this->mType = __FUNCTION__;
  this->mPath = path;
  if(this->mPath == nullptr)
    this->mPath = "NULL";
  return;
}

/**
 *
 */
Throwable::Throwable(const char* path, mcuf::lang::String&& message) construct Throwable(path, message){
  return;
}

/**
 *
 */
Throwable::Throwable(const char* path, const char* message) construct Throwable(path, String(message)){
  return;
}



/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */
 
/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

/**
 *
 */
String Throwable::getMessage(void){
  return this->mMessage;
}

/**
 *
 */
String Throwable::getPath(void){
  return this->mPath;
}

/**
 *
 */
String Throwable::getType(void){
  return this->mType;
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