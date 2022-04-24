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
#include "mcuf/io/RingBufferInputStream.h"
#include "mcuf/lang/System.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::io::RingBufferInputStream;
using mcuf::io::Future;
using mcuf::io::InputBuffer;
using mcuf::io::CompletionHandler;
using mcuf::lang::Pointer;
using mcuf::lang::System;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new RingBufferInputStream object
 * 
 * @param buffer 
 * @param bufferSize 
 */
RingBufferInputStream::RingBufferInputStream(void* buffer, uint32_t bufferSize) :
RingBuffer(buffer, bufferSize){
  this->mInputBuffer = nullptr;
  this->mSkip = -1;
  this->mResult = 0;
  return;
}
  
/**
 * @brief Construct a new RingBufferInputStream object
 * 
 * @param memory 
 */
RingBufferInputStream::RingBufferInputStream(const mcuf::lang::Memory& memory) :
RingBuffer(memory){
  this->mInputBuffer = nullptr;
  this->mSkip = -1;
  this->mResult = 0;
  return;
}
/**
 * @brief Construct a new RingBufferInputStream object
 * 
 * @param length 
 */
RingBufferInputStream::RingBufferInputStream(uint32_t length) :
RingBuffer(length){
  this->mInputBuffer = nullptr;
  this->mSkip = -1;
  this->mResult = 0;
  return;
}
/**
 * @brief Destroy the RingBufferInputStream object
 * 
 */
RingBufferInputStream::~RingBufferInputStream(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - mcuf::io::RingBuffer 
 */

/**
 * @brief 
 * 
 * @param data 
 * @return true 
 * @return false 
 */
bool RingBufferInputStream::putByte(const char data){
  bool result = RingBuffer::putByte(data);
  
  if(this->mHandling == false){
    this->mHandling = true;
    System::execute(*this);
  }
  
  return result;  
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @return int 
 */
int RingBufferInputStream::put(OutputBuffer& outputBuffer){
  int result = RingBuffer::put(outputBuffer);
  
  if(this->mHandling == false){
    this->mHandling = true;
    System::execute(*this);
  }
  
  return result; 
}

/**
 * @brief 
 * 
 * @param data 
 * @param num 
 * @return int 
 */
int RingBufferInputStream::put(const void *data, int num){
  int result = RingBuffer::put(data, num);
  
  if(this->mHandling == false){
    this->mHandling = true;
    System::execute(*this);
  }
  
  return result; 
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::io::InputStream 
 */

/**
 * 
 */
bool RingBufferInputStream::abortRead(void){
  if(!this->readBusy())
    return false;
  
  this->executeCompletionHandler();
  return true;
}  

/**
 * @brief 
 * 
 * @return true is busy.
 * @return false isn't busy.
 */
bool RingBufferInputStream::readBusy(void){
  return ((this->mInputBuffer != nullptr) || (this->mSkip >= 0));
}

/**
 * @brief 
 * 
 * @param inputBuffer 
 * @return int 
 */
bool RingBufferInputStream::read(mcuf::io::InputBuffer& inputBuffer){
  Future future = Future();
  bool result = RingBufferInputStream::read(inputBuffer, future);
  if(result)
    future.waitDone();
  
  return result;
}    

/**
 * @brief nonblocking
 * 
 * @param inputBuffer 
 * @param attachment 
 * @param handler 
 * @return true successful.
 * @return false fail.
 */
bool RingBufferInputStream::read(InputBuffer& inputBuffer, void* attachment, CompletionHandler<int, void*>* handler){
  if(this->readBusy())
    return false;
  
  int result = inputBuffer.put(*this);
  
  if(inputBuffer.remaining() <= 0){
    if(handler)
      handler->completed(result, attachment);
    
    return result;
  }
 
  this->mInputBuffer = &inputBuffer;
  this->mResult = result;
  this->mAttachment = attachment;
  this->mHandler = handler;
  this->mResult = inputBuffer.put(*this);
  
  return true;
}

/**
 * @brief 
 * 
 * @param inputBuffer 
 * @param future 
 * @return true 
 * @return false 
 */
bool RingBufferInputStream::read(InputBuffer& inputBuffer, Future& future){
  if(!future.classAvariable())
    return false;
  
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
bool RingBufferInputStream::skip(int value, void* attachment, CompletionHandler<int, void*>* handler){
  if(this->readBusy())
    return false;

  int result = RingBuffer::skip(value);
  if(result >= value){
    if(handler)
      handler->completed(result, attachment);
  }
  
  this->mSkip = value - result;
  this->mHandler = handler;
  this->mAttachment = attachment;
  
  return true;
}

/**
 * @brief 
 * 
 * @param value 
 * @param future 
 * @return true 
 * @return false 
 */
bool RingBufferInputStream::skip(int value, Future& future){
  if(!future.classAvariable())
    return false;
  
  if(!future.isIdle())
    return false;
  
  return this->skip(value, nullptr, &future);
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::function::Runnable
 */

/**
 * @brief 
 * 
 */
void RingBufferInputStream::run(void){
  if(this->mHandling == false)
    return;
  
  //RingBuffer has data
  while(this->avariable()){
    
    if(this->mSkip > 0){
      int cache = RingBuffer::skip(this->mSkip);
      this->mSkip -= cache;
      this->mResult += cache;
      if(this->mSkip <= 0)
        this->executeCompletionHandler();
      
    }else if(this->mInputBuffer != nullptr){
      this->mResult += this->mInputBuffer->put(*this);
      if(this->mInputBuffer->remaining() <= 0)
        this->executeCompletionHandler();
      
    }else{
      break;
    }
  }
  
  this->mHandling = false;
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
  
/**
 * @brief 
 *
 */
void RingBufferInputStream::executeCompletionHandler(void){
  if(!this->readBusy())
    return;
  
  CompletionHandler<int, void*>* handler = this->mHandler;
  void* attachment = this->mAttachment;
  
  int result = this->mResult;
  this->mResult = 0;
  this->mInputBuffer = nullptr;
  this->mSkip = -1;
  
  if(handler)
    handler->completed(result, attachment);

  return;
}

/* ****************************************************************************************
 * End of file
 */
