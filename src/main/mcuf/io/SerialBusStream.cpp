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
#include "mcuf/io/SerialBusStream.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::io::SerialBusStream;
using hal::serial::SerialBusStatus;
using mcuf::io::InputBuffer;
using mcuf::io::OutputBuffer;
using mcuf::io::CompletionHandler;
using mcuf::io::Future;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Serial Bus Stream object
 * 
 * @param serialBus 
 */
SerialBusStream::SerialBusStream(hal::serial::SerialBus& serialBus, uint16_t address) :
mSerialBus(serialBus),
mStreamSkipper(){
  this->mBusy = false;
  return;
}

/**
 * @brief Destroy the Serial Bus Stream object
 * 
 */
SerialBusStream::~SerialBusStream(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - mcuf::io::InputStream
 */
/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool SerialBusStream::abortRead(void){
  return this->mSerialBus.abort();
}

/**
 * @brief 
 * 
 * @return true is busy.
 * @return false isn't busy.
 */
bool SerialBusStream::readBusy(void){
  return this->isBusy();
}
/**
 * @brief 
 * 
 * @param outputBuffer 
 * @return int 
 */
bool SerialBusStream::read(InputBuffer& inputBuffer, int timeout){
  Future future = Future();
  bool result = this->read(inputBuffer, future);
  if(result)
    future.waitDone(timeout);
  
  return result;
}

/**
 * @brief nonblocking
 * 
 * @param outputBuffer 
 * @param attachment 
 * @param handler 
 * @return true successful.
 * @return false fail.
 */
bool SerialBusStream::read(InputBuffer& inputBuffer, void* attachment, CompletionHandler<int, void*>* handler){
  if(this->isBusy())
    return false;
  
  this->mBusy = true;
  
  this->mAttachment = attachment;
  this->mHandler = handler;
  bool result = this->mSerialBus.read(this->mAddress, inputBuffer, attachment, this);
  
  if(result == false)
    this->mBusy = false;
  
  return result;
}

/**
 * @brief 
 * 
 * @param outputBuffer 
 * @param future 
 * @return true 
 * @return false 
 */
bool SerialBusStream::read(InputBuffer& inputBuffer, Future& future){
  if(!future.isIdle())
    return false;
  
  return this->read(inputBuffer, nullptr, &future);
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
bool SerialBusStream::skip(int value, void* attachment, CompletionHandler<int, void*>* handler){
  if(this->isBusy())
    return false;
  
  if(value <= 0)
    return false;
  
  this->mBusy = true;
  
  this->mAttachment = attachment;
  this->mHandler = handler;
  this->mStreamSkipper.position(0);
  this->mStreamSkipper.capacity(value);
  bool result = this->mSerialBus.read(this->mAddress, this->mStreamSkipper, attachment, this);
  
  if(result == false)
    this->mBusy = false;
  
  return result;
}

/**
 * @brief 
 * 
 * @param value 
 * @param future 
 * @return true 
 * @return false 
 */
bool SerialBusStream::skip(int value, Future& future){
  if(!future.isIdle())
    return false;
  
  return this->skip(value, nullptr, &future);
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::io::OutputStream
 */
/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool SerialBusStream::abortWrite(void){
  return this->mSerialBus.abort();
}

/**
 * @brief 
 * 
 * @return true is busy.
 * @return false isn't busy.
 */
bool SerialBusStream::writeBusy(void){
  return this->isBusy();
}

/**
 * @brief 
 * 
 * @param outputBuffer
 * @param future 
 * @return true 
 * @return false 
 */
bool SerialBusStream::write(OutputBuffer& outputBuffer, int timeout){
  Future future = Future();
  if(this->write(outputBuffer, future) == false)
    return false;
  
  future.waitDone(timeout);
  if(future.isDone() == false)
    this->abortWrite();
  
  future.waitDone();
  return true;
}

/**
 * @brief 
 * 
 * @param outputBuffer
 * @param attachment 
 * @param handler 
 * @return true successful.
 * @return false fail.
 */
bool SerialBusStream::write(OutputBuffer& outputBuffer, void* attachment, CompletionHandler<int, void*>* handler){
  if(this->isBusy())
    return false;
  
  this->mBusy = true;
  
  this->mAttachment = attachment;
  this->mHandler = handler;
  bool result = this->mSerialBus.write(this->mAddress, outputBuffer, attachment, this);
  
  if(result == false)
    this->mBusy = false;
  
  return result;
}

/**
 * @brief 
 * 
 * @param outputBuffer
 * @param future 
 * @return true 
 * @return false 
 */
bool SerialBusStream::write(OutputBuffer& outputBuffer, Future& future){
  if(!future.isIdle())
    return false;
  
  return this->write(outputBuffer, nullptr, &future);
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::io::DuplexStream
 */
/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool SerialBusStream::abortTransfer(void){
  return this->mSerialBus.abort();
}

/**
 * @brief 
 * 
 * @return true is busy.
 * @return false isn't busy.
 */
bool SerialBusStream::transferBusy(void){
  return this->isBusy();
}

/**
 * @brief 
 * 
 * @param inputBuffer 
 * @param outputBuffer 
 * @param timeout 
 * @return true 
 * @return false 
 */
bool SerialBusStream::transfer(InputBuffer& inputBuffer, OutputBuffer& outputBuffer, int timeout){
  Future future = Future();
  bool result = this->transfer(inputBuffer, outputBuffer, future);
  if(result)
    future.waitDone(timeout);
  
  return result;
}

/**
 * @brief 
 * 
 * @param inputBuffer 
 * @param outputBuffer 
 * @param attachment 
 * @param handler 
 * @return true 
 * @return false 
 */
bool SerialBusStream::transfer(InputBuffer& inputBuffer, OutputBuffer& outputBuffer, void* attachment, 
                               CompletionHandler<int, void*>* handler){
  if(this->isBusy())
    return false;
  
  this->mBusy = true;
  
  this->mAttachment = attachment;
  this->mHandler = handler;
  bool result = this->mSerialBus.transfer(this->mAddress, outputBuffer, inputBuffer, attachment, this);
  
  if(result == false)
    this->mBusy = false;
  
  return result;
}

/**
 * @brief 
 * 
 * @param inputBuffer 
 * @param outputBuffer 
 * @param future 
 * @return true 
 * @return false 
 */
bool SerialBusStream::transfer(InputBuffer& inputBuffer, OutputBuffer& outputBuffer, Future& future){
  if(!future.isIdle())
    return false;  
  
  return this->transfer(inputBuffer, outputBuffer, nullptr, &future);
}

/* ****************************************************************************************
 * Public Method <Override> - hal::serial::SerialBusEvent
 */
/**
 * @brief 
 * 
 * @param status handle status
 * @param result 0 = successful, other = remaining byte count.
 * @param attachment user data
 */
void SerialBusStream::onSerialBusEvent(SerialBusStatus status, int result, void* attachment){
  if(this->mHandler != nullptr)
    this->mHandler->completed(result, attachment);
  
  this->mBusy = false;
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
