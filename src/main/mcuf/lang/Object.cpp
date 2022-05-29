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
using mcuf::lang::Allocator;
 
/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Object:: Object object
 * 
 */
Object::Object(void){
  return;
}

/**
 * @brief Destroy the Object:: Object object
 * 
 */
Object::~Object(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/**
 * @brief 
 * 
 * @param n 
 * @return void* 
 */
void* Object::operator new(size_t n){
  return ::operator new(n);
}

/**
 * @brief 
 * 
 * @param n 
 * @param p 
 * @return void* 
 */
void* Object::operator new(size_t n, void* const p){
  return p;
}

/**
 * @brief 
 * 
 * @param n 
 * @param allocator 
 * @return void* 
 */
void* Object::operator new(size_t n, Allocator& allocator){
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
 * @brief 
 * 
 * @param milliseconds 
 */
void Object::delay(int milliseconds) const{
  if(milliseconds <= 0)
    return;
  
  osDelay(static_cast<uint32_t>(milliseconds));
  return;
}

/**
 * @brief 
 * 
 * @param object 
 * @return true 
 * @return false 
 */
bool Object::equal(Object* object) const{
  return (this == object);
}

/**
 * @brief 
 * 
 * @param object 
 * @return true 
 * @return false 
 */
bool Object::equal(Object& object) const{
  return (this == &object);
}

/**
 * @brief 
 * 
 */
void Object::finalize(void){
  delete this;
}

/**
 * @brief 
 * 
 */
void Object::wait(void) const{
  osThreadFlagsClear(0x00000001U);
  osThreadFlagsWait(0x00000001U, osFlagsWaitAny, osWaitForever);
}

/**
 * @brief 
 * 
 * @param timeout 
 * @return true 
 * @return false 
 */
bool Object::wait(int timeout) const{
  if(timeout <= 0)
    return false;
  
  osThreadFlagsClear(0x00000001U);
  if(osThreadFlagsWait(0x00000001U, osFlagsWaitAny, static_cast<uint32_t>(timeout)) == osFlagsErrorTimeout)
    return true;
  
  return false;
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Object::yield(void) const{
  if(osThreadYield() == osOK)
    return true;
  
  return false;
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Object::systemLock(void) const{
  if(osKernelLock() > 0)
    return true;
  
  else
    return false;
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Object::systemUnlock(void) const{
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
