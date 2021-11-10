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
#include "mcuf/lang/OutOfMemoryError.hpp"
#include "mcuf/lang/managerment/StackerManager.hpp"

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::managerment::StackerManager;
using mcuf::lang::OutOfMemoryError;

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
  if(result == nullptr)
    throw OutOfMemoryError(__FUNCTION__, nullptr);
  
  return result;
}
  
/**
 *
 */
void* StackerManager::allocAlignment32(uint32_t size){
  void* result = this->Stacker::allocAlignment32(size);
  if(result == nullptr)
    throw OutOfMemoryError(__FUNCTION__, nullptr);
  
  return result;
}
  
/**
 *
 */
void* StackerManager::allocAlignment64(uint32_t size){
  void* result = this->Stacker::allocAlignment64(size);
  if(result == nullptr)
    throw OutOfMemoryError(__FUNCTION__, nullptr);
  
  return result;
}

/**
 * 
 */
mcuf::lang::Memory StackerManager::allocMemory(uint32_t size){
  Memory result = this->Stacker::allocMemory(size);
  if(result.isNull())
    throw OutOfMemoryError(__FUNCTION__, nullptr);
  
  return result;
}

/**
 * 
 */
mcuf::lang::Memory StackerManager::allocMemoryAlignment32(uint32_t size){
  Memory result = this->Stacker::allocMemoryAlignment32(size);
  if(result.isNull())
    throw OutOfMemoryError(__FUNCTION__, nullptr);
  
  return result;
}

/**
 * 
 */
mcuf::lang::Memory StackerManager::allocMemoryAlignment64(uint32_t size){
  Memory result = this->Stacker::allocMemoryAlignment64(size);
  if(result.isNull())
    throw OutOfMemoryError(__FUNCTION__, nullptr);
  
  
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
