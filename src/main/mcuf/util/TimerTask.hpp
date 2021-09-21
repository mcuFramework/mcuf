/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_B2F9076E_24AC_4E60_8CB6_CF308D4BA07B
#define MCUF_B2F9076E_24AC_4E60_8CB6_CF308D4BA07B

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/function/Runnable.hpp"
#include "mcuf/lang/Object.hpp"
  

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    class Timer;
    class TimerTask;
  }
}



/* ****************************************************************************************
 * Class TimerTask
 */  
class mcuf::util::TimerTask extends mcuf::lang::Object
      implements mcuf::function::Runnable{
  
  /* **************************************************************************************
   * Subclass
   */
  public: class Viewer;

  /* **************************************************************************************
   * Variable <Public>
   */
  public: friend class Timer;
  public: friend class Viewer;

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  private: uint32_t delay;
  private: uint32_t period;

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
  public: TimerTask(void) = default;
    
  /**
   * Disconstruct.
   */
  public: virtual ~TimerTask(void) = default;

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
   * Public Method
   */
  
  /**
   * Cancels this timer task. If the task has been scheduled for one-time execution and has 
   * not yet run, or has not yet been scheduled, it will never run. If the task has been 
   * scheduled for repeated execution, it will never run again. (If the task is running 
   * when this call occurs, the task will run to completion, but will never run again.)
   *
   * Note that calling this method from within the run method of a repeating timer task
   *  absolutely guarantees that the timer task will not run again.
   *
   * This method may be called repeatedly; the second and subsequent calls have no effect.
   *
   * @return true if this task is scheduled for one-time execution and has not yet run, 
   *         or this task is scheduled for repeated execution. Returns false if the task 
   *         was scheduled for one-time execution and has already run, or if the task was 
   *         never scheduled, or if the task was already cancelled. (Loosely speaking, this 
   *         method returns true if it prevents one or more scheduled executions from taking 
   *         place.)
   */
  public: bool cancel(void);


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



/* ****************************************************************************************
 * Class TimerTask::Viewer
 */  
class mcuf::util::TimerTask::Viewer:
      mcuf::lang::Object{

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
   * 
   */
  private: Viewer(void) = default;
  
  /**
   * 
   */
  public: virtual ~Viewer(void) = default;
  
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
   * Public Method
   */

  /**
   * 
   */
  public: static bool isTimerTaskRunning(TimerTask& timerTask);

  /**
   * 
   */
  public: static bool subTimerTaskDelay(TimerTask& timerTask, uint32_t milliSecond);

  /**
   * 
   */
  public: static uint32_t getTimerTaskDelay(TimerTask& timerTask);
  
  /**
   * 
   */
  public: static uint32_t getTimerTaskPeriod(TimerTask& timerTask);
  /**
   * 
   */  
  public: static void setTimerTaskDelay(TimerTask& timerTask, uint32_t delay);
    
  /**
   * 
   */
  public: static void setTimerTaskPeriod(TimerTask& timerTask, uint32_t period);
  
  /**
   * 
   */
  public: static void setTimerTaskDelayPeriod(TimerTask& timerTask, uint32_t delay, uint32_t period);


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


#endif/* MCUF_B2F9076E_24AC_4E60_8CB6_CF308D4BA07B */
