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
#include "./../mcuf/package-info.h"
#include "./../sys/package-info.h"
#include "./../boot/package-info.h"

//-----------------------------------------------------------------------------------------
#include "./System.h"

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

using func::Runnable;
using mcuf::Maths;
using mcuf::Memory;
using mcuf::System;
using mcuf::CoreThread;
using mcuf::SystemRegister;
using mcuf::ThreadEvent;
using mcuf::Timer;

/* ****************************************************************************************
 * Global Operator
 */  

/* ****************************************************************************************
 * Static Variable
 */  
rtos::InterfaceKernel* System::sInterfaceKernel;
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
 * @return mcuf::InputStream& 
 */
mcuf::InputStreamBuffer& System::in(void){
  return *System::mSystemRegister->mInputStreamBuffer;
}

/**
 * @brief 
 * 
 * @return cli::PrintStream& 
 */
cli::PrintStream& System::out(void){
  return *System::mSystemRegister->mPrintStream;
}
/**
 * @brief 
 * 
 */
void System::initialize(void){
  if(System::mSystemRegister != nullptr)
    return;
  
  System::mSystemRegister = new SystemRegister();
  return;
}

/**
 * @brief 
 * 
 */
void System::setup(void){
  if(System::mSystemRegister == nullptr)
    return;
  
  Thread::setInterfaceThread(*System::mSystemRegister->mInterfaceThread);
  System::setInterfaceKernel(*System::mSystemRegister->mInterfaceKernel);
  Timer::setInterfaceTimer(*System::mSystemRegister->mInterfaceTimer);
  return;
}

/**
 * @brief 
 * 
 * @param userThread 
 */
void System::start(mcuf::Thread& userThread){
  System::sInterfaceKernel->kernelInitialize();
  

  
  
  System::mCoreThread 
    = new CoreThread(mcufCoreEcecutorTaskNumber, 
                     &userThread);
  
  System::mCoreThread->start();
  System::sInterfaceKernel->kernelStart();
  
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
 * @param runnable 
 * @return true 
 * @return false 
 */
void System::execute(func::Runnable& runnable){
  if(System::mCoreThread->execute(runnable) == false)
    runnable.run();
}

/**
 * @brief 
 * 
 * @param runnable 
 */
void System::tick(func::Runnable& runnable){

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

/**
 * @brief 執行idle是件
 * 
 */
void System::idleTask(void){
  System::mSystemRegister->mIdleTask.run();
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
/**
 * @brief 
 *
 */
void System::setInterfaceKernel(rtos::InterfaceKernel& interfacrKernel){
  System::sInterfaceKernel = &interfacrKernel;
  return;
}
 
/* ****************************************************************************************
 * End of file
 */ 
