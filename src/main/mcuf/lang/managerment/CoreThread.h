/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_BB9B7C70_E040_4995_A1F3_1855850093BD
#define MCUF_BB9B7C70_E040_4995_A1F3_1855850093BD

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"
#include "mcuf/lang/Memory.h"
#include "mcuf/lang/ThreadEvent.h"
#include "mcuf/util/Executor.h"
#include "mcuf/util/TimerScheduler.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class System;
    namespace managerment{
      class CoreThread;
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::lang::managerment::CoreThread extends mcuf::lang::Thread{
  friend mcuf::lang::System;
  
  /* **************************************************************************************
   * Struct Attachment
   */
  private: struct Attachment{
    mcuf::lang::Memory* stack;
    mcuf::lang::Memory* executor;
    mcuf::lang::Memory* timer;
    mcuf::lang::Thread* userThread;
    uint32_t timerTick;
  };

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
    mcuf::lang::Thread* mUserThread;
    mcuf::util::Executor mExecutor;
    mcuf::util::TimerScheduler mTimerScheduler;
    uint64_t mTimerMemory[4];
    uint32_t mTimerTick;
    void* mTimerID;
    bool mStart;

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
     * @brief Construct a new Core Thread object
     * 
     * @param attachment 
     */
    CoreThread(const Attachment& attachment);

  public: 

    /**
     * @brief Destroy the Core Thread object
     * 
     */
    virtual ~CoreThread(void) = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */
  
  /* **************************************************************************************
   * Public Method <Override> - mcuf::function::Runnable
   */
  public: 
  
    /**
     * @brief 
     * 
     */
    void run(void) override;

  /* **************************************************************************************
   * Public Method
   */
  public: 
  
    /**
     * @brief 
     * 
     * @param runnable 
     * @return true 
     * @return false 
     */
    bool execute(mcuf::function::Runnable& runnable);

    /**
     * @brief 
     * 
     */
    void stop(void);

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
   private: 
   
    /**
      * @brief 
      * 
      * @param attachment 
      */
    static void entryPoint(void* attachment);

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

#endif/* MCUF_BB9B7C70_E040_4995_A1F3_1855850093BD */
