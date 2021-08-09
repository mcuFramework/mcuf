/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "PinDefine.hpp"

/* ****************************************************************************************
 * Using
 */  
using mcuf::hal::PinDefine;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
PinDefine::PinDefine(uint16_t port, uint16_t pin){
  this->port = port;
  this->pin = pin;
  return;
}

/**
 * 
 */
PinDefine::PinDefine(const PinDefine::PortPin& portPin){
  this->port = portPin.port;
  this->pin = portPin.pin;
  return;
}

/**
 * 
 */
PinDefine::PinDefine(void){
  this->port = 0;
  this->pin = 0;
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/**
 * 
 */
PinDefine::operator PinDefine::PortPin(){
  PortPin result;
  result.port = this->port;
  result.pin = this->pin;
  return result;
}

/* ****************************************************************************************
 * Public Method <Static>
 */
 
/* ****************************************************************************************
 * Public Method <Override>
 */

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
