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
#include "hal/serial/SerialBusEvent.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::io::SerialBusQueue;
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
Fifo(queueSize, sizeof(SerialBusQueue::Packet)),
mSerialBus(serialBus){
  this->mPacket.reserved = 0;
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
  return this->mSerialBus.abort();
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool SerialBusQueue::isBusy(void){
  return this->isFull();
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
  Packet packet;
  packet.reserved = 0;
  packet.address = address;
  packet.in = &in;
  packet.out = nullptr;
  packet.attachment = attachment;
  packet.event = event;
  
  return this->handlerConfig(packet);
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
  Packet packet;
  packet.reserved = 0;
  packet.address = address;
  packet.in = nullptr;
  packet.out = &out;
  packet.attachment = attachment;
  packet.event = event;
  
  return this->handlerConfig(packet);
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
  Packet packet;
  packet.reserved = 0;
  packet.address = address;
  packet.in = &in;
  packet.out = &out;
  packet.attachment = attachment;
  packet.event = event;
  
  return this->handlerConfig(packet);
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
  Packet p = this->mPacket;
  this->mPacket.reserved = 0;
  
  if(this->isEmpty() == false){
    Packet packet;
    
    while(true){
      if(this->popTail(&packet) == false)
        break;

      if(this->handlerConfig(packet) == false)
        this->executeFail(p);
      
      else
        break;
        
    }    
  }
  
  if(p.event == nullptr)
    return;
  
  p.event->onSerialBusEvent(status, result, attachment);
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
void SerialBusQueue::abortAll(void){
  this->abort();
  
  while(true){
    Packet p;
    if(this->popTail(&p) == false)
      break;
    
    this->executeFail(p);
  }
}

/**
 * @brief 
 * 
 * @param packet 
 * @return true 
 * @return false 
 */
bool SerialBusQueue::handlerConfig(Packet& packet){
  if(this->mPacket.reserved != 0)
    return this->insertHead(&packet);
    
  this->mPacket = packet;
  this->mPacket.reserved = 0xFFFF;
  
  bool result = false;
 
  if((this->mPacket.out != nullptr) && (this->mPacket.in != nullptr))
    result = this->mSerialBus.transfer(this->mPacket.address, *this->mPacket.out, *this->mPacket.in, this->mPacket.attachment, this);
      
  else if(this->mPacket.out != nullptr)
    result = this->mSerialBus.write(this->mPacket.address, *this->mPacket.out, this->mPacket.attachment, this);
  
  else if(this->mPacket.in != nullptr)
    result = this->mSerialBus.read(this->mPacket.address, *this->mPacket.in, this->mPacket.attachment, this);
  
  else
    result = false;
  
  if(result == false)
    this->mPacket.reserved = 0;
      
  return result;
}

/**
 * @brief 
 * 
 * @param packet 
 */
void SerialBusQueue::executeFail(Packet& packet){
  if(packet.event != nullptr){
    if((packet.out != nullptr) && (packet.in != nullptr))
      packet.event->onSerialBusEvent(SerialBusStatus::TRANSFER_FAIL_WRITE, 0, packet.attachment);
        
    else if(packet.out != nullptr)
      packet.event->onSerialBusEvent(SerialBusStatus::WRITE_FAIL, 0, packet.attachment);
        
    else if(packet.in != nullptr)
      packet.event->onSerialBusEvent(SerialBusStatus::READ_FAIL, 0, packet.attachment);
       
  }
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
