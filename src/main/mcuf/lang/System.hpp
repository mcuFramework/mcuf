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
#include <stdio.h>

#include "../hal/Timer.hpp"
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
class mcuf::lang::System:
      public mcuf::lang::Object{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */
  public: static mcuf::lang::managerment::SystemComponent component;

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
  public: static void info(const char* path, const char* message){
    printf("INFO: %s - %s\n", path, message);
    return;
  }

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
  public: static void throwSystemError(const char* path, const char* message){
    printf("ERROR: %s - %s\n", path, message);
    while(1);
  }

  /**
   * 
   */
  public: static void throwSystemWarning(const char* path, const char* message){
    printf("WARNING: %s - %s\n", path, message);
    return;
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
