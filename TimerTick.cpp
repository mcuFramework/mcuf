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
#include "./TimerTick.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::TimerTick;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */
/**
 * @brief Construct a new Timer Tick object
 * 
 */
TimerTick::TimerTick(void){
  this->mStatus = 0;
}

/**
 * @brief Destroy the Timer Tick object
 * 
 */
TimerTick::~TimerTick(void){
  this->mStatus = 0;
  this->cancel();
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
 * @brief 
 * 
 */
void TimerTick::run(void){
  ++this->mStatus;
}

/* ****************************************************************************************
 * Public Method
 */
/**
 * @brief read
 * 
 * @return int 
 */
int TimerTick::isDone(void){
  return this->mStatus;
}

/**
 * @brief clear
 * 
 * @return int 
 */
void TimerTick::clear(void){
  this->mStatus = 0;
}

/**
 * @brief read and clear
 * 
 */
int TimerTick::read(void){
  int result = this->mStatus;
  this->mStatus = 0;
  return result;
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
