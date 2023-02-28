/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  

#include <string.h>

//-----------------------------------------------------------------------------------------
#include "./mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "./Maths.h"
#include "./System.h"
#include "./Thread.h"
#include "./../rtos/InterfaceThread.h"

/* ****************************************************************************************
 * Macro
 */  

/* ****************************************************************************************
 * Using
 */  
using mcuf::Memory;
using mcuf::Thread;
using mcuf::ThreadPriority;
using mcuf::ThreadState;

/* ****************************************************************************************
 * Variable <Static>
 */
mcuf::rtos::InterfaceThread* Thread::sInterfaceThread;

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/**
 * @brief Construct a new Thread object
 * 
 */
Thread::Thread(uint32_t stackSize) : Memory(stackSize),
mHandlerMemroy(Thread::sInterfaceThread->threadGetHandlerSize()){
  return;
}
  
/**
 * @brief Construct a new Thread object
 * 
 */
Thread::Thread(const mcuf::Data& stackMemory) : Memory(stackMemory),
mHandlerMemroy(Thread::sInterfaceThread->threadGetHandlerSize()){
  return;
}

/**
 * @brief Destroy the Thread:: Thread object
 * 
 */
Thread::~Thread(void){
  if(this->isActive())
    System::error(__CLASSPATH__, ErrorCode::NULL_POINTER);
  
  return;
}

/* ****************************************************************************************
 * Public Method <Static>
 */

/**
 * @brief 取得當前執行序ID;
 * 
 * @return uint32_t 
 */
uint32_t Thread::getThreadID(void){
  return Thread::sInterfaceThread->threadGetCurrentID();
}

/**
 * @brief 喚醒指定執行序
 * 
 */
void Thread::notify(uint32_t thread){
  Thread::sInterfaceThread->threadNotify(thread);
  return;
}

/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

/**
 * @brief 
 * 
 * @return uint32_t 
 */
uint32_t Thread::getID(void) const{
  return Thread::sInterfaceThread->threadGetID(this->mHandlerMemroy);
}

/**
 * @brief 
 * 
 * @param name 
 */
void Thread::setThreadName(const char* name){
  Thread::sInterfaceThread->threadSetName(this->mHandlerMemroy, name);
  return;
}

/**
 * @brief 
 * 
 * @return const char* 
 */
const char* Thread::getThreadName(void) const{
  return Thread::sInterfaceThread->threadGetName(this->mHandlerMemroy);
}

/**
 * @brief 
 * 
 * @return ThreadPriority 
 */
ThreadPriority Thread::getPriority(void) const{
  return Thread::sInterfaceThread->threadGetPriority(this->mHandlerMemroy);
}

/**
 * @brief 
 * 
 * @return ThreadState 
 */
ThreadState Thread::getState(void) const{
  return Thread::sInterfaceThread->threadGetState(this->mHandlerMemroy);
}

/**
 * @brief 
 * 
 * @return uint32_t 
 */
int Thread::getStackSize(void) const{
  return Thread::sInterfaceThread->threadGetStackSize(this->mHandlerMemroy);
}

/**
 * @brief 
 * 
 */
void Thread::notify(void){
  Thread::sInterfaceThread->threadNotify(this->mHandlerMemroy);
  return;
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Thread::start(void){
  return this->start(ThreadPriority::NORMAL);
}

/**
 * @brief 
 * 
 * @param priority 
 * @return true 
 * @return false 
 */
bool Thread::start(ThreadPriority priority){
  if(this->isActive())
    return false;
  
  return Thread::sInterfaceThread->threatStart(this->mHandlerMemroy, priority, *this, *this);
}

/**
 * @brief 
 * 
 * @param priority 
 * @return true 
 * @return false 
 */
bool Thread::setPriority(ThreadPriority priority){
  return Thread::sInterfaceThread->threadSetPriority(*this, priority);
}  

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool Thread::isActive(void){
  ThreadState state = this->getState();
  
  switch(state){
    case ThreadState::INACTIVE:
    case ThreadState::ERROR:
      return false;
    
    case ThreadState::BLOCKED:
    case ThreadState::READY:
    case ThreadState::RUNNING:
    case ThreadState::TERMINATED:
      return true;
      
  }
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
 * Private Method <Static>
 */

/**
 * @brief Set the Interface Thread object
 * 
 * @param interfaceThread 
 */
void Thread::setInterfaceThread(mcuf::rtos::InterfaceThread& interfaceThread){
  Thread::sInterfaceThread = &interfaceThread;
  return;
}

/* ****************************************************************************************
 * Private Method
 */

/* ****************************************************************************************
 * End of file
 */ 
