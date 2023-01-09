/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_B206944D_3301_4051_B3CD_59FD6BBFBF02
#define MCUF_B206944D_3301_4051_B3CD_59FD6BBFBF02

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf\Interface.h"

//-----------------------------------------------------------------------------------------
#include "hal\TimerEvent.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{  
  interface TimerControl;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::TimerControl extends virtual mcuf::Interface{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   */
  virtual void cancel(void) abstract;

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool isBusy(void) abstract;
  
  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool isDone(void) abstract;

  /**
   * @brief 
   * 
   */
  virtual void waitDone(void) abstract;
  
  /**
   * @brief Get the Timer Clock object
   * 
   * @return uint32_t hz
   */
  virtual uint32_t getTimerClock(void) abstract;  

  /**
   * @brief 
   * 
   * @param tick 
   * @return true 
   * @return false 
   */
  virtual bool startAtTick(uint32_t tick) abstract;

  /**
   * @brief 
   * 
   * @param tick 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool startAtTick(uint32_t tick, hal::TimerEvent* event) abstract;
  
  /**
   * @brief 
   * 
   * @param microSecond 
   * @return true 
   * @return false 
   */
  virtual bool startAtTime(uint32_t microSecond) abstract;

  /**
   * @brief 
   * 
   * @param microSecond 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool startAtTime(uint32_t microSecond, hal::TimerEvent* event) abstract;
  
  /**
   * @brief 
   * 
   * @param tick 
   */
  virtual void resetTick(uint32_t tick) abstract;
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_B206944D_3301_4051_B3CD_59FD6BBFBF02 */
