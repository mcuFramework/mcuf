/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include <string.h>

//-----------------------------------------------------------------------------------------
#include "cmsis_rtos/rtx_os.h"
#include "mcuf/lang/managerment/TimerManager.hpp"

/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::managerment::TimerManager;
using mcuf::lang::Memory;
using mcuf::util::Pool;
using mcuf::util::TimerScheduler;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/**
 *
 */
TimerManager::TimerManager(Memory& memory) construct TimerScheduler(memory){
  memset(this->mTimerMemory, 0x00, sizeof(this->mTimerMemory));
  this->mTimerID = nullptr;
  this->mTick = 0;
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

/**
 *
 */
bool TimerManager::start(uint32_t tick){
  if(this->mTimerID != nullptr)
    return false;
  
  if(tick == 0)
    return false;
  
  this->mTick = tick;
  
  osTimerAttr_t attr;
  attr.attr_bits = 0;
  attr.name = "TimerManager";
  attr.cb_mem = this->mTimerMemory;
  attr.cb_size = sizeof(this->mTimerMemory);
  
  this->mTimerID = osTimerNew(TimerManager::entryPoint, osTimerPeriodic, this, &attr);
  
  if(this->mTimerID == nullptr)
    return false;
  
  if(osTimerStart(this->mTimerID, tick) != osOK){
    this->stop();
    return false;
  }

  return true;
}
  
/**
 *
 */
bool TimerManager::stop(void){
  if(this->mTimerID == nullptr)
    return false;
  
  osTimerStop(this->mTimerID);
  osTimerDelete(this->mTimerID);
  this->mTimerID = nullptr;
  this->mTick = 0;
  
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
 * Private Method  <Static>
 */

/**
 *
 */
void TimerManager::entryPoint(void* attacmnent){
  TimerManager* timerManager = static_cast<TimerManager*>(attacmnent);
  timerManager->tick(timerManager->mTick);
}

/* ****************************************************************************************
 * Private Method
 */
 
/* ****************************************************************************************
 * End of file
 */ 
