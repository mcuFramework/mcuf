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
#include "../../lang/Array.hpp"
#include "../../lang/Object.hpp"
#include "../../lang/Memory.hpp"




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
class mcuf::io::channel::ByteBuffer : 
      public mcuf::lang::Object{

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
  private: uint16_t mCapacity;
  private: uint8_t* mPointer;


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
  public: ByteBuffer(void* pointer, size_t length);
  
  /**
   * 
   */
  public: virtual ~ByteBuffer() = default;

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
  public: bool readOnly(void);

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
  public: ByteBuffer& putByte(char value);

  /**
   * 
   */
  public: char getByte(void);

  /**
   * 
   */
  public: ByteBuffer& putShort(short value);

  /**
   * 
   */
  public: short getShort(void);

  /**
   * 
   */
  public: ByteBuffer& putInt(int value);

  /**
   * 
   */
  public: int getInt(void);

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
