/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "stdio.h"
#include "stdlib.h"
#include "System.hpp"
#include "mcuf.h"

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::System;
using mcuf::lang::managerment::MemoryManager;
using mcuf::lang::managerment::SystemComponent;

/* ****************************************************************************************
 * Global Operator
 */  

/**
 * 
 */
void * operator new(size_t n){
  if(System::memoryManager() == nullptr)
    return malloc(n);

  return System::memoryManager()->alloc(n);
}

/**
 * 
 */
void * operator new[](size_t n){
  if(System::memoryManager() == nullptr)
    return malloc(n);

  return System::memoryManager()->alloc(n);
}



/**
 * 
 */
void operator delete (void* ptr){
  if(System::memoryManager() == nullptr)
    free(ptr);

  bool result = System::memoryManager()->free(ptr);
}

/**
 * 
 */
void operator delete (void* ptr, size_t size){
  if(System::memoryManager() == nullptr)
    free(ptr);

  bool result = System::memoryManager()->free(ptr, size);
}

/* ****************************************************************************************
 * Static Variable
 */  
SystemComponent System::component = SystemComponent();

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/**
 * 
 */
void System::init(void){
  System::component.lock();
}

/**
 * 
 */
MemoryManager* System::memoryManager(void){
  return System::component.mMemoryManager;
}


/* ****************************************************************************************
 * Public Method <Override>
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
 * Private Method
 */
 
/* ****************************************************************************************
 * End of file
 */ 
