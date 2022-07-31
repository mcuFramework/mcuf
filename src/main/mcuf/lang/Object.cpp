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
#include "mcuf/lang/Object.h"
#include "mcuf/lang/System.h"

 
/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::Object;
using mcuf::lang::Allocator;

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
  System::sInterfaceKernel->delay(milliseconds);
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
  System::sInterfaceKernel->wait();
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
  return System::sInterfaceKernel->wait(timeout);
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Object::yield(void) const{
  return System::sInterfaceKernel->yield();
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Object::systemLock(void) const{
  return System::sInterfaceKernel->systemLock();
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Object::systemUnlock(void) const{
  return System::sInterfaceKernel->systemUnlock();
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
