/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "mcuf/io/SerialPortStream.h"

/* ****************************************************************************************
 * Macro
 */  

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::Memory;
using mcuf::io::ByteBuffer;
using mcuf::io::CompletionHandler;
using mcuf::io::SerialPortStream;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/**
 *
 */
SerialPortStream::SerialPortStream(mcuf::hal::SerialPort* serialPort){
  this->mSerialPort = serialPort;
}

/**
 *
 */
SerialPortStream::~SerialPortStream(void){
}

/* ****************************************************************************************
 * Public Method <Static>
 */
 
/* ****************************************************************************************
 * Public Method <Override> - mcuf::hal::SerialPortEvent
 */

/**
 *
 */
void SerialPortStream::onSerialPortEvent(SerialPortStatus status, ByteBuffer* byteBuffer){
  CompletionHandler<int, void*>* handler;
  void* attachment;
  
  switch(status){
    case HAL_SERIALPORT_WRITE_SUCCESSFUL:
    case HAL_SERIALPORT_WRITE_ABROT:
    case HAL_SERIALPORT_WRITE_FAIL:
      handler = this->mWriteHandler;
      attachment = this->mWriteAttachment;
      break;

    case HAL_SERIALPORT_READ_SUCCESSFUL:
    case HAL_SERIALPORT_READ_ABROT:
    case HAL_SERIALPORT_READ_FAIL:
      handler = this->mReadHandler;
      attachment = this->mReadAttachment;
      break;
  }
  
  switch(status){
    case HAL_SERIALPORT_WRITE_SUCCESSFUL:
    case HAL_SERIALPORT_WRITE_ABROT:
    case HAL_SERIALPORT_READ_SUCCESSFUL:
    case HAL_SERIALPORT_READ_ABROT:  
      if(handler)
        handler->completed(byteBuffer->remaining(), attachment);
      break;
      
    case HAL_SERIALPORT_WRITE_FAIL:
    case HAL_SERIALPORT_READ_FAIL:
      if(handler)
        handler->failed(&status, attachment);
      break;
  }  
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::io::OutputStream
 */

/**
 *
 */
bool SerialPortStream::abortWrite(void){
  return this->mSerialPort->abortWrite();
}

/**
 *
 */
bool SerialPortStream::writeBusy(void){
  return this->mSerialPort->writeBusy();
}  

/**
 *
 */
bool SerialPortStream::write(ByteBuffer* byteBuffer, void* attachment, CompletionHandler<int, void*>* handler){
  if(this->mSerialPort->writeBusy())
    return false;
  
  this->mWriteHandler = handler;
  this->mWriteAttachment = attachment;
  return this->mSerialPort->write(byteBuffer, this);
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::io::InputStream
 */

/**
 *
 */
bool SerialPortStream::abortRead(void){
  return this->mSerialPort->abortRead();
}

/**
 *
 */
bool SerialPortStream::readBusy(void){
  return this->mSerialPort->readBusy();
}

/**
 *
 */
bool SerialPortStream::read(ByteBuffer* byteBuffer, void* attachment, CompletionHandler<int, void*>* handler){
  if(this->mSerialPort->readBusy())
    return false;
  
  this->mReadHandler = handler;
  this->mReadAttachment = attachment;
  return this->mSerialPort->read(byteBuffer, this);
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
