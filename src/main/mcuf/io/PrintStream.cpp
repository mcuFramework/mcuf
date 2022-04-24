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
#include "mcuf/io/PrintStream.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::lang::Memory;
using mcuf::io::PrintStream;
using mcuf::io::OutputStream;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Print Stream:: Print Stream object
 * 
 * @param outputStream 
 * @param memory 
 */
PrintStream::PrintStream(OutputStream& outputStream, const Memory& memory) : 
  Memory(memory),
  mOutputStream(outputStream),
  mByteBuffer(memory){
  
  return;
}

PrintStream::PrintStream(OutputStream& outputStream, uint32_t length) : 
  PrintStream(outputStream, Memory(length)){

  return;
}

/**
 * @brief Destroy the Print Stream object
 * 
 */
PrintStream::~PrintStream(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

/**
 * @brief 
 * 
 * @param b 
 * @param newLine 
 * @return true 
 * @return false 
 */
bool PrintStream::print(bool b, bool newLine){
  if(this->mOutputStream.writeBusy())
    return false;

  this->mByteBuffer.flush();

  if(b)
    this->mByteBuffer.put("True");

  else
    this->mByteBuffer.put("False");

  if(newLine)
    this->mByteBuffer.put("\n");

  this->mByteBuffer.flip();
  return this->mOutputStream.write(this->mByteBuffer, nullptr, nullptr);
}

/**
 * @brief 
 * 
 * @param c 
 * @param newLine 
 * @return true 
 * @return false 
 */
bool PrintStream::print(char c, bool newLine){
  if(this->mOutputStream.writeBusy())
    return false;

  this->mByteBuffer.flush();
  this->mByteBuffer.putByte(c);

  if(newLine)
    this->mByteBuffer.put("\n");

  this->mByteBuffer.flip();
  return this->mOutputStream.write(this->mByteBuffer, nullptr, nullptr);
}

/**
 * @brief 
 * 
 * @param d 
 * @param newLine 
 * @return true 
 * @return false 
 */
bool PrintStream::print(double d, bool newLine){
  if(this->mOutputStream.writeBusy())
    return false;

  this->mByteBuffer.flush();
  this->mByteBuffer.putFormat("%f", d);

  if(newLine)
    this->mByteBuffer.put("\n");

  this->mByteBuffer.flip();
  return this->mOutputStream.write(this->mByteBuffer, nullptr, nullptr);
}

/**
 * @brief 
 * 
 * @param f 
 * @param newLine 
 * @return true 
 * @return false 
 */
bool PrintStream::print(float f, bool newLine){
  if(this->mOutputStream.writeBusy())
    return false;

  this->mByteBuffer.flush();
  this->mByteBuffer.putFormat("%f", static_cast<double>(f));

  if(newLine)
    this->mByteBuffer.put("\n");

  this->mByteBuffer.flip();
  return this->mOutputStream.write(this->mByteBuffer, nullptr, nullptr);
}

/**
 * @brief 
 * 
 * @param i 
 * @param newLine 
 * @return true 
 * @return false 
 */
bool PrintStream::print(int i, bool newLine, bool unsign){
  if(this->mOutputStream.writeBusy())
    return false;

  this->mByteBuffer.flush();
  if(unsign)
    this->mByteBuffer.putFormat("%d", static_cast<unsigned int>(i));
  
  else
    this->mByteBuffer.putFormat("%d", i);

  if(newLine)
    this->mByteBuffer.put("\n");

  this->mByteBuffer.flip();
  return this->mOutputStream.write(this->mByteBuffer, nullptr, nullptr);
}

/**
 * @brief 
 * 
 * @param string 
 * @param newLine 
 * @return true 
 * @return false 
 */
bool PrintStream::print(const mcuf::lang::String& string, bool newLine){
  if(this->mOutputStream.writeBusy())
    return false;

  this->mByteBuffer.flush();
  this->mByteBuffer.putFormat(string);

  if(newLine)
    this->mByteBuffer.put("\n");

  this->mByteBuffer.flip();
  return this->mOutputStream.write(this->mByteBuffer, nullptr, nullptr);
}

/**
 * @brief 
 * 
 * @param string 
 * @param newLine 
 * @return true 
 * @return false 
 */
bool PrintStream::print(const char* string, bool newLine){
  if(this->mOutputStream.writeBusy())
    return false;

  this->mByteBuffer.flush();
  this->mByteBuffer.put(string);

  if(newLine)
    this->mByteBuffer.put("\n");

  this->mByteBuffer.flip();
  return this->mOutputStream.write(this->mByteBuffer, nullptr, nullptr);
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @param newLine 
 * @return true 
 * @return false 
 */
bool PrintStream::print(mcuf::io::ByteBuffer& byteBuffer, bool newLine){
  if(this->mOutputStream.writeBusy())
    return false;

  this->mByteBuffer.flush();
  this->mByteBuffer.put(byteBuffer);

  if(newLine)
    this->mByteBuffer.put("\n");

  this->mByteBuffer.flip();
  return this->mOutputStream.write(this->mByteBuffer, nullptr, nullptr);
}

/**
 * @brief 
 * 
 * @param OutputBuffer 
 * @param newLine 
 * @return true 
 * @return false 
 */
bool PrintStream::print(mcuf::io::OutputBuffer& outputBuffer, bool newLine){
  if(this->mOutputStream.writeBusy())
    return false;

  this->mByteBuffer.flush();
  if(newLine)
    this->mByteBuffer.limit(this->mByteBuffer.limit()-1);
  
  this->mByteBuffer.put(outputBuffer);
  this->mByteBuffer.limit(this->mByteBuffer.capacity());
  if(newLine)
    this->mByteBuffer.put("\n");

  this->mByteBuffer.flip();
  return this->mOutputStream.write(this->mByteBuffer, nullptr, nullptr);
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool PrintStream::println(void){
  if(this->mOutputStream.writeBusy())
    return false;

  this->mByteBuffer.flush();
  this->mByteBuffer.put("\n");
  this->mByteBuffer.flip();
  return this->mOutputStream.write(this->mByteBuffer, nullptr, nullptr);
}

/**
 * @brief 
 * 
 * @param format 
 * @param ... 
 * @return true 
 * @return false 
 */
bool PrintStream::format(const char* format, ...){
  if(this->mOutputStream.writeBusy())
    return false;

  this->mByteBuffer.flush();
  va_list args;
  va_start(args, format);
  this->mByteBuffer.putFormat(format, args);
  va_end(args);
  this->mByteBuffer.flip();
  return this->mOutputStream.write(this->mByteBuffer, nullptr, nullptr);
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
