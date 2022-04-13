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

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"
#include "mcuf/function/Runnable.h"
#include "mcuf/lang/Object.h"
  

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
 * Class/Interface/Struct
 */  
class mcuf::util::TimerTask extends mcuf::lang::Object implements 
  public mcuf::function::Runnable{

  /* **************************************************************************************
   * Variable <Public>
   */
  public: friend class Timer;

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  private:
    uint32_t mHandler[8];
    void* mTimerID;


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
     * @brief Construct a new Timer Task object
     * 
     */
    TimerTask(void);
    
    /**
     * @brief Destroy the Timer Task object
     * 
     */
    virtual ~TimerTask(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Inline>
   */
  
  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method
   */
  public:

    /**
     * @brief Cancels this timer task. If the task has been scheduled for one-time execution 
     *        and has not yet run, or has not yet been scheduled, it will never run. If the 
     *        task has been scheduled for repeated execution, it will never run again. (If 
     *        the task is running when this call occurs, the task will run to completion, 
     *        but will never run again.)
     *        
     *        Note that calling this method from within the run method of a repeating timer 
     *        task absolutely guarantees that the timer task will not run again.
     * 
     *        This method may be called repeatedly; the second and subsequent calls have no 
     *        effect.
     * 
     * @return true 
     * @return false 
     */
    bool cancel(void);

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool isRunning(void);
  
  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Inline>
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
   * Private Method <Inline>
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


#endif /* MCUF_B2F9076E_24AC_4E60_8CB6_CF308D4BA07B */
