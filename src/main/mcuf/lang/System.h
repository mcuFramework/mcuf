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

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::lang::System final extends mcuf::lang::Object{

  /* **************************************************************************************
   * Variable <Public>
   */
  
  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  private: 
    static void (*mErrorHandler)(const void* address, Error::Code code);
    static mcuf::lang::managerment::CoreThread* mCoreThread;
    static const uint32_t mSystemTimerClock;

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  private:
  
    /**
     * @brief Construct a new System object
     * 
     */
    System(void) = default;

    /**
     * @brief Destroy the System object
     * 
     */
    virtual ~System(void) = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */
  public:

    /**
     * @brief 
     * 
     */
    static void reboot(void);

    /**
     * @brief 
     * 
     * @param userThread 
     */
    static void start(mcuf::lang::Thread* userThread);

    /**
     * @brief 
     * 
     * @param address 
     * @param code 
     */
    static void error(const void* address, Error::Code code);
    
    /**
     * @brief 
     * 
     * @param handler 
     */
    static void registorErrorHandler(void (*handler)(const void* address, Error::Code code));
    
    /**
     * @brief Get the System Timer Clock object
     * 
     * @return uint32_t 
     */
    static uint32_t getSystemTimerClock(void);
    
    /**
     * @brief Get the Core Clock object
     * 
     * @return uint32_t 
     */
    static uint32_t getCoreClock(void);
  
  /* **************************************************************************************
   * Public Method <Inline Static>
   */
  public: 

    /**
     * @brief 
     * 
     * @param runnable 
     * @return true 
     * @return false 
     */
    inline static bool execute(mcuf::function::Runnable& runnable){
      return System::mCoreThread->mExecutor.execute(&runnable);
    }

    /**
     * @brief Schedules the specified task for execution after the specified delay.
     * 
     * @param task to be scheduled.
     * @param delay in milliseconds before task is to be executed.
     * @return true successful.
     * @return false false if task was already scheduled or cancelled.
     */
    inline static bool schedule(mcuf::util::TimerTask& task, uint32_t delay){
      return System::mCoreThread->mTimerScheduler.schedule(task, delay);
    }
    
    /**
     *
     * @task
     * @delay
     * @period
     * @return true successful
     */
    inline static bool scheduleAtFixedRate(mcuf::util::TimerTask& task, 
                                          uint32_t delay, 
                                          uint32_t period){
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
