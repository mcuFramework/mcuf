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
#include "./SystemRegister.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::SystemRegister;

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
void SystemRegister::setInputStreamBuffer(mcuf::InputStreamBuffer* inputStreamBuffer){
  this->mInputStreamBuffer = inputStreamBuffer;
  return;
}

/**
 * @brief Set the Print Stream object
 * 
 * @param printStream 
 */
void SystemRegister::setPrintStream(mcuf::PrintStream* printStream){
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

/**
 * @brief Set the Idle Task object
 * 
 * @param task 
 */
void SystemRegister::setIdleTask(mcuf::function::RunnableEntity task){
  this->mIdleTask = task;
  return;
}

/**
 * @brief Set the Interface Kernel object
 * 
 * @param interfaceKernel 
 */
void SystemRegister::setInterfaceKernel(mcuf::rtos::InterfaceKernel* interfaceKernel){
  this->mInterfaceKernel = interfaceKernel;
  return;
}

/**
 * @brief Set the Interface Thread object
 * 
 * @param interfaceThread 
 */
void SystemRegister::setInterfaceThread(mcuf::rtos::InterfaceThread* interfaceThread){
  this->mInterfaceThread = interfaceThread;
  return;
}

/** 
 * @brief Set the Interface Timer object
 * 
 * @param interfaceTimer 
 */
void SystemRegister::setInterfaceTimer(mcuf::rtos::InterfaceTimer* interfaceTimer){
  this->mInterfaceTimer = interfaceTimer;
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
