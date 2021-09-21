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
#include "mcuf_base.h"
#include "mcuf/hal/base.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    interface GeneralPurposeIO;
  }
}



/* ****************************************************************************************
 * Class GeneralPurposeIO
 */  
interface mcuf::hal::GeneralPurposeIO implement mcuf::hal::Base{

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
  public: virtual uint32_t dir(uint32_t port) = 0;

  /**
   * 
   */
  public: virtual void dir(uint32_t port, uint32_t value) = 0;
  
  /**
   * 
   */
  public: virtual void dirClear(uint32_t port, uint32_t mask) = 0;
  
  /**
   * 
   */
  public: virtual void dirSet(uint32_t port, uint32_t mask) = 0;

  /**
   * Get port value.
   * 
   * @param port GPIO port.
   * @return pin value 0 = low, 1 = high.
   */
  public: virtual uint32_t pin(uint32_t port) = 0;

  /**
   * Set port value.
   * 
   * @param port GPIO port.
   * @param value 0 = low, 
   *              1 = high.
   */
  public: virtual void pin(uint32_t port, uint32_t value) = 0;
  
  /**
   * Set port mask low.
   * 
   * @param port GPIO port.
   * @param value 0 = No operation. 
   *              1 = Set output bit low.
   */
  public: virtual void pinClear(uint32_t port, uint32_t mask) = 0;

  /**
   * Set port mask high.
   * 
   * @param port GPIO port.
   * @param value 0 = No operation. 
   *              1 = Set output bit high.
   */
  public: virtual void pinSet(uint32_t port, uint32_t mask) = 0;
  
  /**
   * Set port mask toggle.
   * 
   * @param port GPIO port.
   * @param value 0 = No operation. 
   *              1 = Set output bit toggle.
   */
  public: virtual void pinToggle(uint32_t port, uint32_t mask) = 0;
  
  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

  /**
   * 
   */
  public: GeneralPurposeIO(void) = default;

  /**
   * 
   */
  public: virtual ~GeneralPurposeIO() = default;
  
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


#endif/* MCUF_DA8BBDE6_3AFE_4070_945C_08F9966A0B20 */
