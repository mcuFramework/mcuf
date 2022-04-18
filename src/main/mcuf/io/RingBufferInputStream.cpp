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
using mcuf::io::ByteBuffer;
using mcuf::io::CompletionHandler;
using mcuf::lang::Pointer;

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
  this->mByteBuffer = nullptr;
  this->mSkip = -1;
  return;
}
  
/**
 * @brief Construct a new RingBufferInputStream object
 * 
 * @param memory 
 */
RingBufferInputStream::RingBufferInputStream(const mcuf::lang::Memory& memory) :
RingBuffer(memory){
  this->mByteBuffer = nullptr;
  this->mSkip = -1;
  return;
}
/**
 * @brief Construct a new RingBufferInputStream object
 * 
 * @param length 
 */
RingBufferInputStream::RingBufferInputStream(uint32_t length) :
RingBuffer(length){
  this->mByteBuffer = nullptr;
  this->mSkip = -1;
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
bool RingBufferInputStream::insert(const void* data){
  if(this->mSkip > 0){
    --this->mSkip;
    if(this->mSkip == 0)
      this->executeCompletionHandler();
    
    return true;
  }
    
  
  if(this->mByteBuffer == nullptr)
    return RingBuffer::insert(data);
  
  this->mByteBuffer->putByte(*static_cast<const char*>(data));
  if(!this->mByteBuffer->hasRemaining())
    this->executeCompletionHandler();
      
  return true;
}

/**
 * @brief 
 * 
 * @param data 
 * @param num 
 * @return int 
 */
int RingBufferInputStream::insertMult(const void *data, int num){
  if(num <= 0)
    return 0;
  
  if(this->mSkip > 0){
    int cache = this->mSkip;
    if(num >= this->mSkip)
      this->mSkip -= num;
    
    num -= cache;
    data = Pointer::pointShift(data, cache);
    
    if(this->mSkip == 0)
      this->executeCompletionHandler();
  }
    
  if(this->mByteBuffer == nullptr)
    return RingBuffer::insertMult(data, num);
  
  int remaining = this->mByteBuffer->remaining();
  if(remaining >= num)
    this->mByteBuffer->put(data, num);
  else{
    this->mByteBuffer->put(data, remaining);
    RingBuffer::insertMult(Pointer::pointShift(data, remaining), (num - remaining));
  }
  
  return num;
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
  return ((this->mByteBuffer != nullptr) || (this->mSkip >= 0));
}

/**
 * @brief nonblocking
 * 
 * @param byteBuffer 
 * @param attachment 
 * @param handler 
 * @return true successful.
 * @return false fail.
 */
bool RingBufferInputStream::read(ByteBuffer& byteBuffer, void* attachment, CompletionHandler<int, void*>* handler){
  if(this->readBusy())
    return false;
  
  if(this->getCount() >= byteBuffer.remaining()){
    byteBuffer += this->popMult(byteBuffer.pointer(byteBuffer.position()), byteBuffer.remaining());
    if(handler)
      handler->completed(byteBuffer.remaining(), attachment);
  }
  
  this->mByteBuffer = &byteBuffer;
  this->mAttachment = attachment;
  this->mHandler = handler;
  byteBuffer += this->popMult(byteBuffer.pointer(byteBuffer.position()), byteBuffer.remaining());
  
  return true;
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @param future 
 * @return true 
 * @return false 
 */
bool RingBufferInputStream::read(ByteBuffer& byteBuffer, Future& future){
  if(!future.classAvariable())
    return false;
  
  if(!future.isIdle())
    return false;
  
  return this->read(byteBuffer, nullptr, &future);
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

  int result = this->popMult(nullptr, value);
  if(result == value){
    if(handler)
      handler->completed(0, attachment);
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
  
  ByteBuffer* byteBuffer = nullptr;
  int result;
  CompletionHandler<int, void*>* handler = this->mHandler;
  void* attachment = this->mAttachment;
  
  if(this->mByteBuffer != nullptr){
    byteBuffer = this->mByteBuffer;
    result = byteBuffer->remaining();
    this->mByteBuffer = nullptr;
    
  }else{
    result = this->mSkip;
    this->mSkip = -1;
    
  }
  
  if(handler)
    handler->completed(result, attachment);

  return;
}

/* ****************************************************************************************
 * End of file
 */
