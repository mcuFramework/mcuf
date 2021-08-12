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
#include "../function/Consumer.hpp"
#include "../hal/Base.hpp"
#include "../lang/Pointer.hpp"


/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{  
    class Timer;
  }
}



/* ****************************************************************************************
 * Class Timer
 */  
class mcuf::hal::Timer : 
      public mcuf::hal::Base{

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
  public: virtual void cancel(void) = 0;

  /**
   * 
   */
  public: virtual bool isBusy(void) = 0;
  
  /**
   * 
   */
  public: virtual int getRemaining(void) = 0;

  /**
   * 
   */
  public: virtual uint32_t getTickBaseMilliSecond(void) = 0;

  /**
   * 
   */
  public: virtual bool startAtTick(uint32_t tick) = 0;

  /**
   * 
   */
  public: virtual bool startAtTick(uint32_t tick,
                                   mcuf::lang::Pointer* attachment,  
                                   mcuf::function::Consumer<mcuf::lang::Pointer&>* execute) = 0;
  
  /**
   * 
   */
  public: virtual bool startAtTime(uint32_t microSecond) = 0;

  /**
   * 
   */
  public: virtual bool startAtTime(uint32_t microSecond, 
                                   mcuf::lang::Pointer* attachment,  
                                   mcuf::function::Consumer<mcuf::lang::Pointer&>* execute) = 0;
  
  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

  /**
   * 
   */
  public: Timer(void) = default;
  
  /**
   * 
   */
  public: virtual ~Timer() = default;
  
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
