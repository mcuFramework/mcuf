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
#include "mcuf/net/SocketAddress.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::net::SocketAddress;
using mcuf::lang::String;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Socket Address:: Socket Address object
 * 
 * @param address 
 * @param port 
 */
SocketAddress::SocketAddress(uint8_t address[4], uint16_t port){
  this->mSocketAddress[0] = address[0];
  this->mSocketAddress[1] = address[1];
  this->mSocketAddress[2] = address[2];
  this->mSocketAddress[3] = address[3];
  this->mPort = port;
}

/**
 * @brief Construct a new Socket Address object
 * 
 * @param address 
 * @param port 
 */
SocketAddress::SocketAddress(const String& address, uint16_t port){
  *reinterpret_cast<int*>(this->mSocketAddress) = 0;
  String addr = address.clone(16);
  char shift = 0;
}

/**
 * @brief Destroy the Socket Address object
 * 
 */
SocketAddress::~SocketAddress(void){
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
