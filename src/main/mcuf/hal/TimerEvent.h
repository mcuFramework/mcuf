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

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{  
    interface TimerEvent;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::TimerEvent{

  /* **************************************************************************************
   * Subclass
   */
  enum TimerStatus{
    HAL_TIMER_TRIGGER,
    HAL_TIMER_CANCEL
  };

  /* **************************************************************************************
   * Method
   */
  
  /**
   *
   */
  virtual void onTimerEvent(TimerStatus status) abstract;
};

#endif/* MCUF_DF0EC699_78D6_4243_A75D_F321C92D88BB */
