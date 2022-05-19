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
#include "mcuf/io/Buffer.h"

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
class mcuf::io::ByteBuffer extends mcuf::lang::Memory implements
  public mcuf::io::Buffer{

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
    int mMark;
    int mLimit;
    int mPosition;

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
    virtual ~ByteBuffer(void) override;
  
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
    inline ByteBuffer& operator<<(int v){
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
    inline ByteBuffer& operator>>(unsigned int& v){
      this->getInt(v);
      return *this;
    }
    
    /**
     *
     */
    inline int operator=(int v){
      this->position(v);
      return this->position();
    }
    
    /**
     *
     */
    inline void operator+=(int shift){
      this->position(this->position() + shift);
    }
    
    /**
     *
     */
    inline void operator-=(int shift){
      this->position(this->position() - shift);
    }
    
    /**
     *
     */
    inline unsigned int operator++(void){
      this->position(this->position() + 1);
      return static_cast<unsigned int>(this->position());
    }
    
    /**
     *
     */
    inline unsigned int operator--(void){
      this->position(this->position() - 1);
      return static_cast<unsigned int>(this->position());
    }

        /**
     *
     */
    inline unsigned int operator++(int){
      unsigned int result = static_cast<unsigned int>(this->position());
      this->position(this->position() + 1);
      return result;
    }
    
    /**
     *
     */
    inline unsigned int operator--(int){
      unsigned int result = static_cast<unsigned int>(this->position());
      this->position(this->position() - 1);
      return result;
    }
    
  /* **************************************************************************************
   *  Public Method <Static>
   */

  /* **************************************************************************************
   *  Public Method <Override> - mcuf::lang::Memory
   */
  public:
    /**
     * @brief 
     * 
     * @param ch 
     * @return int 
     */
    virtual int indexOf(char ch) const override;
    
    /**
     * @brief 
     * 
     * @param ch 
     * @param offset 
     * @return int 
     */
    virtual int indexOf(char ch, int offset) const override;
    
    /**
     * @brief 
     * 
     * @param str 
     * @return int 
     */
    virtual int indexOfString(const char* str) const override;
    
    /**
     * @brief 
     * 
     * @param destination 
     * @param destinationLen 
     * @param start 
     * @param limit 
     * @return int 
     */
    virtual int indexOfData(const void* destination, int destinationLen, int start) const override;
    
  /* **************************************************************************************
   *  Public Method <Override> - mcuf::io::Buffer
   */
  public:
    /**
     * @brief 
     * 
     */
    inline virtual void flush(void) override{
      this->mPosition = 0;
      this->mMark = 0;
      this->mLimit = static_cast<uint16_t>(this->length());
      return;
    }
  
  /* **************************************************************************************
   *  Public Method <Override> - mcuf::io::OutputBuffer
   */
  public:
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    inline virtual bool isEmpty(void) const override{
      return (this->mPosition >= this->mLimit);
    }    
  
    /**
     * @brief 
     * 
     * @return int 
     */
    inline virtual int avariable(void) const override{
      return (this->mLimit - this->mPosition);
    }

    /**
     * @brief pop buffer byte non blocking.
     * 
     * @param result 
     * @return true has data in buffer.
     * @return false no data in buffer.
     */
    virtual bool getByte(char& result) override;

    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @return int 
     */
    virtual int get(mcuf::io::InputBuffer& inputBuffer) override;

    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @return int 
     */
    virtual int get(mcuf::io::InputBuffer& inputBuffer, int length) override;    
    
    /**
     * @brief 
     * 
     * @param buffer 
     * @param bufferSize 
     * @return int 
     */
    virtual int get(void* buffer, int bufferSize) override;

    /**
     * @brief 
     * 
     * @param value 
     * @return int 
     */
    virtual int skip(int value) override;
    
  /* **************************************************************************************
   *  Public Method <Override> - mcuf::io::InputBuffer
   */
  public:
    /**
     * @brief Return empty status of ring buffer.
     * 
     * @return true is full.
     * @return false not full.
     */
    inline virtual bool isFull(void) const override{
      return (this->mPosition >= this->mLimit);
    }    
  
    /**
     * @brief 
     * 
     * @return int 
     */
    inline virtual int remaining(void) const override{
      return (this->mLimit - this->mPosition);
    }

    /**
     * @brief pop buffer byte non blocking.
     * 
     * @param result 
     * @return true has data in buffer.
     * @return false no data in buffer.
     */
    virtual bool putByte(const char result) override;

    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @return int 
     */
    virtual int put(mcuf::io::OutputBuffer& outputBuffer) override;
    
    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @param length 
     * @return int 
     */
    virtual int put(mcuf::io::OutputBuffer& outputBuffer, int length) override;  

    /**
     * @brief 
     * 
     * @param buffer 
     * @param bufferSize 
     * @return int 
     */
    virtual int put(const void* buffer, int bufferSize) override;
    
  /* **************************************************************************************
   *  Public Method <Inline>
   */
  public:

    /**
     * @brief 
     * 
     * @return unsigned int 
     */
    inline int limit(void) const{
      return this->mLimit;
    }

    /**
     * @brief 
     * 
     * @return unsigned int 
     */
    inline int capacity(void) const{
      return this->length();
    }
    
    /**
     * @brief 
     * 
     * @return unsigned int 
     */
    inline int position(void) const{
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
    inline bool getInt(unsigned int& result){
      return this->getInt(reinterpret_cast<int&>(result));
    }
    
    /**
     * @brief Get the Int Msb object
     * 
     * @param result 
     * @return true 
     * @return false 
     */
    inline bool getIntMsb(unsigned int& result){
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
    bool limit(int newLimit);

    /**
     * @brief 
     * 
     * @param newPosition 
     * @return true 
     * @return false 
     */
    bool position(int newPosition);

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
     * @param string 
     * @return true 
     * @return false 
     */
    bool put(const mcuf::lang::String& string);
    
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
     * @param format 
     * @param args 
     * @return int 
     */
    int putFormat(const char* format, va_list args);

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
    bool putFloat(const float value);
    
    /**
     * @brief 
     * 
     * @param value 
     * @return true 
     * @return false 
     */
    bool putFloatMsb(const float value);    
    
    /**
     * @brief 
     * 
     * @param value 
     * @return true 
     * @return false 
     */
    bool putIntMsb(const int value);  

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

    /**
     * @brief Get the Float object
     * 
     * @param result 
     * @return true 
     * @return false 
     */
    bool getFloat(float& result);

    /**
     * @brief 
     * 
     */
    bool getFloatMsb(float& result);

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
