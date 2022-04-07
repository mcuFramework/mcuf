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
#include "hal/general/EdgeTriggerEvent.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace hal{
  namespace general{
    interface EdgeTriggerControl;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::general::EdgeTriggerControl{

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
  virtual bool enableFall(hal::general::EdgeTriggerEvent* event) abstract;

  /**
   * @brief 
   * 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool enableRise(hal::general::EdgeTriggerEvent* event) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_DEF49AD1_F66A_45EA_BC7D_16E860F3A655 */
