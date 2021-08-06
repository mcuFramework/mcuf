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
#include "Base.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    class GeneralPurposeIO;
  }
}



/* ****************************************************************************************
 * Class GeneralPurposeIO
 */  
class mcuf::hal::GeneralPurposeIO : 
      public mcuf::hal::Base{

  /* **************************************************************************************
   * Subclass
   */
  public: class Pin;

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
   * @param port GPIO port.
   */
  public: virtual uint32_t read(uint32_t port) = 0;
  
  /**
   *
   * @param port GPIO port.
   * @param value GPIO write value.
   */
  public: virtual void set(uint32_t port, uint32_t value) = 0;
  
  /**
   * 
   */
  public: virtual void clear(uint32_t port, uint32_t mask) = 0;
  
  /**
   * 
   */
  public: virtual void toggle(uint32_t port, uint32_t mask) = 0;
  
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



/* ****************************************************************************************
 * Class GeneralPurposeIO::Pin
 */  
class mcuf::hal::GeneralPurposeIO::Pin:
      public mcuf::lang::Object{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Enum PinMode
   */
  public: enum PinMode{
    PULL_UP,
    PULL_DOWN,
    OPEN_DRAIN,
  };
   
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
   * Set io pin to high or low.
   *
   * @param value false = low, true = true.
   */
  public: virtual void setValue(bool value) = 0;
  
  /**
   * Set io pin to high.
   */
  public: virtual void setHigh(void) = 0;
  
  /**
   * Set io pin to low.
   */
  public: virtual void setLow(void) = 0;
  
  /**
   * Set io not logic.
   */
  public: virtual void setToggle(void) = 0;
  
  /**
   * Set io direction.
   * 
   * @param dir false = input, true = output.
   */
  public: virtual void setDir(bool dir) = 0;
  
  /**
   * Set io direction to input.
   */
  public: virtual void setInput(void) = 0;
  
  /**
   * Set io direction to output.
   */
  public: virtual void setOutput(void) = 0;
  
  /**
   * Get io read value.
   *
   * @return false = low, true = high.
   */
  public: virtual bool getValue(void) = 0;
  
  /**
   * Get io ditrction.
   *
   * @return false = input, true = output.
   */
  public: virtual bool getDir(void) = 0;

  /**
   * 
   */
  public: virtual bool setPinMode(PinMode mode) = 0;

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

  /**
   * 
   */
  public: Pin(void) = default;
  
  /**
   * 
   */
  public: virtual ~Pin() = default;

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
