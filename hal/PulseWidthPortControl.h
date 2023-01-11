/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_A8489895_04E2_42AE_ABD9_E59CE721E05B
#define MCUF_A8489895_04E2_42AE_ABD9_E59CE721E05B

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "../mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "../Interface.h"

//-----------------------------------------------------------------------------------------
#include "./Base.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace mcuf::hal{
  interface PulseWidthPortControl;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::PulseWidthPortControl extends virtual mcuf::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief Set the Frequence object
   * 
   * @param hz 
   * @return true 
   * @return false 
   */
  virtual bool setFrequence(float hz) abstract;

  /**
   * @brief Get the Frequence object
   * 
   * @return float 
   */
  virtual float getFrequence(void) abstract;

  /**
   * @brief Get the Period object
   * 
   * @return int 
   */
  virtual int getPeriod(void) abstract;
  
  /**
   * @brief Get the Duty object
   * 
   * @param pin 
   * @return float 
   */
  virtual float getDuty(int pin) abstract;

  /**
   * @brief Get the Duty Tick object
   * 
   * @param pin 
   * @return int 
   */
  virtual int getDutyTick(int pin) abstract;
  
  /**
   * @brief Set the Duty object
   * 
   * @param pin 
   * @param percent 
   * @return true 
   * @return false 
   */
  virtual bool setDuty(int pin, float percent) abstract;
  
  /**
   * @brief Set the Duty Tick object
   * 
   * @param pin 
   * @param duty 
   * @return true 
   * @return false 
   */
  virtual bool setDutyTick(int pin, int duty) abstract;

  /**
   * @brief 
   * 
   * @param pin 
   * @return true 
   * @return false 
   */
  virtual bool enable(int pin) abstract;
  
  /**
   * @brief 
   * 
   * @param pin 
   * @return true 
   * @return false 
   */
  virtual bool disable(int pin) abstract;  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_A8489895_04E2_42AE_ABD9_E59CE721E05B */
