/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_BA359EBF_505B_445E_8A31_2AB82A22FEB8
#define MCUF_BA359EBF_505B_445E_8A31_2AB82A22FEB8

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"
#include "mcuf/lang/Memory.h"
#include "mcuf/lang/Object.h"
#include "mcuf/io/Buffer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    class RingBuffer;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::io::RingBuffer extends mcuf::lang::Memory implements
  public mcuf::io::Buffer{

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
    uint32_t mCount;
    uint32_t mHead;
    uint32_t mTail;

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
     * @brief Construct a new Ring Buffer object
     * 
     * @param buffer 
     * @param bufferSize 
     */
    RingBuffer(void* buffer, uint32_t bufferSize);
      
    /**
     * @brief Construct a new Ring Buffer object
     * 
     * @param memory 
     */
    RingBuffer(const mcuf::lang::Memory& memory);  

    /**
     * @brief Construct a new Ring Buffer object
     * 
     * @param length 
     */
    RingBuffer(uint32_t length);

    /**
     * @brief Destroy the Ring Buffer object
     * 
     */
    virtual ~RingBuffer(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::io::Buffer
   */
  public:
    /**
     * @brief 
     * 
     */
    inline virtual void flush(void) override{
      this->mHead = this->mTail = 0;
    }

  /* **************************************************************************************
   * Public Method <Override> - mcuf::io::OutputBuffer
   */
  public:
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    inline virtual bool isEmpty(void) const override{
      return (VACCESS(const uint32_t, this->mHead) == VACCESS(const uint32_t, this->mTail));
    }
  
    /**
     * @brief 
     * 
     * @return int 
     */
    inline virtual int avariable(void) const override{
      return static_cast<int>((VACCESS(const uint32_t, this->mHead) - VACCESS(const uint32_t, this->mTail)));
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
   * Public Method <Override> - mcuf::io::InputBuffer
   */  
  public:
    /**
     * @brief Return empty status of ring buffer.
     * 
     * @return true is full.
     * @return false not full.
     */
    inline virtual bool isFull(void) const override{
      return (this->avariable() >= static_cast<int>(this->mCount));
    }

    /**
     * @brief 
     * 
     * @return int 
     */
    inline virtual int remaining(void) const override{
      return (static_cast<int>(this->mCount) - this->avariable());
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
   * Public Method <Inline>
   */
  public: 

    /**
     * @brief Return size the ring buffer.
     * 
     * @return int Size of the ring buffer in bytes.
     */
    inline int getSize(void){
      return static_cast<int>(this->mCount);
    }

    /**
     * @brief Get the Head Position object
     * 
     * @return int 
     */
    inline int getHeadPosition(void){
      return static_cast<int>((this->mHead & (this->mCount -1)));
    }

    /**
     * @brief Get the Tail Position object
     * 
     * @return int 
     */
    inline int getTailPosition(void){
      return static_cast<int>((this->mTail & (this->mCount - 1)));
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
  
  /**
   *
   */
  private: void init(void);

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_BA359EBF_505B_445E_8A31_2AB82A22FEB8 */
