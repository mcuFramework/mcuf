/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_F7B1526F_354D_4CB2_A881_9E0684740E59
#define MCUF_F7B1526F_354D_4CB2_A881_9E0684740E59

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"
#include "mcuf/util/BlockPool.h"
#include "mcuf/util/TimerTask.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    class TimerScheduler;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::util::TimerScheduler extends mcuf::util::BlockPool implements 
  public mcuf::function::BiConsumer<mcuf::lang::Memory*, void*>{
    
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
    uint32_t mTickMilliSecond;
    
  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  public:

    /**
     * @brief Construct a new Timer Scheduler object
     * 
     * @param memory 
     */
    TimerScheduler(const mcuf::lang::Memory& memory);
    
    /**
     * @brief Destroy the Timer Scheduler object
     * 
     */
    ~TimerScheduler();
  
  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::function::BiConsumer<mcuf::lang::Memory*, void*>
   */
  public: 

    /**
     * @brief 
     * 
     * @param value 
     * @param attachment 
     */
    virtual void accept(mcuf::lang::Memory* value, void* attachment) override;  

  /* **************************************************************************************
   * Public Method 
   */
  public:

    /**
     * @brief Terminates this timer, discarding any currently scheduled tasks. Does not 
     *        interfere with a currently executing task (if it exists). Once a timer has 
     *        been terminated, its execution thread terminates gracefully, and no more 
     *        tasks may be scheduled on it. Note that calling this method from within the 
     *        run method of a timer task that was invoked by this timer absolutely 
     *        guarantees that the ongoing task execution is the last task execution that 
     *        will ever be performed by this timer.
     *    
     *        This method may be called repeatedly; the second and subsequent calls have no 
     *        effect.
     */
    void cancel(void);

    /**
     * @brief Removes all cancelled tasks from this timer's task queue. Calling this method 
     *        has no ffect on the behavior of the timer, but eliminates the references to the 
     *        cancelled tasks from the queue. If there are no external references to these 
     *        tasks, they become eligible for garbage collection.
     * 
     *        Most programs will have no need to call this method. It is designed for use by 
     *        the rare application that cancels a large number of tasks. Calling this method 
     *        trades time for space: the runtime of the method may be proportional to n + c 
     *        log n, where n is the number of tasks in the queue and c is the number of 
     *        cancelled tasks.
     * 
     *        Note that it is permissible to call this method from within a a task scheduled 
     *        on this timer.
     */
    void purge(void);

    /**
     * @brief Schedules the specified task for execution after the specified delay.
     * 
     * @param task task to be scheduled.
     * @param delay  delay in milliseconds before task is to be executed.
     * @return true successful.
     * @return false 
     */
    bool schedule(mcuf::util::TimerTask& task, uint32_t delay);

    /**
     * @brief 
     * 
     * @param task 
     * @param delay 
     * @param period 
     * @return true successful
     * @return false this task was already scheduled or cancelled.
     */
    bool scheduleAtFixedRate(mcuf::util::TimerTask& task, uint32_t delay, uint32_t period);

    /**
     * @brief 
     * 
     * @param milliSecont 
     */
    void tick(uint32_t milliSecont);

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
   * Private Method <Static Inline>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */
   
  /* **************************************************************************************
   * Private Method <Inline>
   */  
    
  /* **************************************************************************************
   * Private Method
   */  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_F7B1526F_354D_4CB2_A881_9E0684740E59 */
