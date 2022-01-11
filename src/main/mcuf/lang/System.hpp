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

  /* **************************************************************************************
   * Variable <Public>
   */
  

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  private: static mcuf::lang::Thread* mThread;
  
  

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

  /**
   *
   */
  public: static bool start(mcuf::lang::Thread& thread);

  /**
   * 
   */
  public: static void throwSystemError(const char* path, const char* message);

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
  
  /**
   *
   */
  private: static void entryPoint(void* attachment);  
  
  /**
   *
   */
  private: static void initThread(mcuf::lang::Thread& thread);
  
};


/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_DB2618AE_F498_4792_900C_A4BD1DC2E35C */
