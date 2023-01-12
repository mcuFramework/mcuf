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
#include "./Throwable.h"
 
/* ****************************************************************************************
 * Using
 */  
using mcuf::Throwable;
using mcuf::Strings;

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
Throwable::Throwable(const Strings& message) : 
mMessage(message.clone()){

  return;
}

/**
 * @brief Construct a new Throwable object
 * 
 * @param message 
 */
Throwable::Throwable(mcuf::Strings&& message) : 
mMessage(message){

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
