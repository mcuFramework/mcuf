/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_BCFFCC2B_972F_4425_952D_3462B2F0C788
#define MCUF_BCFFCC2B_972F_4425_952D_3462B2F0C788

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "hal/Base.h"
#include "mcuf/lang/Interface.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
  namespace general{
    interface GeneralPortControl;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::general::GeneralPortControl extends mcuf::lang::Interface{
  /* **************************************************************************************
   * Method 
   */

  /**
   * @brief 
   * 
   * @param port 
   * @return uint32_t 
   */
  virtual uint32_t dir(uint32_t port) abstract;

  /**
   * @brief 
   * 
   * @param port 
   * @param value 
   */
  virtual void dir(uint32_t port, uint32_t value) abstract;
  
  /**
   * @brief 
   * 
   * @param port 
   * @param mask 
   */
  virtual void dirClear(uint32_t port, uint32_t mask) abstract;
  
  /**
   * @brief 
   * 
   * @param port 
   * @param mask 
   */
  virtual void dirSet(uint32_t port, uint32_t mask) abstract;

  /**
   * @brief Get port value.
   * 
   * @param port GPIO port.
   * @return pin value 0 = low, 1 = high.
   */
  virtual uint32_t pin(uint32_t port) abstract;

  /**
   * @brief Set port value.
   * 
   * @param port GPIO port.
   * @param value 0 = low, 
   *              1 = high.
   */
  virtual void pin(uint32_t port, uint32_t value) abstract;
  
  /**
   * @brief Set port mask low.
   * 
   * @param port GPIO port.
   * @param value 0 = No operation. 
   *              1 = Set output bit low.
   */
  virtual void pinClear(uint32_t port, uint32_t mask) abstract;

  /**
   * @brief Set port mask high.
   * 
   * @param port GPIO port.
   * @param value 0 = No operation. 
   *              1 = Set output bit high.
   */
  virtual void pinSet(uint32_t port, uint32_t mask) abstract;
  
  /**
   * @brief Set port mask toggle.
   * 
   * @param port GPIO port.
   * @param value 0 = No operation. 
   *              1 = Set output bit toggle.
   */
  virtual void pinToggle(uint32_t port, uint32_t mask) abstract;
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_BCFFCC2B_972F_4425_952D_3462B2F0C788 */
