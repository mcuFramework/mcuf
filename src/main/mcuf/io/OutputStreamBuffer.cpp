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
#include "mcuf/io/OutputStreamBuffer.h"
#include "mcuf/lang/ErrorCode.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::io::OutputStreamBuffer;
using mcuf::io::OutputStream;
using mcuf::io::ByteBuffer;
using mcuf::io::RingBuffer;
using mcuf::lang::Memory;
using mcuf::lang::ErrorCode;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Output Stream Buffer object
 * 
 * @param memory 
 */
OutputStreamBuffer::OutputStreamBuffer(OutputStream& outputStream ,Memory& memory) construct 
  RingBuffer(memory),
  mOutputStream(outputStream){

}

/**
 * @brief Destroy the Output Stream Buffer object
 * 
 */
OutputStreamBuffer::~OutputStreamBuffer(void){
  this->mOutputStream.abortWrite();
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - mcuf::io::OutputStream
 */

/**
 * @brief 
 * 
 * @return true successful.
 * @return false fail.
 */
bool OutputStreamBuffer::abortWrite(void){
  return false;
}

/**
 * @brief 
 * 
 * @return true is busy.
 * @return false isn't busy.
 */
bool OutputStreamBuffer::writeBusy(void){
  return false;
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @param attachment 
 * @param handler 
 * @return true successful.
 * @return false fail.
 */
bool OutputStreamBuffer::write(ByteBuffer* byteBuffer, 
                               void* attachment, 
                               CompletionHandler<int, void*>* handler){
  
  if(byteBuffer == nullptr){
    if(handler != nullptr){
      ErrorCode errorCode = ErrorCode::ILLEGAL_ARGUMENT;
      handler->failed(&errorCode, attachment);
    }
    return false;
  }
  
  void* insert = byteBuffer->pointer(byteBuffer->position());
  uint32_t len = byteBuffer->remaining();
  
  if(len != 0){
    len = this->insertMult(insert, len);
    byteBuffer->position(byteBuffer->position() + len);
  }
  
  if(!this->mOutputStream.writeBusy()){
    this->writePacket();
  }
  
  if(handler != nullptr){
    handler->completed(len, attachment);
  }
  
  return true;
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::io::CompletionHandler<int ,void*>
 */

/**
 * @brief 
 * 
 * @param result 
 * @param attachment 
 */
void OutputStreamBuffer::completed(int result, void* attachment){
  
  if(!this->isEmpty()){
    this->writePacket();
  }
}

/**
 * @brief 
 * 
 * @param exc 
 * @param attachment 
 */
void OutputStreamBuffer::failed(void* exc, void* attachment){
  this->abortWrite();
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
 *
 */
void OutputStreamBuffer::writePacket(void){
}

/* ****************************************************************************************
 * End of file
 */
