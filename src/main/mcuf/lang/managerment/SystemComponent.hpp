/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_E1AC23E1_8083_4962_A2F8_4FCBBA37F659
#define MCUF_E1AC23E1_8083_4962_A2F8_4FCBBA37F659

/* ****************************************************************************************
 * Include
 */  
#include "../../io/OutputStream.hpp"
#include "../../hal/Timer.hpp"
#include "../../lang/Object.hpp"
#include "../../lang/managerment/MemoryManager.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class System;

    namespace managerment{
      class SystemComponent;
    }
  }
}



/* ****************************************************************************************
 * Class SystemComponent
 */  
class mcuf::lang::managerment::SystemComponent :
      public mcuf::lang::Object{
      

  friend mcuf::lang::System;

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
  private: bool locked = false;
  
  private: mcuf::io::OutputStream* mOutputString;
  private: mcuf::lang::managerment::MemoryManager* mMemoryManager;
  private: mcuf::hal::Timer* mTimer;

   

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
  public: SystemComponent(void) = default;

  /**
   * Disconstruct.
   */
  public: virtual ~SystemComponent(void) = default;

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
   * Public Method
   */

  /**
   * 
   */
  public: bool memoryManager(mcuf::lang::managerment::MemoryManager* m);

  /**
   * 
   */
  public: mcuf::lang::managerment::MemoryManager* memoryManager(void);

  /**
   * 
   */
  public: bool outputString(mcuf::io::OutputStream* o);

  /**
   * 
   */
  public: mcuf::io::OutputStream* outputString(void);

  /**
   * 
   */
  public: bool timer(mcuf::hal::Timer* t);

  /**
   * 
   */
  public: mcuf::hal::Timer* timer(void);

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /**
   * 
   */
  protected: void lock(void);

  /**
   * 
   */
  protected: void unlock(void);

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


#endif/* MCUF_E1AC23E1_8083_4962_A2F8_4FCBBA37F659 */
