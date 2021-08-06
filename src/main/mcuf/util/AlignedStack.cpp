/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "AlignedStack.hpp"

/* ****************************************************************************************
 * Using
 */  
using mcuf::util::AlignedStack;
using mcuf::lang::Memory;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
AlignedStack::AlignedStack(void* buffer, uint32_t size):
              Stack(buffer, size){

  return;
}

/**
 * 
 */
AlignedStack::AlignedStack(mcuf::lang::Memory& memory):
              Stack(memory){

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

/**
 * 
 */
void* AlignedStack::alloc(uint32_t size){
  if(size & 0x00000003)
    size = (size & 0xFFFFFFFC) + 4;
  return Stack::alloc(size);
}

/**
 * 
 */
Memory AlignedStack::allocMemory(uint32_t size){
  if(size & 0x00000003)
    size = (size & 0xFFFFFFFC) + 4;
  return Stack::allocMemory(size);
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
 