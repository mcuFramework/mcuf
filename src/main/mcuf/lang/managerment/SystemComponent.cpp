
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
using mcuf::io::OutputStream;  
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
bool SystemComponent::memoryManager(MemoryManager* m){
  if(this->locked)
    return false;
  
  this->mMemoryManager = m;
  return true;
}

/**
 * 
 */
MemoryManager* SystemComponent::memoryManager(void){
  return this->mMemoryManager;
}

/**
 * 
 */
bool SystemComponent::outputString(OutputStream* o){
  if(this->locked)
    return false;
  
  this->mOutputString = o;
  return true;
}

/**
 * 
 */
OutputStream* SystemComponent::outputString(void){
  return this->mOutputString;
}

/**
 * 
 */
bool SystemComponent::timer(mcuf::hal::Timer* t){
  if(this->locked)
    return false;
  
  this->mTimer = t;
  return true;
}

/**
 * 
 */
mcuf::hal::Timer* SystemComponent::timer(void){
  return this->mTimer;
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
 