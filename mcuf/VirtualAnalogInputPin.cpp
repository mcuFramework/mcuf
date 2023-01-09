/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "mcuf\VirtualAnalogInputPin.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::VirtualAnalogInputPin;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */
/**
 * @brief Construct a new Virtual Analog Input Pin object
 * 
 */
VirtualAnalogInputPin::VirtualAnalogInputPin(void){
  this->mValue = 0;
  this->mLevel = 0;
  return;
}

/**
 * @brief Destroy the Virtual Analog Input Pin object
 * 
 */
VirtualAnalogInputPin::~VirtualAnalogInputPin(void){
  this->mValue = 0;
  this->mLevel = 0;
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - hal::AnalogInputPin
 */
/**
 * @brief 
 * 
 * @return uint32_t 
 */
uint32_t VirtualAnalogInputPin::convert(void){
  return this->mValue;
}

/**
 * @brief Get the adc convert level.
 * 
 * @return uint32_t 
 */
uint32_t VirtualAnalogInputPin::getConvertLevel(void){
  return this->mLevel;
}

/* ****************************************************************************************
 * Public Method
 */

/**
 * @brief 
 * 
 * @param value 
 */
void VirtualAnalogInputPin::setValue(uint32_t value){
  if(value > this->mLevel)
    value = this->mLevel;
  
  this->mValue = value;
  return;
}

/**
 * @brief 
 * 
 * @param level 
 */
void VirtualAnalogInputPin::setConvertLevel(uint32_t level){
  this->mLevel = level;
  if(this->mValue > this->mLevel)
    this->mValue = this->mLevel;

  return;
}
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
