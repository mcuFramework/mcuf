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
  this->objectHashCode = this->hashCode();
  return;
}

/**
 * @brief Destroy the Object:: Object object
 * 
 */
Object::~Object(void){
  this->objectHashCode = 0;
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
void Object::delay(int milliseconds){
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
bool Object::equal(Object* object){
  return (this == object);
}

/**
 * @brief 
 * 
 * @param object 
 * @return true 
 * @return false 
 */
bool Object::equal(Object& object){
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
void Object::wait(void){
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
bool Object::wait(int timeout){
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
bool Object::yield(void){
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
bool Object::systemLock(void){
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
bool Object::systemUnlock(void){
  if(osKernelUnlock() == 0)
    return true;
  
  else
    return false;
}

/**
 * @brief Get the Name object
 * 
 * @return const char* 
 */
const char* Object::getName(void) const{
  return typeid(*this).name();
}

/**
 * @brief 
 * 
 * @return uint32_t 
 */
uint32_t Object::hashCode(void) const{
  return typeid(*this).hash_code();
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
