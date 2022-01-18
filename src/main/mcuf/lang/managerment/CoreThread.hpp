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
#include "mcuf/lang/Memory.hpp"
#include "mcuf/lang/ThreadEvent.hpp"
#include "mcuf/util/Executor.hpp"
#include "mcuf/util/TimerScheduler.hpp"

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
 * Class Object
 */  
class mcuf::lang::managerment::CoreThread extends mcuf::lang::Thread{
  friend mcuf::lang::System;
  
  /* **************************************************************************************
   * Subclass
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
  private: mcuf::lang::Thread* mUserThread;
  private: mcuf::util::Executor mExecutor;
  private: mcuf::util::TimerScheduler mTimerScheduler;
  private: uint64_t mTimerMemory[4];
  private: uint32_t mTimerTick;
  private: void* mTimerID;
  private: bool mStart;

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
  private: CoreThread(Attachment& attachment);

  /**
   * Destruct.
   */
  public: virtual ~CoreThread(void) = default;

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
   
  /**
   *
   */
  public: void run(void) override;

  /* **************************************************************************************
   * Public Method
   */
   
  /**
   *
   */
  public: bool execute(mcuf::function::Runnable& runnable);

  /**
   *
   */
  public: void stop(void);

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
  
  /**
   *
   */
   private: static void entryPoint(void* attachment);

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
