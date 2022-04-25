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

//-----------------------------------------------------------------------------------------
#include "mcuf/lang/managerment/SystemRegister.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::lang::managerment::SystemRegister;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new System Register object
 * 
 */
SystemRegister::SystemRegister(void){
  return;
}

/**
 * @brief Destroy the System Register object
 * 
 */
SystemRegister::~SystemRegister(void){
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
 * @brief Set the Input Stream object
 * 
 * @param inputStream 
 */
void SystemRegister::setInputStreamBuffer(mcuf::io::InputStreamBuffer* inputStreamBuffer){
  this->mInputStreamBuffer = inputStreamBuffer;
  return;
}

/**
 * @brief Set the Print Stream object
 * 
 * @param printStream 
 */
void SystemRegister::setPrintStream(mcuf::io::PrintStream* printStream){
  this->mPrintStream = printStream;
  return;
}

/**
 * @brief Set the Error Code Handler object
 * 
 * @param errorCodeHandler 
 */
void SystemRegister::setErrorCodeHandler(ErrorCodeHandler errorCodeHandler){
  this->mErrorCodeHandler = errorCodeHandler;
  return;
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
