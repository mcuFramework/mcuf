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

//-----------------------------------------------------------------------------------------
#include "./mcuf_base.h"
#include "./TimerTask.h"
#include "./rtos/InterfaceTimer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  class Timer;
  class System;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
class mcuf::Timer extends mcuf::Object{
  
  friend mcuf::System;
  friend mcuf::TimerTask;
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
    static mcuf::rtos::InterfaceTimer* sInterfaceTimer;
    
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
     * @brief Construct a new Timer Scheduler object
     * 
     * @param memory 
     */
    Timer(void);
    
  public:  
    /**
     * @brief Destroy the Timer Scheduler object
     * 
     */
    virtual ~Timer(void) override;
  
  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */
  public:

    /**
     * @brief Schedules the specified task for execution after the specified delay.
     * 
     * @param task task to be scheduled.
     * @param delay  delay in milliseconds before task is to be executed.
     * @return true successful.
     * @return false 
     */
    static bool schedule(mcuf::TimerTask& task, uint32_t delay);

    /**
     * @brief 
     * 
     * @param task 
     * @param delay 
     * @param period 
     * @return true successful
     * @return false this task was already scheduled or cancelled.
     */
    static bool scheduleAtFixedRate(mcuf::TimerTask& task, uint32_t delay);
    
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
  private:

    /**
     * @brief Set the Interface Timer object
     * 
     * @param imterfaceTimer 
     */
    static void setInterfaceTimer(mcuf::rtos::InterfaceTimer& interfaceTimer);

    /**
     * @brief 
     * 
     * @param attachment 
     */
    static void entryPoint(void* attachment);   
  
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
  private:
    /**
     *
     */
    static bool schedule(mcuf::TimerTask& task, uint32_t delay, bool mode); 

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_F7B1526F_354D_4CB2_A881_9E0684740E59 */
