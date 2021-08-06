/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "SystemComponent.hpp"
 
/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::managerment::SystemComponent; 
using mcuf::lang::managerment::MemoryManager;

/* ****************************************************************************************
 * Construct Method
 */

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
bool SystemComponent::memoryManager(MemoryManager* memoryManager){
  if(this->locked)
    return false;
  
  this->mMemoryManager = memoryManager;
  return true;
}

/**
 * 
 */
MemoryManager* SystemComponent::memoryManager(void){
  return this->mMemoryManager;
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

/**
 * 
 */
void SystemComponent::lock(void){
  this->locked = true;
  return;
}

/**
 * 
 */
void SystemComponent::unlock(void){
  this->locked = false;
  return;
}

/* ****************************************************************************************
 * Private Method
 */
 
/* ****************************************************************************************
 * End of file
 */ 
 