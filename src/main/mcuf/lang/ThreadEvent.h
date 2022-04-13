/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_C2842937_BF83_418E_9A72_EBE18B10E733
#define MCUF_C2842937_BF83_418E_9A72_EBE18B10E733

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"
#include "mcuf/function/Runnable.h"
#include "mcuf/lang/Thread.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class ThreadEvent;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */    
class mcuf::lang::ThreadEvent extends mcuf::lang::Thread{

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
    mcuf::function::Runnable* mRunnable;

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
     * @brief Construct a new Thread Event object
     * 
     * @param memory 
     * @param runnable 
     */
    ThreadEvent(const mcuf::lang::Memory& memory, mcuf::function::Runnable& runnable);

    /**
     * @brief Construct a new Thread Event object
     * 
     * @param memory 
     * @param name 
     * @param runnable 
     */
    ThreadEvent(uint32_t stackSize, mcuf::function::Runnable& runnable);

    /**
     * @brief Destroy the Thread Event object
     * 
     */
    virtual ~ThreadEvent(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::lang::Thread
   */
  public: 

    /**
     * @brief 
     * 
     */
    virtual void run(void) override;

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

#endif /* MCUF_C2842937_BF83_418E_9A72_EBE18B10E733 */
