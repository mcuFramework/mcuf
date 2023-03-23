/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_DA8BBDE6_3AFE_4070_945C_08F9966A0B20
#define MCUF_DA8BBDE6_3AFE_4070_945C_08F9966A0B20

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "../mcuf/package-info.h"

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./Base.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
  interface GeneralPort;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::GeneralPort extends hal::Base{
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

#endif /* MCUF_DA8BBDE6_3AFE_4070_945C_08F9966A0B20 */
