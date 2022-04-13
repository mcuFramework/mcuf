/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#ifndef MCUF_CMSISRTOS2_DISABLE
#include "cmsis_rtos/rtx_os.h"
#endif 

#include "mcuf/lang/Threads.h"

/* ****************************************************************************************
 * Macro
 */  

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::Thread;
using mcuf::lang::Threads;
using mcuf::lang::ThreadPriority;
using mcuf::lang::ThreadState;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Threads object
 * 
 */
Threads::Threads(void){
  return;
}


/**
 * @brief 
 * 
 */
Threads::~Threads(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/**
 *
 */
uint32_t Threads::getThreadID(void){
  return reinterpret_cast<uint32_t>(osThreadGetId());
}

/**
 *
 */
const char* Threads::getName(uint32_t threadID){
  void* id = reinterpret_cast<void*>(threadID);
  return osThreadGetName(id);
}

/**
 *
 */
ThreadState Threads::getState(uint32_t threadID){
  void* id = reinterpret_cast<void*>(threadID);
  return static_cast<ThreadState>(osThreadGetState(id));
}

/**
 *
 */
uint32_t Threads::getCount(void){
  return osThreadGetCount();
}
  
/**
 *
 */
ThreadPriority Threads::getPriority(uint32_t threadID){
  void* id = reinterpret_cast<void*>(threadID);
  return static_cast<ThreadPriority>(osThreadGetPriority(id));
}
  
/**
 *
 */
void Threads::notify(uint32_t threadID){
  void* id = reinterpret_cast<void*>(threadID);
  osThreadFlagsSet(id, 0x00000001U);
}
  
/**
 *
 */
bool Threads::setPriority(uint32_t threadID, ThreadPriority priority){
  void* id = reinterpret_cast<void*>(threadID);
  if(osThreadSetPriority(id, static_cast<osPriority_t>(priority)) == osOK)
    return true;
  
  else
    return false;
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
