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
#include "mcuf/io/PrintStream.hpp"

/* ****************************************************************************************
 * Using
 */  
using mcuf::io::PrintStream;
using mcuf::io::channel::ByteBuffer;
using mcuf::io::channel::ByteBuffer;
using mcuf::io::channel::ByteBuffer;
using mcuf::lang::Memory;
using mcuf::lang::String;

/* ****************************************************************************************
 * Variable
 */
const char PrintStream::textNextLine[] = "\n";
const char PrintStream::textFalse[] = "False\n";
const char PrintStream::textTrue[] = "True\n";

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/**
 * 
 */
PrintStream::PrintStream(mcuf::io::OutputStream* outputStream){
  this->outputStream = outputStream;
}

/* ****************************************************************************************
 * Public Method <Static>
 */
 
/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method <Override> - CompletionHandlerConst
 */

/**
 * 
 */
void PrintStream::CompletionHandlerConst::completed(int result, void* attachment){
  ByteBuffer* b = (ByteBuffer*)attachment;
  delete b;
  return;
}

/**
 * 
 */
void PrintStream::CompletionHandlerConst::failed(mcuf::lang::Object& exc, void* attachment){
  ByteBuffer* b = (ByteBuffer*)attachment;
  delete b;
  return;
}

/* ****************************************************************************************
 * Public Method <Override> - CompletionHandlerHeap
 */
/**
 * 
 */
void PrintStream::CompletionHandlerHeap::completed(int result, void* attachment){
  ByteBuffer* b = (ByteBuffer*)attachment;
  delete b;
  return;
}

/**
 * 
 */
void PrintStream::CompletionHandlerHeap::failed(mcuf::lang::Object& exc, void* attachment){
  ByteBuffer* b = (ByteBuffer*)attachment;
  delete b;
  return;
}

/* ****************************************************************************************
 * Public Method
 */

/**
 * 
 */
PrintStream& PrintStream::format(const char* format, ...){
  if(this->outputStream == nullptr)
    return *this;

  char* string;
  ByteBuffer* byteBuffer;

  va_list args;
  va_start (args, format);
  byteBuffer = new ByteBuffer(String::format(format, args));
  va_end (args);  

  this->outputStream->write(byteBuffer, byteBuffer, &this->completionHandlerHeap);

  return *this;
}

/**
 * 
 */
PrintStream& PrintStream::print(bool b){
  if(this->outputStream == nullptr)
    return *this;

  ByteBuffer* byteBuffer;

  if(b)
    byteBuffer = new ByteBuffer(Memory(PrintStream::textTrue, sizeof(PrintStream::textTrue)-2));
  else
    byteBuffer = new ByteBuffer(Memory(PrintStream::textFalse, sizeof(PrintStream::textFalse)-2));

  this->outputStream->write(byteBuffer, byteBuffer, &this->completionHandlerConst);
  
  return *this;
}

/**
 * 
 */
PrintStream& PrintStream::print(int i){
  if(this->outputStream == nullptr)
    return *this;

  ByteBuffer* byteBuffer = new ByteBuffer(String::format("%d", i));

  this->outputStream->write(byteBuffer, byteBuffer, &this->completionHandlerHeap);
  return *this;
}

/**
 * 
 */
PrintStream& PrintStream::print(const char* string){
  if(this->outputStream == nullptr)
    return *this;

  ByteBuffer* byteBuffer;
  
  byteBuffer = new ByteBuffer(Memory(string, strlen(string)));
  this->outputStream->write(byteBuffer, byteBuffer, &this->completionHandlerConst);

  return *this;
}

/**
 * 
 */
PrintStream& PrintStream::println(bool b){
  if(this->outputStream == nullptr)
    return *this;

  ByteBuffer* byteBuffer;

  if(b)
    byteBuffer = new ByteBuffer(Memory(PrintStream::textTrue, sizeof(PrintStream::textTrue)-1));
  else
    byteBuffer = new ByteBuffer(Memory(PrintStream::textFalse, sizeof(PrintStream::textFalse)-1));

  this->outputStream->write(byteBuffer, byteBuffer, &this->completionHandlerConst);

  return *this;
}

/**
 * 
 */
PrintStream& PrintStream::println(int i){
  if(this->outputStream == nullptr)
    return *this;

  ByteBuffer* byteBuffer = new ByteBuffer(String::format("%d\n", i));
  
  this->outputStream->write(byteBuffer, byteBuffer, &this->completionHandlerHeap);
  return *this;
}

/**
 * 
 */
PrintStream& PrintStream::println(const char* string){
  if(this->outputStream == nullptr)
    return *this;

  ByteBuffer* byteBuffer;
  
  byteBuffer = new ByteBuffer(Memory(string, strlen(string)));
  this->outputStream->write(byteBuffer, byteBuffer, &this->completionHandlerConst);

  byteBuffer = new ByteBuffer(Memory(PrintStream::textNextLine, strlen(PrintStream::textNextLine)));
  this->outputStream->write(byteBuffer, byteBuffer, &this->completionHandlerConst);

  return *this;
}

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
