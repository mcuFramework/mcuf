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
using mcuf::io::Feture;
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
SerialPortInputStream::SerialPortInputStream(mcuf::hal::serial::port::SerialPort* serialPort){
  this->mSerialPort = serialPort;
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
void SerialPortInputStream::onSerialPortEvent(SerialPortStatus status, ByteBuffer* byteBuffer){
  CompletionHandler<int, void*>* handler;
  void* attachment;
  
  switch(status){
    case SerialPortStatus::READ_SUCCESSFUL:
    case SerialPortStatus::READ_ABROT:
    case SerialPortStatus::READ_FAIL:
      handler = this->mReadHandler;
      attachment = this->mReadAttachment;
      break;
    
    default:
      System::error(this, ErrorCode::ILLEGAL_ARGUMENT);
      break;
  }
  
  switch(status){
    case SerialPortStatus::READ_SUCCESSFUL:
    case SerialPortStatus::READ_ABROT:  
      if(handler)
        handler->completed(byteBuffer->remaining(), attachment);
      break;
      
    case SerialPortStatus::READ_FAIL:
      if(handler)
        handler->failed(&status, attachment);
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
  return this->mSerialPort->abortRead();
}

/**
 *
 */
bool SerialPortInputStream::readBusy(void){
  return this->mSerialPort->readBusy();
}

/**
 *
 */
bool SerialPortInputStream::read(ByteBuffer* byteBuffer, void* attachment, CompletionHandler<int, void*>* handler){
  if(this->mSerialPort->readBusy())
    return false;
  
  this->mReadHandler = handler;
  this->mReadAttachment = attachment;

  if(handler == nullptr)
    return this->mSerialPort->read(byteBuffer, nullptr);

  else
    return this->mSerialPort->read(byteBuffer, this);
}

/**
 *
 */
bool SerialPortInputStream::read(ByteBuffer* byteBuffer, Feture& feture){
  if(!feture.classAvariable())
    return false;
  
  if(!feture.isIdle())
    return false;
  
  feture.setWait();
  bool result = this->read(byteBuffer, nullptr, &feture);
  
  if(!result)
    feture.reset();
  
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
