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
#include "../function/Consumer.hpp"
#include "../hal/Base.hpp"
#include "../lang/Pointer.hpp"



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
  public: virtual void disableAll(void) = 0;

  /**
   * 
   */
  public: virtual void disableFall(void) = 0;

  /**
   * 
   */
  public: virtual void disableRise(void) = 0;

  /**
   * 
   */
  public: virtual bool enableFall(mcuf::lang::Pointer* attachment, 
                                  mcuf::function::Consumer<mcuf::lang::Pointer&> function) = 0;

  /**
   * 
   */
  public: virtual bool enableRise(mcuf::lang::Pointer* attachment, 
                                  mcuf::function::Consumer<mcuf::lang::Pointer&> function) = 0;

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
