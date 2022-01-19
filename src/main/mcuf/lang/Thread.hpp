/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_AC7E7A3E_E6D3_4355_B4DE_6B28DF198293
#define MCUF_AC7E7A3E_E6D3_4355_B4DE_6B28DF198293

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"
#include "mcuf/function/Runnable.hpp"
#include "mcuf/lang/Memory.hpp"
#include "mcuf/lang/Object.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class Thread;
    class System;
  }
}

/* ****************************************************************************************
 * Class Object
 */  
abstracts class mcuf::lang::Thread extends mcuf::lang::Memory
  implements mcuf::function::Runnable{

  friend System;
  /* **************************************************************************************
   * Subclass
   */
  public: enum Priority{
    PRIORITY_LOW            =  8,         ///< PRIORITY_: low
    PRIORITY_LOW1           =  8+1,       ///< PRIORITY_: low + 1
    PRIORITY_LOW2           =  8+2,       ///< PRIORITY_: low + 2
    PRIORITY_LOW3           =  8+3,       ///< PRIORITY_: low + 3
    PRIORITY_LOW4           =  8+4,       ///< PRIORITY_: low + 4
    PRIORITY_LOW5           =  8+5,       ///< PRIORITY_: low + 5
    PRIORITY_LOW6           =  8+6,       ///< PRIORITY_: low + 6
    PRIORITY_LOW7           =  8+7,       ///< PRIORITY_: low + 7
    PRIORITY_BELOW_NORMAL   = 16,         ///< PRIORITY_: below normal
    PRIORITY_BELOW_NORMAL1  = 16+1,       ///< PRIORITY_: below normal + 1
    PRIORITY_BELOW_NORMAL2  = 16+2,       ///< PRIORITY_: below normal + 2
    PRIORITY_BELOW_NORMAL3  = 16+3,       ///< PRIORITY_: below normal + 3
    PRIORITY_BELOW_NORMAL4  = 16+4,       ///< PRIORITY_: below normal + 4
    PRIORITY_BELOW_NORMAL5  = 16+5,       ///< PRIORITY_: below normal + 5
    PRIORITY_BELOW_NORMAL6  = 16+6,       ///< PRIORITY_: below normal + 6
    PRIORITY_BELOW_NORMAL7  = 16+7,       ///< PRIORITY_: below normal + 7
    PRIORITY_NORMAL         = 24,         ///< PRIORITY_: normal
    PRIORITY_NORMAL1        = 24+1,       ///< PRIORITY_: normal + 1
    PRIORITY_NORMAL2        = 24+2,       ///< PRIORITY_: normal + 2
    PRIORITY_NORMAL3        = 24+3,       ///< PRIORITY_: normal + 3
    PRIORITY_NORMAL4        = 24+4,       ///< PRIORITY_: normal + 4
    PRIORITY_NORMAL5        = 24+5,       ///< PRIORITY_: normal + 5
    PRIORITY_NORMAL6        = 24+6,       ///< PRIORITY_: normal + 6
    PRIORITY_NORMAL7        = 24+7,       ///< PRIORITY_: normal + 7
    PRIORITY_ABOVE_NORMAL   = 32,         ///< PRIORITY_: above normal
    PRIORITY_ABOVE_NORMAL1  = 32+1,       ///< PRIORITY_: above normal + 1
    PRIORITY_ABOVE_NORMAL2  = 32+2,       ///< PRIORITY_: above normal + 2
    PRIORITY_ABOVE_NORMAL3  = 32+3,       ///< PRIORITY_: above normal + 3
    PRIORITY_ABOVE_NORMAL4  = 32+4,       ///< PRIORITY_: above normal + 4
    PRIORITY_ABOVE_NORMAL5  = 32+5,       ///< PRIORITY_: above normal + 5
    PRIORITY_ABOVE_NORMAL6  = 32+6,       ///< PRIORITY_: above normal + 6
    PRIORITY_ABOVE_NORMAL7  = 32+7,       ///< PRIORITY_: above normal + 7
    PRIORITY_HIGH           = 40,         ///< PRIORITY_: high
    PRIORITY_HIGH1          = 40+1,       ///< PRIORITY_: high + 1
    PRIORITY_HIGH2          = 40+2,       ///< PRIORITY_: high + 2
    PRIORITY_HIGH3          = 40+3,       ///< PRIORITY_: high + 3
    PRIORITY_HIGH4          = 40+4,       ///< PRIORITY_: high + 4
    PRIORITY_HIGH5          = 40+5,       ///< PRIORITY_: high + 5
    PRIORITY_HIGH6          = 40+6,       ///< PRIORITY_: high + 6
    PRIORITY_HIGH7          = 40+7,       ///< PRIORITY_: high + 7
    PRIORITY_REALTIME       = 48,         ///< PRIORITY_: realtime
    PRIORITY_REALTIME1      = 48+1,       ///< PRIORITY_: realtime + 1
    PRIORITY_REALTIME2      = 48+2,       ///< PRIORITY_: realtime + 2
    PRIORITY_REALTIME3      = 48+3,       ///< PRIORITY_: realtime + 3
    PRIORITY_REALTIME4      = 48+4,       ///< PRIORITY_: realtime + 4
    PRIORITY_REALTIME5      = 48+5,       ///< PRIORITY_: realtime + 5
    PRIORITY_REALTIME6      = 48+6,       ///< PRIORITY_: realtime + 6
    PRIORITY_REALTIME7      = 48+7,       ///< PRIORITY_: realtime + 7
    PRIORITY_ERROR          = -1,         ///< System cannot determine priority or illegal priority.    
    PRIORITY_RESERVED       = 0x7FFFFFFF  ///< Prevents enum down-size compiler optimization.
  };
  
  public: enum State{
    STATE_INACTIVE        =  0,           ///< Inactive.
    STATE_READY           =  1,           ///< Ready.
    STATE_RUNNING         =  2,           ///< Running.
    STATE_BLOCKED         =  3,           ///< Blocked.
    STATE_TERMINATED      =  4,           ///< Terminated.
    STATE_ERROR           = -1,           ///< Error.
    STATE_RESERVED        = 0x7FFFFFFF    ///< Prevents enum down-size compiler optimization.
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
  private: void* mThreadID = nullptr;

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
  public: Thread(const Memory& memory);

  /**
   * Construct.
   */
  public: Thread(const Memory& memory, const char* name);

  /**
   * Destruct.
   */
  public: virtual ~Thread(void);

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
   * Public Method <Inline>
   */
  
  /**
   *
   */
  public: inline int getStackSize(void) const{
    return this->length();
  }

  /* **************************************************************************************
   * Public Method
   */

  /**
   *
   */
  public: const char* getName(void) const;
  
  /**
   *
   */
  public: Priority getPriority(void);

  /**
   *
   */
  public: State getState(void);
  
  /**
   *
   */
  public: bool start(void);
  
  /**
   *
   */
  public: bool start(Priority priority);
  
  /**
   *
   */
  public: void notify(void);
  
  /**
   *
   */
  public: bool setPriority(Priority priority);  
  
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
  private: static void entryPoint(void* attachment);
  
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

#endif/* MCUF_AC7E7A3E_E6D3_4355_B4DE_6B28DF198293 */
