/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_C76BAF3F_EE1F_46A3_A050_9CD1057055E5
#define MCUF_C76BAF3F_EE1F_46A3_A050_9CD1057055E5

/* ****************************************************************************************
 * Include
 */
 
//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"
#include "mcuf/lang/ArrayPrototype.hpp"
#include "mcuf/lang/Object.hpp"
#include "mcuf/lang/Memory.hpp"
#include "mcuf/lang/String.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    namespace channel{
      class ByteBuffer;
    }
  }
}

/* ****************************************************************************************
 * Class Map
 */
class mcuf::io::channel::ByteBuffer extends mcuf::lang::Memory{

  /* **************************************************************************************
   *  Variable <Public>
   */

  /* **************************************************************************************
   *  Variable <Protected>
   */

  /* **************************************************************************************
   *  Variable <Private>
   */
  private: uint16_t mMark;
  private: uint16_t mLimit;
  private: uint16_t mPosition;

  /* **************************************************************************************
   *  Abstract method <Public>
   */

  /* **************************************************************************************
   *  Abstract method <Protected>
   */

  /* **************************************************************************************
   *  Construct Method
   */

  /**
   * 
   */
  public: ByteBuffer(mcuf::lang::Memory& memory);
  
  /**
   * 
   */
  public: ByteBuffer(mcuf::lang::Memory&& memory);  
  
  /**
   *
   */
  public: ByteBuffer(uint32_t size);
  
  /**
   * 
   */
  public: virtual ~ByteBuffer(void) = default;

  /* **************************************************************************************
   *  Public Method <Static>
   */

  /* **************************************************************************************
   *  Public Method <Override>
   */

  /* **************************************************************************************
   *  Public Method
   */

  /**
   * 
   */
  public: uint8_t* lowerArray(void);

  /**
   * 
   */
  public: uint8_t* lowerArray(uint32_t offset);  

  /**
   * 
   */
  public: uint32_t limit(void);

  /**
   * 
   */
  public: ByteBuffer& limit(uint32_t newLimit);

  /**
   * 
   */
  public: uint32_t capacity(void);

  /**
   * 
   */
  public: uint32_t position(void);
  /**
   * 
   */
  public: ByteBuffer& position(uint32_t newPosition);

  /**
   * 
   */
  public: ByteBuffer& reset(void);

  /**
   * 
   */
  public: ByteBuffer& flip(void);

  /**
   * 
   */
  public: uint32_t remaining(void);

  /**
   * 
   */
  public: virtual bool readOnly(void);

  /**
   * 
   */
  public: bool hasRemaining(void);

  /**
   * 
   */
  public: ByteBuffer& rewind(void);
  
  /**
   *
   */
  public: virtual ByteBuffer& put(const char* string);
  
  /**
   *
   */
  public: virtual ByteBuffer& put(const void* ptr, uint32_t size);
  
  /**
   *
   */
  public: virtual ByteBuffer& put(mcuf::lang::String& string);  
  
  /**
   *
   */
  public: virtual ByteBuffer& putArray(mcuf::lang::ArrayPrototype& arrayPrototype);

  /**
   * 
   */
  public: virtual ByteBuffer& putByte(const char value);

  /**
   * 
   */
  public: virtual ByteBuffer& putShort(const short value);

  /**
   * 
   */
  public: virtual ByteBuffer& putShortLsb(const short value);

  /**
   * 
   */
  public: virtual ByteBuffer& putInt(const int value);
  
  /**
   * 
   */
  public: virtual ByteBuffer& putIntLsb(const int value);  

  /**
   * 
   */
  public: char getByte(void);

  /**
   * 
   */
  public: short getShort(void);
  
  /**
   * 
   */
  public: short getShortLsb(void);

  /**
   * 
   */
  public: int getInt(void);
  
  /**
   * 
   */
  public: int getIntLsb(void);  

  /* **************************************************************************************
   *  Protected Method <Static>
   */

  /* **************************************************************************************
   *  Protected Method <Override>
   */

  /* **************************************************************************************
   *  Protected Method
   */

  /* **************************************************************************************
   *  Private Method <Static>
   */

  /* **************************************************************************************
   *  Private Method <Override>
   */
   
  /* **************************************************************************************
   *  Private Method
   */
    
};



/* *****************************************************************************************
 *    End of file
 */ 


#endif/* MCUF_C76BAF3F_EE1F_46A3_A050_9CD1057055E5 */
