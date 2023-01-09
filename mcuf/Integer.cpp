/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  

#include <stdlib.h>

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "mcuf\Integer.h"

/* ****************************************************************************************
 * Using
 */  
using mcuf::Integer; 

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Integer:: Integer object
 * 
 */
Integer::Integer(void){
  return;
}

/**
 * @brief Construct a new Integer:: Integer object
 * 
 * @param value 
 */
Integer::Integer(int value){
  this->mValue.s32 = value;
  return;
}

/**
 * @brief Destroy the Integer:: Integer object
 * 
 */
Integer::~Integer(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/**
 * @brief 
 * 
 * @param str 
 * @return int 
 */
int Integer::valueOf(const char* str){
  return atoi(str);
}

/**
 * @brief 
 * 
 * @param str 
 * @return Integer 
 */
Integer Integer::valueOfInteger(const char* str){
  return Integer(Integer::valueOf(str));
}

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
