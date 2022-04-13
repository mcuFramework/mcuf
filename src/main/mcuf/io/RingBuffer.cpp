/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf/io/RingBuffer.h"

/* ****************************************************************************************
 * Macro
 */  
#define INDH()    (this->mHead & (this->mCount - 1))
#define INDT()    (this->mTail & (this->mCount - 1))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

/* ****************************************************************************************
 * Using
 */  
using mcuf::io::RingBuffer;
using mcuf::lang::Memory;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Ring Buffer:: Ring Buffer object
 * 
 * @param buffer 
 * @param bufferSize 
 */
RingBuffer::RingBuffer(void* buffer, uint32_t bufferSize) : Memory(buffer, bufferSize){
  this->init();
  return;
}

/**
 * @brief Construct a new Ring Buffer:: Ring Buffer object
 * 
 * @param memory 
 */
RingBuffer::RingBuffer(const Memory& memory) : Memory(memory){
  this->init();
  return;
}

/**
 * @brief Construct a new Ring Buffer object
 * 
 * @param length 
 */
RingBuffer::RingBuffer(uint32_t length) : Memory(length){
  this->init();
  return;
}

/**
 * @brief Destroy the Ring Buffer object
 * 
 */
RingBuffer::~RingBuffer(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */
 
/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

/**
 * @brief 
 * 
 * @param data 
 * @return true 
 * @return false 
 */
bool RingBuffer::insert(const void* data){
  uint8_t *ptr = static_cast<uint8_t*>(this->pointer());

  /* We cannot insert when queue is full */
  if (this->isFull())
    return false;

  ptr += INDH();
  *(static_cast<uint8_t*>(ptr)) = *(static_cast<const uint8_t*>(data));
  this->mHead++;

  return true;
}

/**
 * @brief 
 * 
 * @param data 
 * @param num 
 * @return int 
 */
uint32_t RingBuffer::insertMult(const void *data, uint32_t num){
  if(data == nullptr){
    uint32_t max = this->getFree();

    if(num > max)
      num = max;

    this->mHead += static_cast<uint32_t>(num);
    return num;
  }

  uint8_t *ptr = static_cast<uint8_t*>(this->pointer());
  uint32_t cnt1, cnt2;

  /* We cannot insert when queue is full */
  if (this->isFull())
    return 0;

  /* Calculate the segment lengths */
  cnt1 = cnt2 = static_cast<uint32_t>(this->getFree());
  if (INDH() + cnt1 >= this->mCount)
    cnt1 = this->mCount - INDH();
  cnt2 -= cnt1;

  cnt1 = MIN(cnt1, static_cast<uint32_t>(num));
  num -= cnt1;

  cnt2 = MIN(cnt2, static_cast<uint32_t>(num));
  num -= cnt2;

  /* Write segment 1 */
  ptr += INDH();
  memcpy(ptr, data, cnt1);
  this->mHead += cnt1;

  /* Write segment 2 */
  ptr = static_cast<uint8_t*>(this->pointer()) + INDH();
  data = static_cast<const uint8_t*>(data) + cnt1;
  memcpy(ptr, data, cnt2);
  this->mHead += cnt2;

  return (cnt1 + cnt2);
}

/**
 * @brief 
 * 
 * @param data 
 * @return true 
 * @return false 
 */
bool RingBuffer::pop(void* data){
  uint8_t *ptr = static_cast<uint8_t*>(this->pointer());

  /* We cannot pop when queue is empty */
  if (this->isEmpty())
    return false;

  ptr += INDT();
  *static_cast<uint8_t*>(data) = *static_cast<uint8_t*>(ptr);
  ++this->mTail;

  return true;
}

/**
 * @brief 
 * 
 * @param data 
 * @param num 
 * @return int 
 */
uint32_t RingBuffer::popMult(void* data, uint32_t num){
  if(data == nullptr){
    uint32_t max = this->getCount();

    if(num > max)
      num = max;

    this->mTail += static_cast<uint32_t>(num);
    return num;
  }

  uint8_t *ptr = static_cast<uint8_t*>(this->pointer());
  uint32_t cnt1, cnt2;

  /* We cannot insert when queue is empty */
  if (this->isEmpty())
    return 0;

  /* Calculate the segment lengths */
  cnt1 = cnt2 = static_cast<uint32_t>(this->getCount());
  if(INDT() + cnt1 >= this->mCount)
    cnt1 = this->mCount - INDT();
  cnt2 -= cnt1;

  cnt1 = MIN(cnt1, static_cast<uint32_t>(num));
  num -= cnt1;

  cnt2 = MIN(cnt2, static_cast<uint32_t>(num));
  num -= cnt2;

  /* Write segment 1 */
  ptr += INDT();
  memcpy(data, ptr, cnt1);
  this->mTail += cnt1;

  /* Write segment 2 */
  ptr = static_cast<uint8_t*>(this->pointer()) + INDT();
  data = static_cast<uint8_t*>(data) + cnt1;
  memcpy(data, ptr, cnt2);
  this->mTail += cnt2;

  return (cnt1 + cnt2);
}

/* ****************************************************************************************
 * Protected Method <Static>
 */
 
/* ****************************************************************************************
 * Protected Method <Override>
 */ 

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */

/**
 * @brief 
 * 
 */
void RingBuffer::init(void){
  uint32_t bufferSize = static_cast<uint32_t>(this->length());
  this->mHead = 0;
  this->mTail = 0;
  
  for(int i=0; i<32; i++){
    bufferSize &= ~(1<<i);
    if(!bufferSize){
      bufferSize = (1<<i);
      break;
    }
  }
  
  this->mCount = bufferSize;
}
 
/* ****************************************************************************************
 * End of file
 */ 
