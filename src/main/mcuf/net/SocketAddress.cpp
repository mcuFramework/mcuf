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
#include "mcuf/lang/Byte.h"

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
using mcuf::lang::Byte;

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
  char cache[4];
  int head = 0;
  int tail = 0;
  
  for(int i=0; i<4; ++i){
    if(i >= 3)
      tail = static_cast<int32_t>(address.size());
    
    else
      tail = address.indexOf('.', head);
    
    if(tail - head > 4)
      break;
    
    int len = address.copyTo(cache, 0, head, static_cast<int>(tail - head));
    cache[len] = 0x00;
    this->mSocketAddress[i] = Byte::valueOf(cache);
    
    head = tail + 1;
  }
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
