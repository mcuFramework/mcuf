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
#include "./Short.h"


/* ****************************************************************************************
 * Using
 */  
using numb::Short;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Short:: Short object
 * 
 */
Short::Short(void){
  return;
}

/**
 * @brief Construct a new Short:: Short object
 * 
 * @param value 
 */
Short::Short(short value){
  Short::mValue.s16[0] = value;
  return;
}

/**
 * @brief Destroy the Short:: Short object
 * 
 */
Short::~Short(void){
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
short Short::valueOf(const char* str){
  return static_cast<short>(atoi(str));
}

/**
 * @brief 
 * 
 * @param str 
 * @return Integer 
 */
Short Short::valueOfShort(const char* str){
  return Short(Short::valueOf(str));
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
