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
#include "mcuf/io/SerialPortInputStream.h"
#include "mcuf/lang/System.h"
#include "mcuf/lang/Threads.h"

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
using mcuf::lang::Threads;
using mcuf::io::ByteBuffer;
using mcuf::io::CompletionHandler;
using mcuf::io::SerialPortInputStream;
using mcuf::io::Future;
using mcuf::hal::serial::port::SerialPort;
using mcuf::hal::serial::port::SerialPortStatus;


/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 *
 */
SerialPortInputStream::SerialPortInputStream(SerialPort& serialPort) construct
  mSerialPort(serialPort){

  return;
}

/**
 *
 */
SerialPortInputStream::~SerialPortInputStream(void){
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - mcuf::hal::serial::port::SerialPortEvent
 */

/**
 *
 */
void SerialPortInputStream::onSerialPortEvent(SerialPortStatus status, int result, void* attachment){
  CompletionHandler<int, void*>* userHandler = this->mReadHandler;
  ByteBuffer* byteBuffer = static_cast<ByteBuffer*>(attachment);
  
  switch(status){
    case SerialPortStatus::READ_SUCCESSFUL:
    case SerialPortStatus::READ_ABROT:  
      if(userHandler)
        userHandler->completed(result, attachment);
      break;
      
    case SerialPortStatus::READ_FAIL:
      if(userHandler)
        userHandler->failed(&status, attachment);
      break;
      
    default:
      System::error(this, ErrorCode::ILLEGAL_ARGUMENT);
      break;
  }  
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::io::InputStream
 */

/**
 *
 */
bool SerialPortInputStream::abortRead(void){
  return this->mSerialPort.abortRead();
}

/**
 *
 */
bool SerialPortInputStream::readBusy(void){
  return this->mSerialPort.readBusy();
}

/**
 *
 */
bool SerialPortInputStream::read(ByteBuffer& byteBuffer, void* attachment, CompletionHandler<int, void*>* handler){
  if(this->mSerialPort.readBusy())
    return false;
  
  this->mReadHandler = handler;
  
  if(handler == nullptr)
    return this->mSerialPort.read(byteBuffer, attachment, nullptr);
  
  else
    return this->mSerialPort.read(byteBuffer, attachment, this);
  
}

/**
 *
 */
bool SerialPortInputStream::read(ByteBuffer& byteBuffer, Future& future){
  if(!future.isIdle())
    return false;
  
  future.setWait();
  bool result = this->read(byteBuffer, nullptr, &future);
  
  if(!result)
    future.clear();
  
  return result; 
}

/**
 * @brief 
 * 
 * @param value 
 * @param attachment 
 * @param handler 
 * @return true 
 * @return false 
 */
bool SerialPortInputStream::skip(int value, void* attachment, CompletionHandler<int, void*>* handler){
  if(this->mSerialPort.readBusy())
    return false;
  
  if(handler == nullptr)
    return this->mSerialPort.skip(value, attachment, nullptr);
  
  else{
    this->mReadHandler = handler;
    return this->mSerialPort.skip(value, attachment, this);
  }
}
/**
 * @brief 
 * 
 * @param value 
 * @param future 
 * @return true 
 * @return false 
 */
bool SerialPortInputStream::skip(int value, mcuf::io::Future& future){
  if(!future.isIdle())
    return false;
  
  future.setWait();
  bool result = this->skip(value, nullptr, &future);
  
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
