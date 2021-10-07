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

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    namespace managerment{
      class ExecutorManager;
    }
  }
}

/* ****************************************************************************************
 * Class Object
 */  
class mcuf::lang::managerment::ExecutorManager extends mcuf::util::Executor
  implements mcuf::function::Runnable{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */
  public: mcuf::lang::ThreadEvent mThreadEvent;

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
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
  public: ExecutorManager(mcuf::lang::Memory& memory);

  /**
   * Destruct.
   */
  public: virtual ~ExecutorManager(void) = default;

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
