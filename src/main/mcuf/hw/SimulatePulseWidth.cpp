/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "mcuf/lang/System.h"
#include "mcuf/hw/SimulatePulseWidth.h"
/* ****************************************************************************************
 * Macro
 */  

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::System;
using mcuf::hw::SimulatePulseWidth;
using mcuf::hal::GeneralPinControl;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 *
 */
SimulatePulseWidth::SimulatePulseWidth(GeneralPinControl* pin){
  this->mPin = pin;
  this->mMinnisecondBase = 0;
  this->mMinnisecondChange = 0;
}

/**
 *
 */
SimulatePulseWidth::~SimulatePulseWidth(void){
  this->stop();
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */
 
/* ****************************************************************************************
 * Public Method <Override> - mcuf::util::TimerTask
 */

/**
 * @brief 
 * 
 */
void SimulatePulseWidth::run(void){
  if(this->mStats){
    this->mStats = false;
    this->setPeriod(this->mMinnisecondBase - this->mMinnisecondChange);
    this->mPin->setHigh();
  }else{
    this->mStats = true;
    this->setPeriod(this->mMinnisecondChange);
    this->mPin->setLow();
  }
  
  return;
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::hal::PulseWidthControl
 */

/**
 * @brief Set the Frequence object
 * 
 * @param hz 
 * @return true 
 * @return false 
 */
bool SimulatePulseWidth::setBaseFrequence(uint32_t hz){
  if(hz > 1000)
    return false;
  
  this->mMinnisecondBase = (1000 / hz);
  return true;
}

/**
 * @brief Set the Base Second object
 * 
 * @param second 
 * @return true 
 * @return false 
 */
bool SimulatePulseWidth::setBaseSecond(float second){
  if(second < 0.001)
    return false;
  
  this->mMinnisecondBase = (second * 1000);
  
  return true;
}

/* ****************************************************************************************
 * Public Method <Override> - mcuf::hal::PulseWidthConfig
 */

/**
 * @brief Set the Duty object
 * 
 * @param percent 
 * @return true 
 * @return false 
 */
bool SimulatePulseWidth::setDuty(float percent){
  if(this->mMinnisecondBase == 0)
    return false;
  
  if(this->mPin == nullptr)
    return false;
  
  if(percent > 1)
    return false;
  
  
  this->mMinnisecondChange = (this->mMinnisecondBase * percent);
  this->cancel();
  this->mPin->setLow();
  this->mStats = false;
  System::scheduleAtFixedRate(*this, this->mMinnisecondChange, this->mMinnisecondChange);
  return true;
}
     
/**
 * @brief Set the Duty8 Bit object
 * 
 * @param duty 
 * @return true 
 * @return false 
 */
bool SimulatePulseWidth::setDuty8Bit(uint8_t duty){
  return true;
}

/**
 * @brief 
 * 
 */
bool SimulatePulseWidth::stop(void){
  this->cancel();
  return true;
}


/* ****************************************************************************************
 * Public Method
 */

/* ****************************************************************************************
 * Protected Method <Static>
 */
 
/* ****************************************************************************************
 * Protected Method <Override>
 */ 

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */
 
/* ****************************************************************************************
 * End of file
 */ 
