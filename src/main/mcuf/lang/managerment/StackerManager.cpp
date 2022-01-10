/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/lang/managerment/StackerManager.hpp"

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::managerment::StackerManager;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
StackerManager::StackerManager(void* buffer, uint32_t size) construct Stacker(buffer, size){
  return;
}

/**
 * 
 */
StackerManager::StackerManager(Memory& memory) construct Stacker(memory){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */
 
/* ****************************************************************************************
 * Public Method <Override> - mcuf::util::Stacker
 */

/**
 * 
 */
void* StackerManager::alloc(uint32_t size){
  void* result = this->Stacker::alloc(size);
  return result;
}
  
/**
 *
 */
void* StackerManager::allocAlignment32(uint32_t size){
  void* result = this->Stacker::allocAlignment32(size);
  return result;
}
  
/**
 *
 */
void* StackerManager::allocAlignment64(uint32_t size){
  void* result = this->Stacker::allocAlignment64(size);
  return result;
}

/**
 * 
 */
mcuf::lang::Memory StackerManager::allocMemory(uint32_t size){
  Memory result = this->Stacker::allocMemory(size);
  return result;
}

/**
 * 
 */
mcuf::lang::Memory StackerManager::allocMemoryAlignment32(uint32_t size){
  Memory result = this->Stacker::allocMemoryAlignment32(size);
  return result;
}

/**
 * 
 */
mcuf::lang::Memory StackerManager::allocMemoryAlignment64(uint32_t size){
  Memory result = this->Stacker::allocMemoryAlignment64(size);
  return result;
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
 
/* ****************************************************************************************
 * End of file
 */ 
