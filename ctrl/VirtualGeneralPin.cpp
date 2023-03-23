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
#include "./VirtualGeneralPin.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using ctrl::VirtualGeneralPin;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */
/**
 * @brief Construct a new Virtual General Pin object
 * 
 */
VirtualGeneralPin::VirtualGeneralPin(void){
  this->mDir = 0;
  this->mValue = 0;
  this->mGeneralPinMode = hal::GeneralPinMode::PUSH_PULL;
  return;
}
/**
 * @brief Destroy the Virtual General Pin object
 * 
 */
VirtualGeneralPin::~VirtualGeneralPin(void){
  this->mDir = 0;
  this->mValue = 0;
  this->mGeneralPinMode = hal::GeneralPinMode::PUSH_PULL;
  return;
}
/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override>
 */
/**
 * @brief Get io direction.
 * 
 * @return true output
 * @return false input
 */
bool VirtualGeneralPin::getDir(void){
  return this->mDir;
}

/**
 * @brief 
 * 
 * @param dir false = input, true = output.
 */
void VirtualGeneralPin::setDir(bool dir){
  this->mDir = dir;
}

/**
 * @brief 
 * 
 * @return mcuf::hal::GeneralPinMode 
 */
hal::GeneralPinMode VirtualGeneralPin::getPinMode(void){
  return this->mGeneralPinMode;
}
/**
 * @brief 
 * 
 * @param mode 
 * @return true 
 * @return false 
 */
hal::GeneralPinMode VirtualGeneralPin::setPinMode(hal::GeneralPinMode mode){
  this->mGeneralPinMode = mode;
  return this->mGeneralPinMode;
} 

/**
 * @brief Set the High object
 * 
 */
void VirtualGeneralPin::setHigh(void){
  this->setValue(true);
  return;
}

/**
 * @brief Set the Input object
 * 
 */
void VirtualGeneralPin::setInput(void){
  this->setDir(false);
  return;
}

/**
 * @brief Set the Low object
 * 
 */
void VirtualGeneralPin::setLow(void){
  this->setValue(false);
  return;
}

/**
 * @brief Set the Output object
 * 
 */
void VirtualGeneralPin::setOutput(void){
  this->setDir(true);
  return;
}
/**
 * @brief Set the Toggle object
 * 
 */
void VirtualGeneralPin::setToggle(void){
  if(this->getDir() == false)
    return;

  this->setValue(!this->getValue());
  return;
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool VirtualGeneralPin::getValue(void){
  return this->mValue;
}

/**
 * @brief 
 * 
 * @param level 
 */
void VirtualGeneralPin::setValue(bool level){
  if(this->getDir() == false)
    return;

  this->mValue = getValue();
  return;
}
/* ****************************************************************************************
 * Public Method
 */

/**
 * @brief Set the Input Value object
 * 
 * @param level 
 * @return true 
 * @return false 
 */
bool VirtualGeneralPin::setInputValue(bool level){
  if(this->getDir() == true)
    return false;
  
  this->mValue = level;
  return true;
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
