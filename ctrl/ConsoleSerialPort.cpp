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
#include "./package-info.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using ctrl::ConsoleSerialPort;
using hal::SerialPort;
using cli::PrintStream;
using mcuf::InputStream;

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
 * Public Method <Override> - cli::Console
 */
/**
 * @brief 
 * 
 * @return cli::PrintStream& 
 */
PrintStream& ConsoleSerialPort::out(void){
  return this->mPrintStream;
}

/**
 * @brief 
 * 
 * @return mcuf::InputStreamBuffer& 
 */
InputStream& ConsoleSerialPort::in(void){
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
