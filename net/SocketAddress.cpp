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
#include "./../numb/package-info.h"

//-----------------------------------------------------------------------------------------
#include "./SocketAddress.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using net::SocketAddress;
using mcuf::Strings;
using numb::Byte;
using net::InternetProtocolAddress;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Socket Address object
 * 
 */
SocketAddress::SocketAddress(void) : 
InternetProtocolAddress(){
  this->mPort = 0;
  return;
}

/**
 * @brief Construct a new Socket Address object
 * 
 * @param internetProtocolAddress 
 * @param port 
 */
SocketAddress::SocketAddress(const InternetProtocolAddress& internetProtocolAddress, const uint16_t port):
InternetProtocolAddress(internetProtocolAddress){
  this->mPort = port;
  return;
}

/**
 * @brief Construct a new Socket Address object
 * 
 * @param address 
 * @param port 
 */
SocketAddress::SocketAddress(const uint32_t address, const uint16_t port) : 
InternetProtocolAddress(address){
  this->mPort = port;
  return;
}

/**
 * @brief Construct a new Socket Address:: Socket Address object
 * 
 * @param address 
 * @param port 
 */
SocketAddress::SocketAddress(const uint8_t a1, const uint8_t a2, const uint8_t a3, const uint8_t a4, const uint16_t port) : 
InternetProtocolAddress(a1, a2, a3, a4){
  this->mPort = port;
  return;
}

/**
 * @brief Construct a new Socket Address object
 * 
 * @param address 
 * @param port 
 */
SocketAddress::SocketAddress(const uint8_t address[4], const uint16_t port) : 
InternetProtocolAddress(address){
  this->mPort = port;
  return;
}

/**
 * @brief Construct a new Socket Address object
 * 
 * @param address 
 * @param port 
 */
SocketAddress::SocketAddress(const Strings& address, const uint16_t port) : 
InternetProtocolAddress(address){
  this->mPort = port;
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
 * Public Method <Override> - net::InternetProtocolAddress
 */

/**
 * @brief 
 * 
 * @return mcuf::Strings 
 */
Strings SocketAddress::toStrings(void) const{
  Strings result = Strings(22);
  this->getSocketAddress(result);
  return result;
}

/* ****************************************************************************************
 * Public Method
 */

/**
 * @brief Get the Port object
 * 
 * @return uint16_t 
 */
uint16_t SocketAddress::getPort(void) const{
  return this->mPort;
}

/**
 * @brief Get the Socket Address object
 * 
 * @param result 
 */
void SocketAddress::getSocketAddress(mcuf::Strings& result) const{
  result.format("%d.%d.%d.%d:%d\0", this->mInternetProtocolAddress[0], 
                                    this->mInternetProtocolAddress[1], 
                                    this->mInternetProtocolAddress[2], 
                                    this->mInternetProtocolAddress[3],
                                    this->mPort);
  return; 
}

/**
 * @brief Set the Port object
 * 
 * @param port 
 */
void SocketAddress::setPort(uint16_t port){
  this->mPort = port;
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