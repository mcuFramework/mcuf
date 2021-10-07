/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_ECF923D8_FF28_485C_9D21_B7D4847F4ACD
#define MCUF_ECF923D8_FF28_485C_9D21_B7D4847F4ACD

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "ByteBuffer.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    namespace channel{
      class ConstByteBuffer;
    }
  }
}

/* ****************************************************************************************
 * Class ConstByteBuffer
 */  
class mcuf::io::channel::ConstByteBuffer extends mcuf::io::channel::ByteBuffer{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

  /**
   * Construct.
   */
  public: ConstByteBuffer(mcuf::lang::Memory& memory);

  /**
   * 
   */
  public: ConstByteBuffer(const void* pointer, size_t length);

  /**
   * 
   */
  public: ConstByteBuffer(const char* string);

  /**
   * Destruct.
   */
  public: virtual ~ConstByteBuffer(void) = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */

  /**
   * 
   */
  public: virtual bool readOnly(void) override;

  /**
   * 
   */
  public: virtual mcuf::io::channel::ByteBuffer& putByte(char value) override;
  
  /**
   * 
   */
  public: virtual mcuf::io::channel::ByteBuffer& putShort(short value) override;
  
  /**
   * 
   */
  public: virtual mcuf::io::channel::ByteBuffer& putInt(int value) override;

  /* **************************************************************************************
   * Public Method
   */

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */
   
  /* **************************************************************************************
   * Private Method
   */  

};



/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_ECF923D8_FF28_485C_9D21_B7D4847F4ACD */
