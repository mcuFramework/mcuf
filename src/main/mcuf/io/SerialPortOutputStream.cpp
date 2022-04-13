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
#include "mcuf/io/SerialPortOutputStream.h"
#include "mcuf/lang/System.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::lang::Memory;
using mcuf::lang::System;
using mcuf::lang::ErrorCode;
using mcuf::io::ByteBuffer;
using mcuf::io::CompletionHandler;
using mcuf::io::SerialPortOutputStream;
using hal::serial::SerialPort;
using hal::serial::SerialPortStatus;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 *
 */
SerialPortOutputStream::SerialPortOutputStream(SerialPort& serialPort) :
  mSerialPort(serialPort){

  return;
}

/**
 *
 */
SerialPortOutputStream::~SerialPortOutputStream(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - hal::serial::SerialPortEvent
 */

/**
 *
 */
void SerialPortOutputStream::onSerialPortEvent(SerialPortStatus status, int result, void* attachment){
  CompletionHandler<int, void*>* handler = this->mWriteHandler;
  
  switch(status){
    case SerialPortStatus::WRITE_SUCCESSFUL:
    case SerialPortStatus::WRITE_ABROT:
      if(handler)
        handler->completed(result, attachment);
      break;
      
    case SerialPortStatus::WRITE_FAIL:
      if(handler)
        handler->failed(&status, attachment);
      break;
      
    case SerialPortStatus::READ_SUCCESSFUL:
    case SerialPortStatus::READ_FAIL:
    case SerialPortStatus::READ_ABROT:
      System::error(this, ErrorCode::ILLEGAL_ARGUMENT);
      break;
  }  
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::io::OutputStream
 */

/**
 *
 */
bool SerialPortOutputStream::abortWrite(void){
  return this->mSerialPort.abortWrite();
}

/**
 *
 */
bool SerialPortOutputStream::writeBusy(void){
  return this->mSerialPort.writeBusy();
}  

/**
 *
 */
bool SerialPortOutputStream::write(ByteBuffer& byteBuffer, void* attachment, CompletionHandler<int, void*>* handler){
  if(this->mSerialPort.writeBusy())
    return false;
  
  
  if(handler == nullptr)
    return this->mSerialPort.write(byteBuffer, attachment, nullptr);

  else{
    this->mWriteHandler = handler;
    return this->mSerialPort.write(byteBuffer, attachment, this);
  }
}

/**
 *
 */
bool SerialPortOutputStream::write(ByteBuffer& byteBuffer, Future& future){
  if(!future.isIdle())
    return false;
  
  future.setWait();
  bool result = this->write(byteBuffer, nullptr, &future);
  
  if(!result)
    future.clear();
  
  return result; 
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
