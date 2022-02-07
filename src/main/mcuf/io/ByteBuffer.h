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
#include "mcuf/lang/ArrayPrototype.h"
#include "mcuf/lang/Object.h"
#include "mcuf/lang/Memory.h"
#include "mcuf/lang/String.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    class ByteBuffer;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
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
  private: 
    uint16_t mMark;
    uint16_t mLimit;
    uint16_t mPosition;

  /* **************************************************************************************
   *  Abstract method <Public>
   */

  /* **************************************************************************************
   *  Abstract method <Protected>
   */

  /* **************************************************************************************
   *  Construct Method
   */
  public: 

    /**
     * @brief Construct a new Byte Buffer object
     * 
     * @param memory 
     */
    ByteBuffer(const mcuf::lang::Memory& memory);

    /**
     * @brief Destroy the Byte Buffer object
     * 
     */
    virtual ~ByteBuffer(void) = default;

  /* **************************************************************************************
   *  Public Method <Static>
   */

  /* **************************************************************************************
   *  Public Method <Override>
   */

  /* **************************************************************************************
   *  Public Method <Inline>
   */
  public:

    /**
     * @brief 
     * 
     * @return uint32_t 
     */
    inline uint32_t limit(void){
      return this->mLimit;
    }

    /**
     * @brief 
     * 
     * @return uint32_t 
     */
    inline uint32_t capacity(void){
      return this->length();
    }
    
    /**
     * @brief 
     * 
     * @return uint32_t 
     */
    inline uint32_t position(void){
      return this->mPosition;
    }  
    
    /**
     * @brief 
     * 
     */
    inline void reset(void){
      this->mPosition = 0;
      this->mLimit = this->length();
      return;
    }  
    
    /**
     * @brief 
     * 
     * @return uint32_t 
     */
    inline uint32_t remaining(void){
      return this->mLimit - this->mPosition;
    }  
    
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    inline bool hasRemaining(void){
      return (this->mLimit > this->mPosition);
    }  
    
    /**
     * @brief 
     * 
     */
    inline void rewind(void){
      this->mPosition = 0;
      this->mMark = 0;
      return;
    }  
  
  /* **************************************************************************************
   *  Public Method
   */
  public:

    /**
     * @brief 
     * 
     * @param newLimit 
     * @return true 
     * @return false 
     */
    bool limit(uint32_t newLimit);

    /**
     * @brief 
     * 
     * @param newPosition 
     * @return true 
     * @return false 
     */
    bool position(uint32_t newPosition);

    /**
     * @brief 
     * 
     */
    void flip(void);
    
    /**
     * @brief 
     * 
     * @param string 
     * @return true 
     * @return false 
     */
    bool put(const char* string);
    
    /**
     * @brief 
     * 
     * @param ptr 
     * @param size 
     * @return true 
     * @return false 
     */
    bool put(const void* ptr, uint32_t size);
    
    /**
     * @brief 
     * 
     * @param string 
     * @return true 
     * @return false 
     */
    bool put(const mcuf::lang::String& string);
    
    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @return true 
     * @return false 
     */
    bool put(mcuf::io::ByteBuffer& byteBuffer);

    /**
     * @brief 
     * 
     * @param value 
     * @return true 
     * @return false 
     */
    bool putByte(const char value);
    
    /**
     * @brief 
     * 
     * @param format 
     * @param ... 
     * @return int 
     */
    int putFormat(const char* format, ...);

    /**
     * @brief 
     * 
     * @param value 
     * @return true 
     * @return false 
     */
    bool putShort(const short value);

    /**
     * @brief 
     * 
     * @param value 
     * @return true 
     * @return false 
     */
    bool putShortMsb(const short value);

    /**
     * @brief 
     * 
     * @param value 
     * @return true 
     * @return false 
     */
    bool putInt(const int value);
    
    /**
     * @brief 
     * 
     * @param value 
     * @return true 
     * @return false 
     */
    bool putIntMsb(const int value);  

    /**
     * @brief Get the Byte object
     * 
     * @param result 
     * @return true 
     * @return false 
     */
    bool getByte(char& result);

    /**
     * @brief Get the Short object
     * 
     * @param result 
     * @return true 
     * @return false 
     */
    bool getShort(short& result);
    
    /**
     * @brief Get the Short Msb object
     * 
     * @param result 
     * @return true 
     * @return false 
     */
    bool getShortMsb(short& result);

    /**
     * @brief Get the Int object
     * 
     * @param result 
     * @return true 
     * @return false 
     */
    bool getInt(int& result);
    
    /**
     * @brief Get the Int Msb object
     * 
     * @param result 
     * @return true 
     * @return false 
     */
    bool getIntMsb(int& result);  

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
