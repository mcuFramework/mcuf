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
#include "../hal/Timer.hpp"
#include "../io/PrintStream.hpp"
#include "../lang/Object.hpp"
#include "../lang/managerment/SystemComponent.hpp"
#include "../lang/managerment/MemoryManager.hpp"


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
class mcuf::lang::System final:
      public mcuf::lang::Object{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */
  public: static mcuf::lang::managerment::SystemComponent component;
  public: static mcuf::io::PrintStream out;

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */

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
   * Disconstruct.
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
  public: static void info(const char* path, const char* message);

  /**
   * 
   */
  public: static void init(void);

  /**
   * 
   */
  public: static mcuf::lang::managerment::MemoryManager* memoryManager(void);

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
};


/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_DB2618AE_F498_4792_900C_A4BD1DC2E35C */
