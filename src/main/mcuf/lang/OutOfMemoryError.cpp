/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "mcuf/lang/OutOfMemoryError.hpp"

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::OutOfMemoryError;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 *
 */
OutOfMemoryError::OutOfMemoryError(const char* path, mcuf::lang::String& message) construct Error(path, message){
  this->mType = __FUNCTION__;
  return;
}

/**
 *
 */
OutOfMemoryError::OutOfMemoryError(const char* path, mcuf::lang::String&& message) construct Error(path, message){
  this->mType = __FUNCTION__;
  return;
}

/**
 *
 */
OutOfMemoryError::OutOfMemoryError(const char* path, const char* message) construct Error(path, message){
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
