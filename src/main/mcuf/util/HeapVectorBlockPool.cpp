/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "HeapVectorBlockPool.hpp"
#include "mcuf.h"

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::Math;
using mcuf::util::HeapVectorBlockPool;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
HeapVectorBlockPool::HeapVectorBlockPool(uint32_t elementSize, uint32_t capacity) :
                     VectorBlockPool(new uint32_t[Math::ceil(capacity, 32UL)],
                                     new uint8_t[elementSize*capacity], 
                                     elementSize,
                                     capacity){

  return;
}

/**
 * 
 */
HeapVectorBlockPool::~HeapVectorBlockPool(void){
  delete BlockPool::mPointer;
  delete BlockPool::mFlags;
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
void HeapVectorBlockPool::expansion(uint32_t capacity){
  HeapVectorBlockPool* p = new HeapVectorBlockPool(this->mElementSize, capacity);
  this->vectorAdd(p);
  return;
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

/* ****************************************************************************************
 * End of file
 */ 
