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
#include "mcuf/lang/Throwable.h"
 
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
 * @brief Construct a new Throwable:: Throwable object
 * 
 */
Throwable::Throwable(void) :
mMessage("NULL"){

  return;
}

/**
 * @brief Construct a new Throwable:: Throwable object
 * 
 * @param message 
 */
Throwable::Throwable(String& message) : 
mMessage(message.clone()){

  return;
}

/**
 * @brief Destroy the Throwable object
 * 
 */
Throwable::~Throwable(void){
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
const char* Throwable::getMessage(void) const{
  return this->mMessage;
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
