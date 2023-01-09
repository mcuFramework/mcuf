/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_DF0EC699_78D6_4243_A75D_F321C92D88BB
#define MCUF_DF0EC699_78D6_4243_A75D_F321C92D88BB

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "hal/counter/TimerStatus.h"
#include "mcuf/lang/Interface.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{  
  namespace counter{
    interface TimerEvent;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::counter::TimerEvent extends virtual mcuf::lang::Interface{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @param status 
   */
  virtual void onTimerEvent(hal::counter::TimerStatus status) abstract;
};

#endif /* MCUF_DF0EC699_78D6_4243_A75D_F321C92D88BB */
