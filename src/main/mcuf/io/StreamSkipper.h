/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_191BC7E7_9B06_42F9_A2A6_564525AECDC8
#define MCUF_191BC7E7_9B06_42F9_A2A6_564525AECDC8

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/lang/Object.h"
#include "mcuf/io/InputBuffer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    class StreamSkipper;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class mcuf::io::StreamSkipper extends mcuf::lang::Object implements
public mcuf::io::InputBuffer{

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  private:
    int mPosition;
    int mCapacity;

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  public: 
    /**
     * @brief Construct a new Stream Skipper object
     * 
     */
    StreamSkipper(void);

    /**
     * @brief Destroy the Stream Skipper object
     * 
     */
    virtual ~StreamSkipper(void) override;

  /* **************************************************************************************
   * Operator Method
   */
  public:
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
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::io::InputBuffer
   */
  public:
    /**
     * @brief ??????InputBuffer????????????
     * 
     * @return true ??????
     * @return false ?????????????????????
     */
    inline virtual bool isFull(void) const override{
      return (this->mPosition >= this->mCapacity);
    }

    /**
     * @brief ??????InputBuffer???????????????
     * 
     * @return int InputBuffer???????????????
     */
    inline virtual int remaining(void) const override{
      return (this->mCapacity - this->mPosition);
    }

    /**
     * @brief ???data?????????InputBuffer
     * 
     * @param data ????????????
     * @return true ?????????data?????????InputBuffer
     * @return false InputBuffer??????
     */
    virtual bool putByte(const char data) override;

    /**
     * @brief ???outputBuffer??????????????????InputBuffer
     * 
     * @param byteBuffer ????????????
     * @return int ??????????????????(byte)
     */
    virtual int put(mcuf::io::OutputBuffer& outputBuffer) override;

    /**
     * @brief ???buffer??????????????????InputBuffer
     * 
     * @param buffer ????????????
     * @param length ????????????
     * @return int ??????????????????(byte)
     */
    virtual int put(mcuf::io::OutputBuffer& outputBuffer, int length) override;      
    
    /**
     * @brief ???buffer??????????????????InputBuffer
     * 
     * @param buffer ????????????
     * @param bufferSize ??????????????????
     * @return int ??????????????????(byte)
     */
    virtual int put(const void* buffer, int length) override;

  /* **************************************************************************************
   * Public Method <Inline>
   */
  public:

    /**
     * @brief 
     * 
     * @param v 
     */
    inline void position(int v){
      if(v < 0)
        v = 0;

      if(v > this->mCapacity)
        v = this->mCapacity;

      this->mPosition = v;
      return;
    }
    
    /**
     * @brief 
     * 
     * @return int 
     */
    inline int position(void){
      return this->mPosition;
    }

    /**
     * @brief 
     * 
     * @param v 
     */
    inline void capacity(int v){
      if(v < 0)
        v = 0;

      if(this->mPosition > v)
        this->mPosition = v;

      this->mCapacity = v;
      return;
    }

    /**
     * @brief 
     * 
     * @return int 
     */
    inline int capacity(void){
      return this->mCapacity;
    }

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

/* ****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_191BC7E7_9B06_42F9_A2A6_564525AECDC8 */
