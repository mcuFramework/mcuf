/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "mcuf/lang/Exception.hpp"

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::Exception;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */
 
/**
 *
 */
Exception::Exception(const char* path, mcuf::lang::String& message) construct Throwable(path, message){
  this->mType = __FUNCTION__;
  return;
}

/**
 *
 */
Exception::Exception(const char* path, mcuf::lang::String&& message) construct Throwable(path, message){
  this->mType = __FUNCTION__;
  return;
}

/**
 *
 */
Exception::Exception(const char* path, const char* message) construct Throwable(path, message){
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
