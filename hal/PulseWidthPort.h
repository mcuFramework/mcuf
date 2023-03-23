/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_9C2CA0D2_D921_428A_B411_A41968013B4F
#define MCUF_9C2CA0D2_D921_428A_B411_A41968013B4F

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "../mcuf/package-info.h"

//-----------------------------------------------------------------------------------------
#include "./Base.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */

namespace hal{
  interface PulseWidthPort;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface hal::PulseWidthPort extends hal::Base{

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

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_9C2CA0D2_D921_428A_B411_A41968013B4F */
