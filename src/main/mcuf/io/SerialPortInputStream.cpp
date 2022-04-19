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
SerialPortInputStream::SerialPortInputStream(SerialPort& serialPort) :
  mSerialPort(serialPort){

  return;
}

/**
 *
 */
SerialPortInputStream::~SerialPortInputStream(void){
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
void SerialPortInputStream::onSerialPortEvent(SerialPortStatus status, int result, void* attachment){
  CompletionHandler<int, void*>* userHandler = this->mReadHandler;
  
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
      
    case SerialPortStatus::WRITE_SUCCESSFUL:
    case SerialPortStatus::WRITE_FAIL:
    case SerialPortStatus::WRITE_ABROT:
      System::error(this, ErrorCode::ILLEGAL_ARGUMENT);
      break;
  }  
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::io::InputStream
 */

/**
 * @brief 
 * 
 * @return int 
 */
int SerialPortInputStream::avariable(void){
  return static_cast<int>(this->mSerialPort.avariable());
}

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
 * @brief pop buffer byte non blocking.
 * 
 * @param result 
 * @return true has data in buffer.
 * @return false no data in buffer.
 */
bool SerialPortInputStream::getByte(char& result){
  return this->mSerialPort.getByte(result);
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @return int 
 */
int SerialPortInputStream::get(mcuf::io::ByteBuffer& byteBuffer){
  return this->mSerialPort.get(byteBuffer);
}

/**
 * @brief 
 * 
 * @param buffer 
 * @param bufferSize 
 * @return int 
 */
int SerialPortInputStream::get(void* buffer, int bufferSize){
  return this->mSerialPort.get(buffer, bufferSize);
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @return bool 
 */
bool SerialPortInputStream::read(mcuf::io::ByteBuffer& byteBuffer){
  Future future = Future();
  bool result = SerialPortInputStream::read(byteBuffer, future);
  if(result)
    future.waitDone();
  
  return result;
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
