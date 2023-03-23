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
#include "./SerialBusStream.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::SerialBusStream;
using mcuf::hal::SerialBusStatus;
using mcuf::InputBuffer;
using mcuf::OutputBuffer;
using mcuf::CompletionHandler;
using mcuf::Future;

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
SerialBusStream::SerialBusStream(mcuf::hal::SerialBus& serialBus, uint16_t address) :
mSerialBus(serialBus),
mStreamSkipper(){
  this->mAddress = address;
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
 * Public Method <Override> - mcuf::InputStream
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
  
  future.setWait();
  bool result = this->read(inputBuffer, nullptr, &future);
  if(result == false)
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
  
  future.setWait();
  bool result = this->skip(value, nullptr, &future);
  if(result == false)
    future.clear();
  
  return result;
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::OutputStream
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
  
  future.setWait();
  bool result = this->write(outputBuffer, nullptr, &future);
  if(result == false)
    future.clear();
  
  return result;
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::DuplexStream
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

  future.setWait();
  bool result = this->transfer(inputBuffer, outputBuffer, nullptr, &future);
  if(result == false)
    future.clear();
  
  return result;
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::hal::SerialBusEvent
 */
/**
 * @brief 
 * 
 * @param status handle status
 * @param result 0 = successful, other = remaining byte count.
 * @param attachment user data
 */
void SerialBusStream::onSerialBusEvent(SerialBusStatus status, int result, void* attachment){
  if(this->mHandler != nullptr){
    switch(status){
      case SerialBusStatus::READ_FAIL:
      case SerialBusStatus::TRANSFER_FAIL_READ:
      case SerialBusStatus::TRANSFER_FAIL_WRITE:
      case SerialBusStatus::WRITE_FAIL:
        this->mHandler->failed(nullptr, attachment);
        break;
      
      case SerialBusStatus::READ_SUCCESSFUL:
      case SerialBusStatus::TRANSFER_SUCCESSFUL:
      case SerialBusStatus::WRITE_SUCCESSFUL:
        this->mHandler->completed(result, attachment);
        break;
    }

  }
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
