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
 * Class Timer
 */  
interface mcuf::hal::Timer implement mcuf::hal::Base{

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

  /* **************************************************************************************
   * Abstract method <Public>
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
  virtual bool startAtTick(uint32_t tick,
                                   void* attachment,  
                                   mcuf::function::Consumer<void*>* execute) abstract;
  
  /**
   * 
   */
  virtual bool startAtTime(uint32_t microSecond) abstract;

  /**
   * 
   */
  virtual bool startAtTime(uint32_t microSecond, 
                                   void* attachment,  
                                   mcuf::function::Consumer<void*>* execute) abstract;
  
  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  
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


#endif/* MCUF_AD0B942D_EE2D_4080_BDAD_3E9AACE341DA */
