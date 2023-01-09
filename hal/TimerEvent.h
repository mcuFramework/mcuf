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

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf\Interface.h"

//-----------------------------------------------------------------------------------------
#include "hal\TimerStatus.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{  
  interface TimerEvent;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::TimerEvent extends virtual mcuf::Interface{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @param status 
   */
  virtual void onTimerEvent(hal::TimerStatus status) abstract;
};

#endif /* MCUF_DF0EC699_78D6_4243_A75D_F321C92D88BB */
