/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_C68B6E70_0FC9_44C2_A6E1_2B07FFBB0175
#define MCUF_C68B6E70_0FC9_44C2_A6E1_2B07FFBB0175

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/lang/Object.hpp"
#include "mcuf/util/TimerTask.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    interface Timer;
  }
}



/* ****************************************************************************************
 * Class Timer
 */  
interface mcuf::util::Timer{

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
  
  /**
   * Terminates this timer, discarding any currently scheduled tasks. Does not interfere 
   * with a currently executing task (if it exists). Once a timer has been terminated, 
   * its execution thread terminates gracefully, and no more tasks may be scheduled on it.
   * Note that calling this method from within the run method of a timer task that was 
   * invoked by this timer absolutely guarantees that the ongoing task execution is the last 
   * task execution that will ever be performed by this timer.
   *
   * This method may be called repeatedly; the second and subsequent calls have no effect.
   */
  public: virtual void cancel() = 0;
  
  /**
   * Removes all cancelled tasks from this timer's task queue. Calling this method has no 
   * effect on the behavior of the timer, but eliminates the references to the cancelled 
   * tasks from the queue. If there are no external references to these tasks, they become 
   * eligible for garbage collection.
   *
   * Most programs will have no need to call this method. It is designed for use by the rare 
   * application that cancels a large number of tasks. Calling this method trades time for 
   * space: the runtime of the method may be proportional to n + c log n, where n is the 
   * number of tasks in the queue and c is the number of cancelled tasks.
   * 
   * Note that it is permissible to call this method from within a a task scheduled on this 
   * timer.
   * 
   * @return the number of tasks removed from the queue.
   */
  public: virtual uint32_t purge() = 0;
  
  /**
   * Schedules the specified task for execution after the specified delay.
   *
   * @task task to be scheduled.
   * @delay delay in milliseconds before task is to be executed.
   * @return true successful, false if task was already scheduled or cancelled.
   */
  public: virtual bool schedule(mcuf::util::TimerTask& task, uint32_t delay) = 0;
  
  /**
   * 
   */
  public: virtual bool scheduleAtFixedRate(mcuf::util::TimerTask& task, uint32_t delay, uint32_t period) = 0;
  
  
  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

  /**
   * Construct.
   */
  public: Timer(void) = default;
  
  /**
   * Disconstruct.
   */
  public: virtual ~Timer(void) = default;
	
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


#endif/* MCUF_C68B6E70_0FC9_44C2_A6E1_2B07FFBB0175 */
