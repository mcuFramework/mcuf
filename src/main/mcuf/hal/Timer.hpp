/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_AD0B942D_EE2D_4080_BDAD_3E9AACE341DA
#define MCUF_AD0B942D_EE2D_4080_BDAD_3E9AACE341DA

/* ****************************************************************************************
 * Include
 */  
#include "mcuf/function/Consumer.hpp"
#include "mcuf/hal/Base.hpp"
#include "mcuf/lang/Pointer.hpp"


/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{  
    interface Timer;
  }
}



/* ****************************************************************************************
 * Interface Timer
 */  
interface mcuf::hal::Timer implement mcuf::hal::Base{

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
  virtual void cancel(void) abstract;

  /**
   * 
   */
  virtual bool isBusy(void) abstract;
  
  /**
   * 
   */
  virtual bool isDone(void) abstract;

  /**
   * 
   */
  virtual uint32_t getTickBaseMilliSecond(void) abstract;

  /**
   * 
   */
  virtual bool startAtTick(uint32_t tick) abstract;

  /**
   * 
   */
  virtual bool startAtTick(uint32_t tick, Event* event) abstract;
  
  /**
   * 
   */
  virtual bool startAtTime(uint32_t microSecond) abstract;

  /**
   * 
   */
  virtual bool startAtTime(uint32_t microSecond, Event* event) abstract;
  
};



/* ****************************************************************************************
 * Interface Timer:;Event
 */  
interface mcuf::hal::Timer::Event{
  /* **************************************************************************************
   * Subclass
   */
  enum Status{
    TRIGGER,
    CANCEL
  };

  /* **************************************************************************************
   * Method
   */
  
  /**
   *
   */
  virtual void onTimerEvent(Status status) abstract;
  
};



/* *****************************************************************************************
 * End of file
 */ 


#endif/* MCUF_AD0B942D_EE2D_4080_BDAD_3E9AACE341DA */
