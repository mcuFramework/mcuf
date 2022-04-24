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
#define INDH()    (static_cast<int>(this->mHead & (this->mCount - 1)))
#define INDT()    (static_cast<int>(this->mTail & (this->mCount - 1)))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

/* ****************************************************************************************
 * Using
 */  
using mcuf::io::RingBuffer;
using mcuf::lang::Memory;
using mcuf::io::InputBuffer;
using mcuf::io::OutputBuffer;

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
 * Public Method <Override> - mcuf::io::OutputBuffer
 */

/**
 * @brief 
 * 
 * @param data 
 * @return true 
 * @return false 
 */
bool RingBuffer::putByte(const char result){
  uint8_t *ptr = static_cast<uint8_t*>(this->pointer());

  /* We cannot insert when queue is full */
  if (this->isFull())
    return false;

  ptr += INDH();
  *(static_cast<uint8_t*>(ptr)) = (static_cast<const uint8_t>(result));
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
int RingBuffer::put(OutputBuffer& outputBuffer){
  int num = outputBuffer.avariable();
  
  if(num <= 0)
    return 0;

  uint8_t *ptr = static_cast<uint8_t*>(this->pointer());
  int cnt1, cnt2;

  /* We cannot insert when queue is full */
  if (this->isFull())
    return 0;

  /* Calculate the segment lengths */
  cnt1 = cnt2 = this->remaining();
  if (INDH() + cnt1 >= static_cast<int>(this->mCount))
    cnt1 = static_cast<int>(this->mCount) - INDH();
  cnt2 -= cnt1;

  cnt1 = MIN(cnt1, num);
  num -= cnt1;

  cnt2 = MIN(cnt2, num);
  num -= cnt2;

  /* Write segment 1 */
  ptr += INDH();
  outputBuffer.get(ptr, cnt1);
  this->mHead += static_cast<uint32_t>(cnt1);

  /* Write segment 2 */
  ptr = static_cast<uint8_t*>(this->pointer()) + INDH();
  outputBuffer.get(ptr, cnt2);
  this->mHead += static_cast<uint32_t>(cnt2);

  return (cnt1 + cnt2);
}

/**
 * @brief 
 * 
 * @param data 
 * @param num 
 * @return int 
 */
int RingBuffer::put(const void *data, int num){
  if(num <= 0)
    return 0;
  
  if(data == nullptr){
    uint32_t max = static_cast<uint32_t>(this->remaining());

    if(static_cast<uint32_t>(num) > max)
      num = static_cast<int>(max);

    this->mHead += static_cast<uint32_t>(num);
    return static_cast<int>(num);
  }

  uint8_t *ptr = static_cast<uint8_t*>(this->pointer());
  int cnt1, cnt2;

  /* We cannot insert when queue is full */
  if (this->isFull())
    return 0;

  /* Calculate the segment lengths */
  cnt1 = cnt2 = this->remaining();
  if (INDH() + cnt1 >= static_cast<int>(this->mCount))
    cnt1 = static_cast<int>(this->mCount) - INDH();
  cnt2 -= cnt1;

  cnt1 = MIN(cnt1, num);
  num -= cnt1;

  cnt2 = MIN(cnt2, num);
  num -= cnt2;

  /* Write segment 1 */
  ptr += INDH();
  memcpy(ptr, data, static_cast<uint32_t>(cnt1));
  this->mHead += static_cast<uint32_t>(cnt1);

  /* Write segment 2 */
  ptr = static_cast<uint8_t*>(this->pointer()) + INDH();
  data = static_cast<const uint8_t*>(data) + cnt1;
  memcpy(ptr, data, static_cast<uint32_t>(cnt2));
  this->mHead += static_cast<uint32_t>(cnt2);

  return (cnt1 + cnt2);
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::io::InputBuffer
 */

/**
 * @brief 
 * 
 * @param data 
 * @return true 
 * @return false 
 */
bool RingBuffer::getByte(char& data){
  uint8_t *ptr = static_cast<uint8_t*>(this->pointer());

  /* We cannot pop when queue is empty */
  if (this->isEmpty())
    return false;

  ptr += INDT();
  data = static_cast<char>(*ptr);
  ++this->mTail;

  return true;
}

/**
 * @brief 
 * 
 * @param byteBuffer 
 * @return int 
 */
int RingBuffer::get(InputBuffer& inputBuffer){
  int num = inputBuffer.remaining();
  if(num <= 0)
    return 0;

  uint8_t *ptr = static_cast<uint8_t*>(this->pointer());
  int cnt1, cnt2;

  /* We cannot insert when queue is full */
  if (this->isFull())
    return 0;

  /* Calculate the segment lengths */
  cnt1 = cnt2 = this->remaining();
  if (INDH() + cnt1 >= static_cast<int>(this->mCount))
    cnt1 = static_cast<int>(this->mCount) - INDH();
  cnt2 -= cnt1;

  cnt1 = MIN(cnt1, num);
  num -= cnt1;

  cnt2 = MIN(cnt2, num);
  num -= cnt2;

  /* Write segment 1 */
  ptr += INDH();
  inputBuffer.put(ptr, cnt1);
  this->mHead += static_cast<uint32_t>(cnt1);

  /* Write segment 2 */
  ptr = static_cast<uint8_t*>(this->pointer()) + INDH();
  inputBuffer.put(ptr, cnt2);
  this->mHead += static_cast<uint32_t>(cnt2);

  return cnt1 + cnt2;
}

/**
 * @brief 
 * 
 * @param data 
 * @param num 
 * @return int 
 */
int RingBuffer::get(void* data, int num){
  if(num <= 0)
    return 0;
  
  if(data == nullptr){
    uint32_t max = static_cast<uint32_t>(this->avariable());

    if(static_cast<uint32_t>(num) > max)
      num = static_cast<int>(max);

    this->mTail += static_cast<uint32_t>(num);
    return num;
  }

  uint8_t *ptr = static_cast<uint8_t*>(this->pointer());
  int cnt1, cnt2;

  /* We cannot insert when queue is empty */
  if (this->isEmpty())
    return 0;

  /* Calculate the segment lengths */
  cnt1 = cnt2 = this->avariable();
  if(INDT() + cnt1 >= static_cast<int>(this->mCount))
    cnt1 = static_cast<int>(this->mCount) - INDT();
  
  cnt2 -= cnt1;

  cnt1 = MIN(cnt1, num);
  num -= cnt1;

  cnt2 = MIN(cnt2, num);
  num -= cnt2;

  /* Write segment 1 */
  ptr += INDT();
  memcpy(data, ptr, static_cast<uint32_t>(cnt1));
  this->mTail += static_cast<uint32_t>(cnt1);

  /* Write segment 2 */
  ptr = static_cast<uint8_t*>(this->pointer()) + INDT();
  data = static_cast<uint8_t*>(data) + cnt1;
  memcpy(data, ptr, static_cast<uint32_t>(cnt2));
  this->mTail += static_cast<uint32_t>(cnt2);

  return cnt1 + cnt2;
}

/**
 * @brief 
 * 
 * @param value 
 * @return int 
 */
int RingBuffer::skip(int value){
  int max = this->avariable();
  
  if(value > max)
    value = max;

  this->mTail += static_cast<uint32_t>(value);
  return value;
}

/* ****************************************************************************************
 * Public Method
 */

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
