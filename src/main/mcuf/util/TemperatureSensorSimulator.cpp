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
#include "mcuf/util/TemperatureSensorSimulator.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::util::TemperatureSensorSimulator;

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
TemperatureSensorSimulator::TemperatureSensorSimulator(void){
  this->mValue = 25.0f;
  return;
}

/**
 * @brief Construct a new Temperature Sensor Simulator object
 * 
 * @param value 
 */
TemperatureSensorSimulator::TemperatureSensorSimulator(float value){
  this->mValue = value;
  return;
}

/**
 * @brief Destroy the Temperature Sensor Simulator object
 * 
 */
TemperatureSensorSimulator::~TemperatureSensorSimulator(void){
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - mcuf::util::TemperatureSensor
 */

/**
 * @brief Get the Celsius object
 * 
 * @return float 
 */
float TemperatureSensorSimulator::getCelsius(void){
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
float TemperatureSensorSimulator::setCelsius(float value){
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
