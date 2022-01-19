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
#include "mcuf/function/Runnable.hpp"
#include "mcuf/hal/Base.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    interface EdgeTrigger;
  }
}


/* ****************************************************************************************
 * Interface EdgeTrigger
 */  
interface mcuf::hal::EdgeTrigger implement mcuf::hal::Base{

  /* **************************************************************************************
   * Subclass
   */
  interface Event;
  
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
  virtual bool enableFall(Event* event) abstract;

  /**
   * 
   */
  virtual bool enableRise(Event* event) abstract;

};



/* ****************************************************************************************
 * Interface EdgeTrigger
 */  
interface mcuf::hal::EdgeTrigger::Event{

  /* **************************************************************************************
   * Subclass
   */
  enum Status{
    RISE,
    FALL
  };
  
  /* **************************************************************************************
   * Method
   */
  
  /**
   *
   */
  virtual void onEdgeTriggerEvent(Status status) abstract;
  
};



/* *****************************************************************************************
 * End of file
 */ 


#endif/* MCUF_EFF1A157_A291_4313_A742_99FB124D0B71 */
