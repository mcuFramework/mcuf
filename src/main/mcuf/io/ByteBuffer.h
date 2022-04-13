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
     * @brief Construct a new Byte Buffer object
     * 
     * @param length 
     */
    ByteBuffer(size_t length);

    /**
     * @brief Destroy the Byte Buffer object
     * 
     */
    virtual ~ByteBuffer(void);
  
  /* **************************************************************************************
   * Operator Method
   */
  public:

    /**
     *
     */
    inline ByteBuffer& operator<<(char c){
      this->putByte(c);
      return *this;
    }  
  
    /**
     *
     */
    inline ByteBuffer& operator<<(short s){
      this->putShort(s);
      return *this;
    }  
  
    /**
     *
     */
    inline ByteBuffer& operator<<(int32_t v){
      this->putInt(v);
      return *this;
    }  
  
    /**
     *
     */
    inline ByteBuffer& operator<<(const char* string){
      this->put(string);
      return *this;
    }
    
    /**
     *
     */
    inline ByteBuffer& operator<<(mcuf::lang::String& string){
      this->put(string);
      return *this;
    }        
    
    /**
     *
     */
    inline ByteBuffer& operator>>(char& c){
      this->getByte(c);
      return *this;
    }
    
    /**
     *
     */
    inline ByteBuffer& operator>>(uint8_t& c){
      this->getByte(c);
      return *this;
    }    
  
    /**
     *
     */
    inline ByteBuffer& operator>>(short& s){
      this->getShort(s);
      return *this;
    }
    
    /**
     *
     */
    inline ByteBuffer& operator>>(uint16_t& s){
      this->getShort(s);
      return *this;
    }  
  
    /**
     *
     */
    inline ByteBuffer& operator>>(int& v){
      this->getInt(v);
      return *this;
    }
    
    /**
     *
     */
    inline ByteBuffer& operator>>(uint32_t& v){
      this->getInt(v);
      return *this;
    }
    
    /**
     *
     */
    inline int32_t operator=(int32_t v){
      this->position(static_cast<uint32_t>(v));
      return static_cast<int32_t>(this->position());
    }
    
    /**
     *
     */
    inline void operator+=(int32_t shift){
      this->position(static_cast<uint32_t>(static_cast<int32_t>(this->position()) + shift));
    }
    
    /**
     *
     */
    inline void operator-=(int32_t shift){
      this->position(static_cast<uint32_t>(static_cast<int32_t>(this->position()) - shift));
    }
    
    /**
     *
     */
    inline uint32_t operator++(void){
      this->position(this->position() + 1);
      return this->position();
    }
    
    /**
     *
     */
    inline uint32_t operator--(void){
      this->position(this->position() - 1);
      return this->position();
    }

        /**
     *
     */
    inline uint32_t operator++(int){
      uint32_t result = this->position();
      this->position(this->position() + 1);
      return result;
    }
    
    /**
     *
     */
    inline uint32_t operator--(int){
      uint32_t result = this->position();
      this->position(this->position() - 1);
      return result;
    }
    
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
     */
    inline void clear(void){
      this->mPosition = 0;
      this->mMark = 0;
      this->mLimit = static_cast<uint16_t>(this->length());
      return;
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
      this->position(this->mMark);
      return;
    }  
    
    /**
     * @brief 
     * 
     * @return uint32_t 
     */
    inline uint32_t remaining(void){
      return static_cast<uint32_t>(this->mLimit - this->mPosition);
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
    inline void mark(void){
      this->mMark = mPosition;
      return;
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
    
    /**
     * @brief Get the Byte object
     * 
     * @param result 
     * @return true 
     * @return false 
     */
    inline bool getByte(uint8_t& result){
      return this->getByte(reinterpret_cast<char&>(result));
    }

    /**
     * @brief Get the Short object
     * 
     * @param result 
     * @return true 
     * @return false 
     */
    inline bool getShort(uint16_t& result){
      return this->getShort(reinterpret_cast<short&>(result));
    }
    
    /**
     * @brief Get the Short Msb object
     * 
     * @param result 
     * @return true 
     * @return false 
     */
    inline bool getShortMsb(uint16_t& result){
      return this->getShortMsb(reinterpret_cast<short&>(result));
    }

    /**
     * @brief Get the Int object
     * 
     * @param result 
     * @return true 
     * @return false 
     */
    inline bool getInt(uint32_t& result){
      return this->getInt(reinterpret_cast<int&>(result));
    }
    
    /**
     * @brief Get the Int Msb object
     * 
     * @param result 
     * @return true 
     * @return false 
     */
    inline bool getIntMsb(uint32_t& result){
      return this->getIntMsb(reinterpret_cast<int&>(result));
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
     * @return int32_t 
     */
    int32_t putFormat(const char* format, ...);

    /**
     * @brief 
     * 
     * @param format 
     * @param args 
     * @return int32_t 
     */
    int32_t putFormat(const char* format, va_list args);

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
    bool putInt(const int32_t value);
    
    /**
     * @brief 
     * 
     * @param value 
     * @return true 
     * @return false 
     */
    bool putIntMsb(const int32_t value);  

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

#endif /* MCUF_C76BAF3F_EE1F_46A3_A050_9CD1057055E5 */
