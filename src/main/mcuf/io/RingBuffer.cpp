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
 *
 */
RingBuffer::RingBuffer(void* buffer, uint32_t bufferSize) construct Memory(buffer, bufferSize){
  this->init();
  return;
}

/**
 * Construct.
 */
RingBuffer::RingBuffer(const Memory& memory) construct Memory(memory){
  this->init();
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
 * 
 */
bool RingBuffer::insert(const void* data){
  uint8_t *ptr = (uint8_t*)this->pointer();

  /* We cannot insert when queue is full */
  if (this->isFull())
    return false;

  ptr += INDH();
  *((uint8_t*)ptr) = *((uint8_t*)data);
  this->mHead++;

  return true;
}

/**
 * 
 */
int RingBuffer::insertMult(const void *data, int num){
  if(data == nullptr){
    int max = this->getFree();

    if(num > max)
      num = max;

    this->mHead += num;
    return num;
  }

  uint8_t *ptr = (uint8_t*)this->pointer();
  int cnt1, cnt2;

  /* We cannot insert when queue is full */
  if (this->isFull())
    return 0;

  /* Calculate the segment lengths */
  cnt1 = cnt2 = this->getFree();
  if (INDH() + cnt1 >= this->mCount)
    cnt1 = this->mCount - INDH();
  cnt2 -= cnt1;

  cnt1 = MIN(cnt1, num);
  num -= cnt1;

  cnt2 = MIN(cnt2, num);
  num -= cnt2;

  /* Write segment 1 */
  ptr += INDH();
  memcpy(ptr, data, cnt1);
  this->mHead += cnt1;

  /* Write segment 2 */
  ptr = (uint8_t *) this->pointer() + INDH();
  data = (const uint8_t *) data + cnt1;
  memcpy(ptr, data, cnt2);
  this->mHead += cnt2;

  return cnt1 + cnt2;
}

/**
 * 
 */
bool RingBuffer::pop(void* data){
  uint8_t *ptr = (uint8_t*)this->pointer();

  /* We cannot pop when queue is empty */
  if (this->isEmpty())
    return false;

  ptr += INDT();
  *((uint8_t*)data) = *((uint8_t*)ptr);
  ++this->mTail;

  return true;
}

/**
 * 
 */
int RingBuffer::popMult(void* data, int num){
  if(data == nullptr){
    int max = this->getCount();

    if(num > max)
      num = max;

    this->mTail += num;
    return num;
  }

  uint8_t *ptr = (uint8_t*)this->pointer();
  int cnt1, cnt2;

  /* We cannot insert when queue is empty */
  if (this->isEmpty())
    return 0;

  /* Calculate the segment lengths */
  cnt1 = cnt2 = this->getCount();
  if(INDT() + cnt1 >= this->mCount)
    cnt1 = this->mCount - INDT();
  cnt2 -= cnt1;

  cnt1 = MIN(cnt1, num);
  num -= cnt1;

  cnt2 = MIN(cnt2, num);
  num -= cnt2;

  /* Write segment 1 */
  ptr += INDT();
  memcpy(data, ptr, cnt1);
  this->mTail += cnt1;

  /* Write segment 2 */
  ptr = (uint8_t *) this->pointer() + INDT();
  data = (uint8_t *) data + cnt1;
  memcpy(data, ptr, cnt2);
  this->mTail += cnt2;

  return cnt1 + cnt2;
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
 *
 */
void RingBuffer::init(void){
  uint32_t bufferSize = this->length();
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
