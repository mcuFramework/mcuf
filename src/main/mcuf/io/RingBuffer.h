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
class mcuf::io::RingBuffer extends mcuf::lang::Memory{

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
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method <Inline>
   */
  public: 
  
    /**
     * @brief 
     * 
     */
    inline void flush(void){
      this->mHead = this->mTail = 0;
    }

    /**
     * @brief Return size the ring buffer.
     * 
     * @return int Size of the ring buffer in bytes.
     */
    inline int getSize(void){
      return static_cast<int>(this->mCount);
    }

    /**
     * @brief Return number of items in the ring buffer
     * 
     * @return int Number of items in the ring buffer.
     */
    inline int getCount(void){
      return static_cast<int>((VACCESS(uint32_t, this->mHead) - VACCESS(uint32_t, this->mTail)));
    }

    /**
     * @brief Return number of free items in the ring buffer.
     * 
     * @return int Number of free items in the ring buffer.
     */
    inline int getFree(void){
      return (static_cast<int>(this->mCount) - this->getCount());
    }

    /**
     * @brief Return empty status of ring buffer.
     * 
     * @return true is full.
     * @return false not full.
     */
    inline bool isFull(void){
      return (this->getCount() >= static_cast<int>(this->mCount));
    }

    /**
     * @brief Return empty status of ring buffer.
     * 
     * @return true is empty.
     * @return false not empty.
     */
    inline bool isEmpty(void){
      return (VACCESS(uint32_t, this->mHead) == VACCESS(uint32_t, this->mTail));
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
  public:

    /**
     * @brief 
     * 
     * @param data 
     * @return true 
     * @return false 
     */
    virtual bool insert(const void* data);
    
    /**
     * @brief 
     * 
     * @param data 
     * @param num 
     * @return int 
     */
    virtual int insertMult(const void *data, int num);

    /**
     * @brief 
     * 
     * @param data 
     * @return true 
     * @return false 
     */
    virtual bool pop(void* data);

    /**
     * @brief 
     * 
     * @param data 
     * @param num 
     * @return int 
     */
    virtual int popMult(void* data, int num);

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
