/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "mcuf/util/LinkedPool.hpp"
 
/* ****************************************************************************************
 * Using
 */  
using mcuf::function::Consumer;
using mcuf::util::LinkedPool;
using mcuf::lang::Memory;


/* ****************************************************************************************
 * Macro
 */
 
/* ****************************************************************************************
 * Variable
 */

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/**
 *
 */
LinkedPool::LinkedPool(Memory& memory, uint32_t elementSize) construct Memory(memory){
  this->mElementSize = elementSize;
  this->clear();
  return;
}

/**
 *
 */
LinkedPool::~LinkedPool(void){
  return;
}

/* ****************************************************************************************
 * Public Method <Static>
 */
 
/* ****************************************************************************************
 * Public Method <Override> - mcuf::util::Iterable
 */

/**
 *
 */
void LinkedPool::forEach(mcuf::function::Consumer<mcuf::lang::Memory*>& action){
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::util::Collection
 */

/**
 *
 */
void LinkedPool::clear(void){
  
}

/**
 *
 */
bool LinkedPool::isEmpty(void){
  if(this->mUsedBlock == 0)
    return true;
  
  return false;
}

/**
 *
 */
uint32_t LinkedPool::size(void){
  return (this->length() / (this->mElementSize + 4));
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::util::Pool
 */

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
 * Private Method <Static>
 */
 
/* ****************************************************************************************
 * Private Method
 */
 
/* ****************************************************************************************
 * End of file
 */ 
