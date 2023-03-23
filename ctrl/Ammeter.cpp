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
#include "./Ammeter.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using ctrl::Ammeter;
using ctrl::Voltmeter;
using hal::AnalogInputPin;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */
/**
 * @brief Construct a new Ammeter object
 * 
 * @param analogPin 
 * @param voltageMin 
 * @param voltageMax 
 * @param amperDelta 1V/Amper
 */
Ammeter::Ammeter(AnalogInputPin& analogPin, float voltageMin, float voltageMax, float amperDelta) : 
Voltmeter(analogPin, voltageMin, voltageMax){

  this->mAmperDelta = amperDelta;
  return;
}

/**
 * @brief Construct a new Ammeter object
 * 
 * @param voltmeter 
 * @param amperDelta 1V/Amper
 */
Ammeter::Ammeter(const ctrl::Voltmeter& voltmeter, float amperDelta) : 
Voltmeter(voltmeter){

  this->mAmperDelta = amperDelta;
  return;
}
/**
 * @brief Destroy the Ammeter object
 * 
 */
Ammeter::~Ammeter(void){
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
float Ammeter::amper(void){
  return this->voltage() * this->mAmperDelta;
}

/**
 * @brief 
 * 
 * @return float 
 */
float Ammeter::amperDelta(void){
  return this->mAmperDelta;
}

/**
 * @brief 
 * 
 * @param value 
 */
void Ammeter::amperDelta(float value){
  this->mAmperDelta = value;
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
