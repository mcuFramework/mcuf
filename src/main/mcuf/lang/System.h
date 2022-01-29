/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_DB2618AE_F498_4792_900C_A4BD1DC2E35C
#define MCUF_DB2618AE_F498_4792_900C_A4BD1DC2E35C

/* ****************************************************************************************
 * Include
 */
#include "mcuf_base.h"
#include "mcuf/lang/Error.h"
#include "mcuf/lang/Object.h"
#include "mcuf/lang/Thread.h"
#include "mcuf/lang/managerment/CoreThread.h"


/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class System;
  }
}



/**
 * Class System
 */
class mcuf::lang::System final extends mcuf::lang::Object{

  /* **************************************************************************************
   * Subclass
   */


  /* **************************************************************************************
   * Variable <Public>
   */
  
  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  private: static void (*mErrorHandler)(const void* address, Error::Code code);
  private: static mcuf::lang::managerment::CoreThread* mCoreThread;

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

  /**
   * Construct.
   */
  private: System(void) = default;

  /**
   * Destruct.
   */
  public: virtual ~System(void) = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  public: static void reboot(void);

  /**
   *
   */
  public: static void start(mcuf::lang::Thread* userThread);

  /**
   * 
   */
  public: static void error(const void* address, Error::Code code);
  
  /**
   *
   */
  public: static void registorErrorHandler(void (*handler)(const void* address, Error::Code code));
  
  /* **************************************************************************************
   * Public Method <Inline Static>
   */
   
  /**
   *
   */
  public: inline static bool execute(mcuf::function::Runnable& runnable){
    return System::mCoreThread->mExecutor.execute(&runnable);
  }

  /**
   * Schedules the specified task for execution after the specified delay.
   *
   * @task task to be scheduled.
   * @delay delay in milliseconds before task is to be executed.
   * @return true successful, false if task was already scheduled or cancelled.
   */
  public: inline static bool schedule(mcuf::util::TimerTask& task, uint32_t delay){
    return System::mCoreThread->mTimerScheduler.schedule(task, delay);
  }
  
  /**
   *
   * @task
   * @delay
   * @period
   * @return true successful
   */
  public: inline static bool scheduleAtFixedRate(mcuf::util::TimerTask& task, uint32_t delay, uint32_t period){
    return System::mCoreThread->mTimerScheduler.scheduleAtFixedRate(task, delay, period);
  }

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method
   */

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */
  
  /* **************************************************************************************
   * Private Method <Override>
   */
   
  /* **************************************************************************************
   * Private Method
   */  
  
};


/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_DB2618AE_F498_4792_900C_A4BD1DC2E35C */
