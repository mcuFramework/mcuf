/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_DEF49AD1_F66A_45EA_BC7D_16E860F3A655
#define MCUF_DEF49AD1_F66A_45EA_BC7D_16E860F3A655

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/hal/general/trigger/EdgeTriggerEvent.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    interface EdgeTriggerControl;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::EdgeTriggerControl{

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
  virtual bool enableFall(mcuf::hal::general::trigger::EdgeTriggerEvent* event) abstract;

  /**
   * @brief 
   * 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool enableRise(mcuf::hal::general::trigger::EdgeTriggerEvent* event) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_DEF49AD1_F66A_45EA_BC7D_16E860F3A655 */
