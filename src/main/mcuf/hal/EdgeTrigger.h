/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_EFF1A157_A291_4313_A742_99FB124D0B71
#define MCUF_EFF1A157_A291_4313_A742_99FB124D0B71

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/hal/Base.h"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    interface EdgeTrigger;
    interface EdgeTriggerEvent;
  }
}


/* ****************************************************************************************
 * Interface EdgeTrigger
 */  
interface mcuf::hal::EdgeTrigger implement mcuf::hal::Base{

  /* **************************************************************************************
   * Method
   */

  /**
   * 
   */
  virtual void disableAll(void) abstract;

  /**
   * 
   */
  virtual void disableFall(void) abstract;

  /**
   * 
   */
  virtual void disableRise(void) abstract;

  /**
   * 
   */
  virtual bool enableFall(EdgeTriggerEvent* event) abstract;

  /**
   * 
   */
  virtual bool enableRise(EdgeTriggerEvent* event) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 


#endif/* MCUF_EFF1A157_A291_4313_A742_99FB124D0B71 */
