/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "mcuf/io/WritePendingException.hpp"

/* ****************************************************************************************
 * Macro
 */  

/* ****************************************************************************************
 * Using
 */  
using mcuf::io::WritePendingException;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 *
 */
WritePendingException::WritePendingException(const char* path, mcuf::lang::String& message) construct IOException(path, message){
  this->mType = __FUNCTION__;
  return;
}

/**
 *
 */
WritePendingException::WritePendingException(const char* path, mcuf::lang::String&& message) construct IOException(path, message){
  this->mType = __FUNCTION__;
  return;
}

/**
 *
 */
WritePendingException::WritePendingException(const char* path, const char* message) construct IOException(path, message){
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
