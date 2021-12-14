/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "mcuf/lang/NotAlignmentException.hpp"

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::NotAlignmentException;
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
NotAlignmentException::NotAlignmentException(const char* path, String& message) construct Exception(path, message){
  this->mType = __FUNCTION__;
  return;
}

/**
 *
 */
NotAlignmentException::NotAlignmentException(const char* path, String&& message) construct Exception(path, message){
  this->mType = __FUNCTION__;
  return;
}

/**
 *
 */
NotAlignmentException::NotAlignmentException(const char* path, const char* message) construct Exception(path, message){
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
