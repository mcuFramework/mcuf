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
#include "mcuf_macro.h" 
#include "mcuf/lang/Object.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    class RingBuffer;
  }
}

/* ****************************************************************************************
 * Class Object
 */  
class mcuf::util::RingBuffer :
      public mcuf::lang::Object{

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
  private: void* mData;
  private: uint32_t mCount;
  private: uint32_t mHead;
  private: uint32_t mTail;


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
  public: RingBuffer(void* buffer, uint32_t bufferSize);

  /**
   * Disconstruct.
   */
  public: virtual ~RingBuffer(void) = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method
   */

  /**
   *
   */
  public: inline void flush(void){
    this->mHead = this->mTail = 0;
  }

  /**
   * Return size the ring buffer.
   *
   * @return	Size of the ring buffer in bytes.
   */
  public: inline uint32_t getSize(void){
    return this->mCount;
  }

  /**
   * Return number of items in the ring buffer
   *
   * @return	Number of items in the ring buffer.
   */
  public: inline uint32_t getCount(void){
    return VACCESS(uint32_t, this->mHead) - VACCESS(uint32_t, this->mTail);
  }

  /**
   * Return number of free items in the ring buffer.
   *
   * @return	Number of free items in the ring buffer.
   */
  public: inline uint32_t getFree(void){
    return this->mCount = this->getCount();
  }

  /**
   * Return empty status of ring buffer.
   *
   * @return	1 if the ring buffer is full, otherwise 0.
   */
  public: inline bool isFull(void){
    return (this->getCount() >= this->mCount);
  }

  /**
   * Return empty status of ring buffer.
   *
   * @return	1 if the ring buffer is empty, otherwise 0.
   */
  public: bool isEmpty(void){
    return (VACCESS(uint32_t, this->mHead) == VACCESS(uint32_t, this->mTail));
  }

  /**
   * 
   */
  public: bool insert(const void* data);

  /**
   * 
   */
  public: int insertMult(const void *data, int num);

  /**
   * 
   */
  public: bool pop(void* data);

  /**
   * 
   */
  public: int popMult(void* data, int num);

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

#endif/* MCUF_BA359EBF_505B_445E_8A31_2AB82A22FEB8 */
