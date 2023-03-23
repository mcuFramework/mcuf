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
#include "./Voltmeter.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using ctrl::Voltmeter;
using hal::AnalogInputPin;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */
/**
 * @brief Construct a new Voltmeter object
 * 
 * @param analogPin 
 * @param voltmeterMin 
 * @param voltmeterMax 
 */
Voltmeter::Voltmeter(AnalogInputPin& analogPin, float voltageMin, float voltageMax) :
mAnalogPin(analogPin){

  this->mVoltageMin = voltageMin;
  this->mVoltageMax = voltageMax;
  this->mVoltageDelta = (voltageMax - voltageMin) / static_cast<float>(analogPin.getConvertLevel());
  return;
}

/**
 * @brief Destroy the Voltmeter object
 * 
 */
Voltmeter::~Voltmeter(void){
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

/* ****************************************************************************************
 * Public Method
 */
/**
 * @brief 
 * 
 * @return float 
 */
float Voltmeter::voltage(void){
  float result = this->mVoltageDelta * static_cast<float>(this->mAnalogPin.convert());
  return (result + this->mVoltageMin);
}

/**
 * @brief 
 * 
 * @return float 
 */
float Voltmeter::voltageMax(void){
  return this->mVoltageMax;
}

/**
 * @brief 
 * 
 * @param value 
 */
void Voltmeter::voltageMax(float value){
  this->mVoltageMax = value;
  this->mVoltageDelta = (this->mVoltageMax - this->mVoltageMin) / static_cast<float>(this->mAnalogPin.getConvertLevel());
}

/**
 * @brief 
 * 
 * @return float 
 */
float Voltmeter::voltageMin(void){
  return this->mVoltageMin;
}

/**
 * @brief 
 * 
 * @param value 
 */
void Voltmeter::voltageMin(float value){
  this->mVoltageMin = value;
  this->mVoltageDelta = (this->mVoltageMax - this->mVoltageMin) / static_cast<float>(this->mAnalogPin.getConvertLevel());
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
