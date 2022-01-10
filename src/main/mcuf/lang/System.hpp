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
#include "mcuf/io/PrintStream.hpp"
#include "mcuf/lang/Object.hpp"
#include "mcuf/lang/Thread.hpp"
#include "mcuf/lang/managerment/TimerManager.hpp"
#include "mcuf/lang/managerment/StackerManager.hpp"
#include "mcuf/lang/managerment/ExecutorManager.hpp"


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
  private: static mcuf::lang::managerment::StackerManager mStackerManager;
  
  private: static mcuf::io::PrintStream* mPrintStream;
  private: static mcuf::lang::managerment::ExecutorManager* mExecutorManager;
  private: static mcuf::lang::managerment::TimerManager* mTimerManager;
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
  public: static mcuf::lang::Memory allocMemory(size_t size);

  /**
   * 
   */
  public: static void* allocPointer(size_t size);

  /**
   *
   */
  public: static bool execute(mcuf::function::Runnable& runnable);

  /**
   * 
   */
  public: static void freeMemory(mcuf::lang::Memory& memory);

  /**
   * 
   */
  public: static void freePointer(void* pointer);

  /**
   * 
   */
  public: static void freePointer(void* pointer, size_t size);

  /**
   *
   */
  public: static mcuf::util::Timer& getTimer(void);

  /**
   * 
   */
  public: static void info(const char* path, const char* message);
  
  /**
   *
   */
  public: static mcuf::io::PrintStream& out(void);
  
  /**
   *
   */
  public: static bool start(mcuf::lang::Thread& thread, mcuf::io::OutputStream* outputStream);

  /**
   * 
   */
  public: static void throwSystemError(const char* path, const char* message);

  /**
   * 
   */
  public: static void throwSystemWarning(const char* path, const char* message);

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
  private: static void initMemoryManager(void);
  
  /**
   *
   */
  private: static void initPrintStream(mcuf::io::OutputStream* outputStream);
  
  /**
   *
   */
  private: static void initThread(mcuf::lang::Thread& thread);
  
  /**
   *
   */
  private: static void initTimer(void);
  
  /**
   *
   */
  private: static void initExecutor(void);   
};


/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_DB2618AE_F498_4792_900C_A4BD1DC2E35C */
