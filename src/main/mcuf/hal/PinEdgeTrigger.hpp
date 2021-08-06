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
#include "../hal/Base.hpp"
#include "../function/BiConsumer.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    class PinEdgeTrigger;
  }
}


/* ****************************************************************************************
 * Class PinEdgeTrigger
 */  
class mcuf::hal::PinEdgeTrigger: 
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
  public: virtual bool enableRise(void* attachment, void(*function)(PinEdgeTrigger*, void*)) = 0;

  /**
   * 
   */
  public: virtual bool enableRise(void* attachment, mcuf::function::BiConsumer<PinEdgeTrigger*, void*> function) = 0;
  
  /**
   * 
   */
  public: virtual bool enableFall(void* attachment, void(*function)(PinEdgeTrigger*, void*)) = 0;
  
  /**
   * 
   */
  public: virtual bool enableFall(void* attachment, mcuf::function::BiConsumer<PinEdgeTrigger*, void*> function) = 0;

  /**
   * 
   */
  public: virtual void disableRise(void) = 0;
  
  /**
   * 
   */
  public: virtual void disableFall(void) = 0;

  /**
   * 
   */
  public: virtual void disableAll(void) = 0;

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

  /**
   * 
   */
  public: PinEdgeTrigger(void) = default;
  
  /**
   * 
   */
  public: virtual ~PinEdgeTrigger() = default;

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


#endif/* MCUF_EFF1A157_A291_4313_A742_99FB124D0B71 */
