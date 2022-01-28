/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_BA8DBAF0_DCE9_4F33_B776_7C5470172961
#define MCUF_BA8DBAF0_DCE9_4F33_B776_7C5470172961

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/hal/Base.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    interface EdgeTriggerEvent;
  }
}

/* ****************************************************************************************
 * Interface EdgeTrigger
 */  
interface mcuf::hal::EdgeTriggerEvent{

  /* **************************************************************************************
   * Subclass
   */
  enum EdgeTriggerStatus{
    HAL_EDGETRIGGER_RISE,
    HAL_EDGETRIGGER_FALL
  };
  
  /* **************************************************************************************
   * Method
   */
  
  /**
   *
   */
  virtual void onEdgeTriggerEvent(EdgeTriggerStatus status) abstract;
  
};



/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_BA8DBAF0_DCE9_4F33_B776_7C5470172961 */
