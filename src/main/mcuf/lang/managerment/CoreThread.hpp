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
      class CoreThread;
    }
  }
}

/* ****************************************************************************************
 * Class Object
 */  
class mcuf::lang::managerment::CoreThread extends mcuf::lang::Thread{

  /* **************************************************************************************
   * Subclass
   */
  private: struct Attachment{
    mcuf::lang::Memory* stackMemory;
    mcuf::lang::Memory* taskMemory;
    mcuf::lang::Memory* timerTaskMemory;
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
  private: mcuf::util::Executor* mExecutor;
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

  /**
   *
   */
  public: static CoreThread create(mcuf::lang::Memory& memory, uint32_t executeTask, uint32_t timerTask);

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
