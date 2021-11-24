/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "mcuf/io/IOException.hpp"

/* ****************************************************************************************
 * Using
 */  
using mcuf::io::IOException;

/* ****************************************************************************************
 * Macro
 */
 
/* ****************************************************************************************
 * Variable
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 *
 */
IOException::IOException(const char* path, mcuf::lang::String& message) construct Exception(path, message){
  this->mType = __FUNCTION__;
  return;
}

/**
 *
 */
IOException::IOException(const char* path, mcuf::lang::String&& message) construct Exception(path, message){
  this->mType = __FUNCTION__;
  return;
}

/**
 *
 */
IOException::IOException(const char* path, const char* message) construct Exception(path, message){
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
 * Private Method <Static>
 */
 
/* ****************************************************************************************
 * Private Method
 */
 
/* ****************************************************************************************
 * End of file
 */ 