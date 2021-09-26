/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  

#include <string.h>

//-----------------------------------------------------------------------------------------
#include "mcuf.h"

/* ****************************************************************************************
 * Using
 */  
using mcuf::io::channel::ByteBuffer;
using mcuf::io::channel::ConstByteBuffer;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
ConstByteBuffer::ConstByteBuffer(mcuf::lang::Memory& memory) :
                 ByteBuffer(memory){

  return;
}

/**
 * 
 */
ConstByteBuffer::ConstByteBuffer(const void* pointer, size_t length) :
                 ByteBuffer((void*)pointer, length){

  return;
}

/**
 * 
 */
ConstByteBuffer::ConstByteBuffer(const char* string) :
                 ByteBuffer((void*)string, strlen(string)){

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
 * 
 */
bool ConstByteBuffer::readOnly(void){
  return true;
}

/**
 * 
 */
ByteBuffer& ConstByteBuffer::putByte(char value){
  return *this;
}
  
/**
 * 
 */
ByteBuffer& ConstByteBuffer::putShort(short value){
  return *this;
}
  
/**
 * 
 */
ByteBuffer& ConstByteBuffer::putInt(int value){
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
