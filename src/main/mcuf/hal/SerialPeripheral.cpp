/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "SerialPeripheral.hpp"

/* ****************************************************************************************
 * Using
 */  
using mcuf::hal::SerialPeripheral;
using mcuf::lang::Pointer;

/* ****************************************************************************************
 * Construct Method
 */

/**
 * 
 */
SerialPeripheral::Packet::Packet(void){
  this->mTransferPointer = nullptr;
  this->mReceiverPointer = nullptr;
  this->mLength = 0;
  this->mDummy = 0;
}

/**
 * 
 */
SerialPeripheral::Packet::Packet(void* transferPointer, void* receiverPointer, 
                                 uint16_t length, uint16_t dummy){

  this->mTransferPointer = transferPointer;
  this->mReceiverPointer = receiverPointer;
  this->mLength = length;
  this->mDummy = dummy;
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
 * 
 */
uint16_t SerialPeripheral::Packet::dummy(void){
  return this->mDummy;
}

/**
 * 
 */
SerialPeripheral::Packet* SerialPeripheral::Packet::dummy(uint16_t dummy){
  this->mDummy = dummy;
  return this;
}

/**
 * 
 */
uint16_t SerialPeripheral::Packet::length(void){
  return this->mLength;
}

/**
 * 
 */
SerialPeripheral::Packet* SerialPeripheral::Packet::length(uint16_t length){
  this->mLength = length;
  return this;
}

/**
 * 
 */
void* SerialPeripheral::Packet::ReceiverPointer(void){
  return this->mReceiverPointer;
}

/**
 * 
 */
SerialPeripheral::Packet* SerialPeripheral::Packet::ReceiverPointer(void* pointer){
  this->mReceiverPointer = pointer;
  return this;
}

/**
 * 
 */
SerialPeripheral::Packet* SerialPeripheral::Packet::ReceiverPointer(mcuf::lang::Pointer pointer){
  this->mReceiverPointer = pointer.pointer();
  return this;
}

/**
 * 
 */
void* SerialPeripheral::Packet::TransferPointer(void){
  return this->mTransferPointer;
}

/**
 * 
 */
SerialPeripheral::Packet* SerialPeripheral::Packet::TransferPointer(void* pointer){
  this->mTransferPointer = pointer;
  return this;
}

/**
 * 
 */
SerialPeripheral::Packet* SerialPeripheral::Packet::TransferPointer(Pointer pointer){
  this->mTransferPointer = pointer.pointer();
  return this;
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
