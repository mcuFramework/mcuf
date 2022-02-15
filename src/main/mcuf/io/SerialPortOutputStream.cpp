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
SerialPortOutputStream::SerialPortOutputStream(mcuf::hal::serial::port::SerialPort* serialPort){
  this->mSerialPort = serialPort;
}

/**
 *
 */
SerialPortOutputStream::~SerialPortOutputStream(void){
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
void SerialPortOutputStream::onSerialPortEvent(SerialPortStatus status, ByteBuffer* byteBuffer){
  CompletionHandler<int, void*>* handler;
  void* attachment;
  
  switch(status){
    case SerialPortStatus::WRITE_SUCCESSFUL:
    case SerialPortStatus::WRITE_ABROT:
    case SerialPortStatus::WRITE_FAIL:
      handler = this->mWriteHandler;
      attachment = this->mWriteAttachment;
      break;
    
    default:
      System::error(this, ErrorCode::ILLEGAL_ARGUMENT);
      break;
  }
  
  switch(status){
    case SerialPortStatus::WRITE_SUCCESSFUL:
    case SerialPortStatus::WRITE_ABROT:
      if(handler)
        handler->completed(byteBuffer->remaining(), attachment);
      break;
      
    case SerialPortStatus::WRITE_FAIL:
      if(handler)
        handler->failed(&status, attachment);
      break;
      
    default:
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
  return this->mSerialPort->abortWrite();
}

/**
 *
 */
bool SerialPortOutputStream::writeBusy(void){
  return this->mSerialPort->writeBusy();
}  

/**
 *
 */
bool SerialPortOutputStream::write(ByteBuffer* byteBuffer, void* attachment, CompletionHandler<int, void*>* handler){
  if(this->mSerialPort->writeBusy())
    return false;
  
  this->mWriteHandler = handler;
  this->mWriteAttachment = attachment;
  
  if(handler == nullptr)
    return this->mSerialPort->write(byteBuffer, nullptr);

  else
    return this->mSerialPort->write(byteBuffer, this);
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
