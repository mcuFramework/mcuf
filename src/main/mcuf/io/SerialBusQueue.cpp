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
#include "mcuf/io/SerialBusQueue.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::io::SerialBusQueue;
using mcuf::io::SerialBusQueuePacket;
using mcuf::io::OutputBuffer;
using mcuf::io::InputBuffer;
using hal::serial::SerialBus;
using hal::serial::SerialBusStatus;
using hal::serial::SerialBusEvent;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */
/**
 * @brief Construct a new Serial Bus Queue object
 * 
 * @param serialBus 
 * @param queueSize 
 */
SerialBusQueue::SerialBusQueue(SerialBus& serialBus, uint32_t queueSize) : 
ArrayQueue<SerialBusQueuePacket>(queueSize),
mSerialBus(serialBus){
  
  return;
}

/**
 * @brief Destroy the Serial Bus Queue object
 * 
 */
SerialBusQueue::~SerialBusQueue(void){
  this->abortAll();
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - hal::Base
 */
/**
 * @brief uninitialze hardware.
 * 
 * @return true 
 * @return false 
 */
bool SerialBusQueue::deinit(void){
  if(this->mSerialBus.isInit())
    this->abortAll();
  
  return this->mSerialBus.deinit();
}

/**
 * @brief initialze hardware;
 * 
 * @return true 
 * @return false 
 */
bool SerialBusQueue::init(void){
  return this->mSerialBus.init();
}

/**
 * @brief get hardware initialzed status.
 * 
 * @return true not init
 * @return false initd
 */
bool SerialBusQueue::isInit(void){
  return this->mSerialBus.isInit();
}

/* ****************************************************************************************
 * Public Method <Override> - hal::serial::SerialBusControl
 */
/**
 * @brief 
 * 
 * @return uint32_t 
 */
uint32_t SerialBusQueue::clockRate(void){
  return this->mSerialBus.clockRate();
}

/**
 * @brief 
 * 
 * @param clock 
 * @return uint32_t 
 */
uint32_t SerialBusQueue::clockRate(uint32_t clock){
  return this->mSerialBus.clockRate(clock);
}

/* ****************************************************************************************
 * Public Method <Override> - hal::serial::SerialBusTransfer
 */
/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool SerialBusQueue::abort(void){
  return false;
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool SerialBusQueue::isBusy(void){
  return false;
}

/**
 * @brief 
 * 
 * @param address 
 * @param in
 * @param attachment   
 * @param event 
 */
bool SerialBusQueue::read(uint16_t address, InputBuffer& in, void* attachment, SerialBusEvent* event){
  return false;
}

/**
 * @brief 
 * 
 * @param address 
 * @param out
 * @param attachment                      
 * @param event 
 */
bool SerialBusQueue::write(uint16_t address, OutputBuffer& out, void* attachment, SerialBusEvent* event){
  return false;
}

/**
 * @brief 
 * 
 * @param address 
 * @param out
 * @param in
 * @param attachment                       
 * @param event 
 * @return true 
 * @return false 
 */
bool SerialBusQueue::transfer(uint16_t address, OutputBuffer& out, InputBuffer& in, void* attachment, SerialBusEvent* event){
  return false;
}

/* ****************************************************************************************
 * Public Method <Override> - hal::serial::SerialBusEvent
 */
/**
 * @brief 
 * 
 * @param status handle status
 * @param result 0 = successful, other = remaining byte count.
 * @param attachment user data
 */
void SerialBusQueue::onSerialBusEvent(SerialBusStatus status, int result, void* attachment){
  return;
}

/* ****************************************************************************************
 * Public Method
 */
/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool SerialBusQueue::abortAll(void){
  return false;
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
