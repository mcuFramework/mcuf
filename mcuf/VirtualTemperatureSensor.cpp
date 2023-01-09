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
#include "mcuf\VirtualTemperatureSensor.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::VirtualTemperatureSensor;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */
/**
 * @brief Construct a new Temperature Sensor Simulator object
 * 
 */
VirtualTemperatureSensor::VirtualTemperatureSensor(void){
  this->mValue = 25.0f;
  return;
}

/**
 * @brief Construct a new Temperature Sensor Simulator object
 * 
 * @param value 
 */
VirtualTemperatureSensor::VirtualTemperatureSensor(float value){
  this->mValue = value;
  return;
}

/**
 * @brief Destroy the Temperature Sensor Simulator object
 * 
 */
VirtualTemperatureSensor::~VirtualTemperatureSensor(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - mcuf::TemperatureSensor
 */

/**
 * @brief Get the Celsius object
 * 
 * @return float 
 */
float VirtualTemperatureSensor::getCelsius(void){
  return this->mValue;
}

/* ****************************************************************************************
 * Public Method
 */
/**
 * @brief Get the Celsius object
 * 
 * @return float 
 */
float VirtualTemperatureSensor::setCelsius(float value){
  this->mValue = value;
  return this->getCelsius();
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
