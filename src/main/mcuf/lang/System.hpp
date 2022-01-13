/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_DB2618AE_F498_4792_900C_A4BD1DC2E35C
#define MCUF_DB2618AE_F498_4792_900C_A4BD1DC2E35C

/* ****************************************************************************************
 * Include
 */
#include "mcuf_base.h"
#include "mcuf/lang/Error.hpp"
#include "mcuf/lang/Object.hpp"
#include "mcuf/lang/Thread.hpp"


/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class System;
  }
}



/**
 * Class System
 */
class mcuf::lang::System final extends mcuf::lang::Object{

  /* **************************************************************************************
   * Subclass
   */
  public: struct Attachment{
    mcuf::function::Runnable* coreThread;
    mcuf::lang::Memory* coreThreadMemory;
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
  private: static mcuf::lang::Thread* mCoreThread;

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
  private: System(void) = default;

  /**
   * Destruct.
   */
  public: virtual ~System(void) = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  public: static void reboot(void);

  /**
   *
   */
  public: static bool start(Attachment& attachment);

  /**
   * 
   */
  public: static void error(const void* address, Error::Code code);
  
  /* **************************************************************************************
   * Public Method <Inline Static>
   */
   
  /**
   *
   */
  public: inline static mcuf::lang::Thread* getSystemThread(void){
    return System::mCoreThread;
  }

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
  
  /**
   *
   */
  private: static bool initCore(Attachment& attachment);  
  
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

#endif/* MCUF_DB2618AE_F498_4792_900C_A4BD1DC2E35C */
