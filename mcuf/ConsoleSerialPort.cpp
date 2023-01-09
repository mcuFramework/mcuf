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
#include "mcuf\ConsoleSerialPort.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::ConsoleSerialPort;
using hal::SerialPort;
using mcuf::PrintStream;
using mcuf::InputStreamBuffer;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */
/**
 * @brief Construct a new Console Serial Port object
 * 
 * @param serialPort 
 * @param formatSize 
 * @param bufferSize 
 */
ConsoleSerialPort::ConsoleSerialPort(SerialPort& serialPort, uint32_t formatSize, uint32_t bufferSize) :
mSerialPort(serialPort),
mOutputStreamHandler(this->mSerialPort, bufferSize),
mPrintStream(this->mOutputStreamHandler, formatSize){
  
  return;
}

/**
 * @brief Destroy the Console Serial Port object
 * 
 */
ConsoleSerialPort::~ConsoleSerialPort(void){
  return;
}
/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - mcuf::Console
 */
/**
 * @brief 
 * 
 * @return mcuf::PrintStream& 
 */
PrintStream& ConsoleSerialPort::out(void){
  return this->mPrintStream;
}

/**
 * @brief 
 * 
 * @return mcuf::InputStreamBuffer& 
 */
InputStreamBuffer& ConsoleSerialPort::in(void){
  return this->mSerialPort;
}
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
