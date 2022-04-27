/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  

#include <stdlib.h>

//-----------------------------------------------------------------------------------------

#include "cmsis_rtos/rtx_os.h"

#include "mcuf/lang/Math.h"
#include "mcuf/lang/System.h"
#include "mcuf/lang/ThreadEvent.h"
#include "mcuf/lang/managerment/CoreThread.h"
#include "mcuf/util/Timer.h"
#include "mcuf/util/Stacker.h"

/* ****************************************************************************************
 * Namespace
 */  

/* ****************************************************************************************
 * Extern
 */  
extern unsigned int SystemCoreClockHz;

extern const uint32_t mcufCoreStackMemorySize;
extern const uint32_t mcufCoreEcecutorTaskNumber;
extern const uint32_t mcufTickBaseTime;
extern const uint32_t mcufTickTaskNumber;

/* ****************************************************************************************
 * Using
 */  

using mcuf::function::Runnable;
using mcuf::lang::Math;
using mcuf::lang::Memory;
using mcuf::lang::System;
using mcuf::lang::managerment::CoreTick;
using mcuf::lang::managerment::CoreThread;
using mcuf::lang::managerment::SystemRegister;
using mcuf::lang::ThreadEvent;
using mcuf::util::Stacker;
using mcuf::util::Timer;

/* ****************************************************************************************
 * Global Operator
 */  

/* ****************************************************************************************
 * Static Variable
 */  

SystemRegister* System::mSystemRegister = nullptr;
CoreThread* System::mCoreThread = nullptr;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new System object
 * 
 */
System::System(void){
  return;
}

/**
 * @brief Destroy the System object
 * 
 */
System::~System(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/**
 * @brief 
 * 
 */
void System::reboot(void){
  System::mSystemRegister->mSystemReset();
  return;
}

/**
 * @brief 
 * 
 * @return mcuf::io::InputStream& 
 */
mcuf::io::InputStreamBuffer& System::in(void){
  return *System::mSystemRegister->mInputStreamBuffer;
}

/**
 * @brief 
 * 
 * @return mcuf::io::PrintStream& 
 */
mcuf::io::PrintStream& System::out(void){
  return *System::mSystemRegister->mPrintStream;
}
/**
 * @brief 
 * 
 */
void System::initialize(void){
  if(System::mSystemRegister != nullptr)
    return;
  
  osKernelInitialize();
  System::mSystemRegister = new SystemRegister();
}

/**
 * @brief 
 * 
 * @param userThread 
 */
void System::start(mcuf::lang::Thread& userThread){

  System::mCoreThread 
    = new CoreThread(mcufCoreStackMemorySize, mcufCoreEcecutorTaskNumber, 
                     mcufTickTaskNumber, mcufTickBaseTime, 
                     &userThread);
  
  System::mCoreThread->start();
  osKernelStart();
  
  delete System::mCoreThread;
  System::mCoreThread = nullptr;
  return;
}

/**
 * 
 */
void System::error(const void* address, ErrorCode code){
  bool result = false;
  if(System::mSystemRegister->mErrorCodeHandler){
    result = System::mSystemRegister->mErrorCodeHandler(address, code);
  }
  
  if(result)
    return;
  
  while(1);
}

/**
 * @brief 
 * 
 * @return SystemRegister 
 */
SystemRegister& System::getRegister(void){
  return *System::mSystemRegister;
}

/**
 *
 */
uint32_t System::getCoreClock(void){
  return SystemCoreClockHz;
}

/**
 * @brief 
 * 
 * @param times 
 */
void System::lowerDelay(uint32_t times){
#pragma clang optimize off
  while(times){
    --times;
  }
#pragma clang optimize on
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
