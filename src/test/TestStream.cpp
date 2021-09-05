/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include <stdio.h>
#include "TestStream.hpp"

/* ****************************************************************************************
 * Using
 */  
using test::TestStream;
using mcuf::io::channel::ByteBuffer;
using mcuf::io::channel::CompletionHandler;

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */
 
/* ****************************************************************************************
 * Public Method <Override>
 */

/**
 *
 */
int TestStream::available(void){
  return 0;
}

/** 
 * 
 */
void TestStream::close(void){
  return;
}

/**
 *
 */
void TestStream::flush(void){
  return;
}

/**
 * 
 */
bool TestStream::isOpen(void){
  return true;
}

/**
 *  read async
 */
void TestStream::read(ByteBuffer* byteBuffer, 
                      void* attachment,
                      CompletionHandler<int, void*>* handler){

  if(handler){
    mcuf::lang::Throwable throwable = mcuf::lang::Throwable();
    handler->failed(throwable, attachment);
  }
}
  
/**
 *  
 */
int TestStream::skip(int skip){
  return 0;
}

/**
 *  write nonBlocking
 */
void TestStream::write(ByteBuffer* byteBuffer, 
                       void* attachment,
                       CompletionHandler<int, void*>* handler){

  uint8_t* base = byteBuffer->lowerArray(byteBuffer->position());

  for(int i=byteBuffer->position(); i<byteBuffer->limit(); i++)
    putchar(base[i]);

  byteBuffer->position(byteBuffer->limit());

  if(handler){
    handler->completed(0, attachment);
  }
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
