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
#include "mcuf\function\Consumer.hpp"
#include "mcuf\function\ConsumerEvent.hpp"
#include "mcuf\util\BlockPool.hpp"
#include "mcuf\util\Timer.hpp"
#include "mcuf\util\TimerTask.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    class TimerScheduler;
  }
}

/* ****************************************************************************************
 * Class TimerScheduler
 */  
class mcuf::util::TimerScheduler extends mcuf::util::BlockPool
      implements mcuf::util::Timer{

  /* **************************************************************************************
   * Subclass
   */
  
  public: class ConsumerClear;
  public: class ConsumerPurge;
  public: class ConsumerTick;

  friend ConsumerClear;
  friend ConsumerPurge;
  friend ConsumerTick;

  /* **************************************************************************************
   * Class ConsumerClear
   */
  public: class ConsumerClear extends mcuf::lang::Object
                implements mcuf::function::Consumer<mcuf::lang::Memory*>{

    public: ConsumerClear(void) = default;

    public: virtual void accept(mcuf::lang::Memory* t);
  };


  /* **************************************************************************************
   * Class ConsumerPurge
   */
  public: class ConsumerPurge extends mcuf::lang::Object
                implements mcuf::function::Consumer<mcuf::lang::Memory*>{

    private: TimerScheduler* base;
    private: uint32_t purge;

    public: ConsumerPurge(TimerScheduler* base){
      this->base = base;
      this->purge = 0;
    }

    public: virtual void accept(mcuf::lang::Memory* t);

    public: inline void clear(void);

    public: inline uint32_t get(void);
  };

  /* **************************************************************************************
   * Class ConsumerTick
   */
  public: class ConsumerTick extends mcuf::lang::Object
                implements mcuf::function::Consumer<mcuf::lang::Memory*>{

    private: TimerScheduler* base;
    private: uint32_t tickMilliSecond;

    public: ConsumerTick(TimerScheduler* base);

    public: virtual void accept(mcuf::lang::Memory* t);

    public: void setTickMilliSecond(uint32_t milliSecond);

    public: uint32_t getTickMilliSecond(void);
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
  private: ConsumerTick  consumerTick;
  private: ConsumerPurge consumerPurge;
  private: ConsumerClear consumerClear;

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
  public: TimerScheduler(const mcuf::lang::Memory& memory);
  
  
  /**
   * Destruct.
   */
  public: ~TimerScheduler();
  
  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
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
  public: virtual void cancel(void);
  
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
  public: virtual uint32_t purge(void);

  /**
   * Schedules the specified task for execution after the specified delay.
   *
   * @task task to be scheduled.
   * @delay delay in milliseconds before task is to be executed.
   * @return true successful, false if task was already scheduled or cancelled.
   */
  public: virtual bool schedule(mcuf::util::TimerTask& task, uint32_t delay);
  
  /**
   *
   * @task
   * @delay
   * @period
   * @return true successful
   */
  public: virtual bool scheduleAtFixedRate(mcuf::util::TimerTask& task, uint32_t delay, uint32_t period);

  /* **************************************************************************************
   * Public Method
   */

  /**
   * 
   */
  public: void tick(uint32_t milliSecont);

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


#endif/* MCUF_F7B1526F_354D_4CB2_A881_9E0684740E59 */
