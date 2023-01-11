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
using mcuf::VirtualGeneralPin;

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
  this->mGeneralPinMode = mcuf::hal::GeneralPinMode::PUSH_PULL;
  return;
}
/**
 * @brief Destroy the Virtual General Pin object
 * 
 */
VirtualGeneralPin::~VirtualGeneralPin(void){
  this->mDir = 0;
  this->mValue = 0;
  this->mGeneralPinMode = mcuf::hal::GeneralPinMode::PUSH_PULL;
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
bool VirtualGeneralPin::dir(void){
  return this->mDir;
}

/**
 * @brief 
 * 
 * @param dir false = input, true = output.
 */
void VirtualGeneralPin::dir(bool dir){
  this->mDir = dir;
}

/**
 * @brief 
 * 
 * @return mcuf::hal::GeneralPinMode 
 */
mcuf::hal::GeneralPinMode VirtualGeneralPin::pinMode(void){
  return this->mGeneralPinMode;
}
/**
 * @brief 
 * 
 * @param mode 
 * @return true 
 * @return false 
 */
bool VirtualGeneralPin::pinMode(mcuf::hal::GeneralPinMode mode){
  this->mGeneralPinMode = mode;
  return true;
} 

/**
 * @brief Set the High object
 * 
 */
void VirtualGeneralPin::setHigh(void){
  this->value(true);
  return;
}

/**
 * @brief Set the Input object
 * 
 */
void VirtualGeneralPin::setInput(void){
  this->dir(false);
  return;
}

/**
 * @brief Set the Low object
 * 
 */
void VirtualGeneralPin::setLow(void){
  this->value(false);
  return;
}

/**
 * @brief Set the Output object
 * 
 */
void VirtualGeneralPin::setOutput(void){
  this->dir(true);
  return;
}
/**
 * @brief Set the Toggle object
 * 
 */
void VirtualGeneralPin::setToggle(void){
  if(this->dir() == false)
    return;

  this->value(!this->value());
  return;
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool VirtualGeneralPin::value(void){
  return this->mValue;
}

/**
 * @brief 
 * 
 * @param level 
 */
void VirtualGeneralPin::value(bool level){
  if(this->dir() == false)
    return;

  this->mValue = value();
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
  if(this->dir() == true)
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
