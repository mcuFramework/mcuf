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
 * Class/Interface/Struct
 */  
interface mcuf::hal::EdgeTrigger extends mcuf::hal::Base{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   */
  virtual void disableAll(void) abstract;

  /**
   * @brief 
   * 
   */
  virtual void disableFall(void) abstract;

  /**
   * @brief 
   * 
   */
  virtual void disableRise(void) abstract;

  /**
   * @brief 
   * 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool enableFall(EdgeTriggerEvent* event) abstract;

  /**
   * @brief 
   * 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool enableRise(EdgeTriggerEvent* event) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 


#endif/* MCUF_EFF1A157_A291_4313_A742_99FB124D0B71 */
