/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "mcuf/lang/IllegalArgumentException.hpp"

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::IllegalArgumentException;
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
IllegalArgumentException::IllegalArgumentException(const char* path, String& message) construct Exception(path, message){
  this->mType = __FUNCTION__;
  return;
}

/**
 *
 */
IllegalArgumentException::IllegalArgumentException(const char* path, String&& message) construct Exception(path, message){
  this->mType = __FUNCTION__;
  return;
}

/**
 *
 */
IllegalArgumentException::IllegalArgumentException(const char* path, const char* message) construct Exception(path, message){
  this->mType = __FUNCTION__;
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
