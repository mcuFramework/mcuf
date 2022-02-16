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
 * @brief Construct a new Print Stream object
 * 
 */
PrintStream::PrintStream(OutputStream* outputStream, const Memory& memory) construct Memory(memory),
  mByteBuffer(memory){
  
  this->mOutputStream = outputStream;
}

/**
 * @brief Destroy the Print Stream object
 * 
 */
PrintStream::~PrintStream(void){
  
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
  if(this->mOutputStream->writeBusy())
    return false;

  this->mByteBuffer.reset();

  if(b)
    this->mByteBuffer.put("True");

  else
    this->mByteBuffer.put("False");

  if(newLine)
    this->mByteBuffer.put("\n");

  this->mByteBuffer.flip();
  return this->mOutputStream->write(&this->mByteBuffer, nullptr, nullptr);
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
  if(this->mOutputStream->writeBusy())
    return false;

  this->mByteBuffer.reset();
  this->mByteBuffer.putByte(c);

  if(newLine)
    this->mByteBuffer.put("\n");

  this->mByteBuffer.flip();
  return this->mOutputStream->write(&this->mByteBuffer, nullptr, nullptr);
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
  if(this->mOutputStream->writeBusy())
    return false;

  this->mByteBuffer.reset();
  this->mByteBuffer.putFormat("%f", d);

  if(newLine)
    this->mByteBuffer.put("\n");

  this->mByteBuffer.flip();
  return this->mOutputStream->write(&this->mByteBuffer, nullptr, nullptr);
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
  if(this->mOutputStream->writeBusy())
    return false;

  this->mByteBuffer.reset();
  this->mByteBuffer.putFormat("%f", f);

  if(newLine)
    this->mByteBuffer.put("\n");

  this->mByteBuffer.flip();
  return this->mOutputStream->write(&this->mByteBuffer, nullptr, nullptr);
}

/**
 * @brief 
 * 
 * @param i 
 * @param newLine 
 * @return true 
 * @return false 
 */
bool PrintStream::print(int i, bool newLine){
  if(this->mOutputStream->writeBusy())
    return false;

  this->mByteBuffer.reset();
  this->mByteBuffer.putFormat("%d", i);

  if(newLine)
    this->mByteBuffer.put("\n");

  this->mByteBuffer.flip();
  return this->mOutputStream->write(&this->mByteBuffer, nullptr, nullptr);
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
  if(this->mOutputStream->writeBusy())
    return false;

  this->mByteBuffer.reset();
  this->mByteBuffer.putFormat(string);

  if(newLine)
    this->mByteBuffer.put("\n");

  this->mByteBuffer.flip();
  return this->mOutputStream->write(&this->mByteBuffer, nullptr, nullptr);
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
  if(this->mOutputStream->writeBusy())
    return false;

  this->mByteBuffer.reset();
  this->mByteBuffer.put(string);

  if(newLine)
    this->mByteBuffer.put("\n");

  this->mByteBuffer.flip();
  return this->mOutputStream->write(&this->mByteBuffer, nullptr, nullptr);
}

/**
 * @brief 
 * 
 * @param b 
 * @return true 
 * @return false 
 */
bool PrintStream::print(bool b){
  return this->print(b, false);
}

/**
 * @brief 
 * 
 * @param c 
 * @return true 
 * @return false 
 */
bool PrintStream::print(char c){
  return this->print(c, false);
}

/**
 * @brief 
 * 
 * @param d 
 * @return true 
 * @return false 
 */
bool PrintStream::print(double d){
  return this->print(d, false);
}

/**
 * @brief 
 * 
 * @param f 
 * @return true 
 * @return false 
 */
bool PrintStream::print(float f){
  return this->print(f, false);
}

/**
 * @brief 
 * 
 * @param i 
 * @return true 
 * @return false 
 */
bool PrintStream::print(int i){
  return this->print(i, false);
}

/**
 * @brief 
 * 
 * @param string 
 * @return true 
 * @return false 
 */
bool PrintStream::print(const mcuf::lang::String& string){
  return this->print(string, false);
}

/**
 * @brief 
 * 
 * @param string 
 * @return true 
 * @return false 
 */
bool PrintStream::print(const char* string){
  return this->print(string, false);
}

/**
 * @brief 
 * 
 * @param b 
 * @return true 
 * @return false 
 */
bool PrintStream::println(bool b){
  return this->print(b, true);
}

/**
 * @brief 
 * 
 * @param c 
 * @return true 
 * @return false 
 */
bool PrintStream::println(char c){
  return this->print(c, true);
}

/**
 * @brief 
 * 
 * @param d 
 * @return true 
 * @return false 
 */
bool PrintStream::println(double d){
  return this->print(d, true);
}

/**
 * @brief 
 * 
 * @param f 
 * @return true 
 * @return false 
 */
bool PrintStream::println(float f){
  return this->print(f, true);
}

/**
 * @brief 
 * 
 * @param i 
 * @return true 
 * @return false 
 */
bool PrintStream::println(int i){
  return this->print(i, true);
}

/**
 * @brief 
 * 
 * @param string 
 * @return true 
 * @return false 
 */
bool PrintStream::println(mcuf::lang::String& string){
  return this->print(string, true);
}

/**
 * @brief 
 * 
 * @param string 
 * @return true 
 * @return false 
 */
bool PrintStream::println(const char* string){
  return this->print(string, true);
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
  if(this->mOutputStream->writeBusy())
    return false;

  this->mByteBuffer.reset();
  va_list args;
  va_start(args, format);
  this->mByteBuffer.putFormat(format, args);
  va_end(args);
  return this->mOutputStream->write(&this->mByteBuffer, nullptr, nullptr);
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
