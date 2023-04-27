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
#include "boot/CoreEntry.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using boot::CoreEntry;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */
/**
 *
 */
CoreEntry::CoreEntry(uint32_t stackSize) : Thread(stackSize){
  return;
}

/**
 *
 */
CoreEntry::~CoreEntry(void){
  return;
}
/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - mcuf::function::Runnable
 */

/**
 *
 */
void CoreEntry::run(void){
  this->mSetup(this);
  while(true){
    this->mLoop(this);
  }
}

/* ****************************************************************************************
 * Public Method
 */

/**
 *
 */
void CoreEntry::setSetup(void (*setup)(sys::Thread*)){
  this->mSetup = setup;
}

/**
 *
 */
void CoreEntry::setLoop(void (*loop)(sys::Thread*)){
  this->mLoop = loop;
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