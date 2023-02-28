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

//-----------------------------------------------------------------------------------------
#include "./Object.h"
#include "./System.h"
#include "./Thread.h"
#include "./../rtos/InterfaceThread.h"

/* ****************************************************************************************
 * Using
 */  
using mcuf::Object;
using mcuf::Allocator;

/* ****************************************************************************************
 * Variable <Static>
 */

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
  System::sInterfaceKernel->kernelDelay(milliseconds);
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
  return;
}

/**
 * @brief 
 * 
 */
void Object::wait(void) const{
  System::sInterfaceKernel->kernelWait();
  return;
}

/**
 * @brief 
 * 
 * @param timeout 
 * @return true 
 * @return false 
 */
bool Object::wait(int timeout) const{
  return System::sInterfaceKernel->kernelWait(timeout);
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Object::yield(void) const{
  return Thread::sInterfaceThread->threadYield();
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Object::systemLock(void) const{
  return System::sInterfaceKernel->kernelLock();
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Object::systemUnlock(void) const{
  return System::sInterfaceKernel->kernelUnlock();
}

mcuf::Object& Object::getObject(void){
  return *this;
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
