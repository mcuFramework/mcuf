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
#include "mcuf/util/Timer.h"

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
    bool mStart;
    bool mOnWait;

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
    CoreThread(uint32_t stackSize, uint32_t executeQueue, mcuf::lang::Thread* userThread);

  public: 

    /**
     * @brief Destroy the Core Thread object
     * 
     */
    virtual ~CoreThread(void) override;

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

#endif /* MCUF_BB9B7C70_E040_4995_A1F3_1855850093BD */
