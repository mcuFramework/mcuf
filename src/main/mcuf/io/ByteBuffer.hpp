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
    class ByteBuffer;
  }
}

/* ****************************************************************************************
 * Class Map
 */
class mcuf::io::ByteBuffer extends mcuf::lang::Memory{

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
   * @brief 
   * 
   */
  public: ByteBuffer(const mcuf::lang::Memory& memory);

  /**
   * @brief 
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
   *  Public Method <Inline>
   */

  /**
   * @brief 
   * 
   */
  public: inline uint32_t limit(void){
    return this->mLimit;
  }

  /**
   * @brief 
   * 
   */
  public: inline uint32_t capacity(void){
    return this->length();
  }
  
  /**
   * @brief 
   * 
   */
  public: inline uint32_t position(void){
    return this->mPosition;
  }  
  
  /**
   * @brief 
   * 
   */
  public: inline void reset(void){
    this->mPosition = 0;
    this->mLimit = this->length();
    return;
  }  
  
  /**
   * @brief 
   * 
   */
  public: inline uint32_t remaining(void){
    return this->mLimit - this->mPosition;
  }  
  
  /**
   * @brief 
   * 
   */
  public: inline bool hasRemaining(void){
    return (this->mLimit > this->mPosition);
  }  
  
  /**
   * @brief 
   * 
   */
  public: inline void rewind(void){
    this->mPosition = 0;
    this->mMark = 0;
    return;
  }  
  
  /* **************************************************************************************
   *  Public Method
   */

    /**
     * 
     */
  public: bool limit(uint32_t newLimit);

  /**
   * 
   */
  public: bool position(uint32_t newPosition);

  /**
   * 
   */
  public: void flip(void);
  
  /**
   *
   */
  public: bool put(const char* string);
  
  /**
   *
   */
  public: bool put(const void* ptr, uint32_t size);
  
  /**
   *
   */
  public: bool put(const mcuf::lang::String& string);  

  /**
   * 
   */
  public: bool putByte(const char value);
  
  /**
   *
   */
  public: int putFormat(const char* format, ...);

  /**
   * 
   */
  public: bool putShort(const short value);

  /**
   * 
   */
  public: bool putShortMsb(const short value);

  /**
   * 
   */
  public: bool putInt(const int value);
  
  /**
   * 
   */
  public: bool putIntMsb(const int value);  

  /**
   * 
   */
  public: bool getByte(char& result);

  /**
   * 
   */
  public: bool getShort(short& result);
  
  /**
   * 
   */
  public: bool getShortMsb(short& result);

  /**
   * 
   */
  public: bool getInt(int& result);
  
  /**
   * 
   */
  public: bool getIntMsb(int& result);  

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
