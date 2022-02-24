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
#include "cmsis_rtos/rtx_os.h"
#include "mcuf/lang/Object.h"
 
/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::Object;
using mcuf::lang::managerment::MemoryAllocator;
 
/* ****************************************************************************************
 * Construct Method
 */

/**
 *
 */
Object::Object(void){
  this->objectRecodeBase = this;
}

/**
 *
 */
Object::~Object(void){
  this->objectRecodeBase = nullptr;
}

/* ****************************************************************************************
 * Operator Method
 */

/**
 * 
 */
void* Object::operator new(size_t n){
  return ::operator new(n);
}

/**
 * 
 */
void* Object::operator new(size_t n, void* const p){
  return p;
}

/**
 *
 */
void* Object::operator new(size_t n, MemoryAllocator& allocator){
  return allocator.alloc(n);
}

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
void Object::delay(uint32_t milliseconds){
  osDelay(milliseconds);
  return;
}

/**
 * 
 */
bool Object::equal(Object* object){
  return (this == object);
}

/**
 * 
 */
bool Object::equal(Object& object){
  return (this == &object);
}

/**
 * 
 */
void Object::finalize(void){
  delete this;
}

/**
 *
 */
void Object::wait(void){
  osThreadFlagsClear(0x00000001U);
  osThreadFlagsWait(0x00000001U, osFlagsWaitAny, osWaitForever);
}

/**
 *
 */
bool Object::wait(uint32_t timeout){
  osThreadFlagsClear(0x00000001U);
  if(osThreadFlagsWait(0x00000001U, osFlagsWaitAny, timeout) == osFlagsErrorTimeout)
    return true;
  
  return false;
}

/**
 *
 */
bool Object::yield(void){
  if(osThreadYield() == osOK)
    return true;
  
  return false;
}

/**
 *
 */
bool Object::systemLock(void){
  if(osKernelLock() > 0)
    return true;
  
  else
    return false;
}

/**
 *
 */
bool Object::systemUnlock(void){
  if(osKernelUnlock() == 0)
    return true;
  
  else
    return false;
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