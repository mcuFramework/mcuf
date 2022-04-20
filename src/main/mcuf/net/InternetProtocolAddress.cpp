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
#include "mcuf/net/InternetProtocolAddress.h"
#include "mcuf/lang/Byte.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::net::InternetProtocolAddress;
using mcuf::lang::String;
using mcuf::lang::Byte;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Internet Protocol Address object
 * 
 */
InternetProtocolAddress::InternetProtocolAddress(void){
  *reinterpret_cast<uint32_t*>(this->mInternetProtocolAddress) = 0;
  return;
}

/**
 * @brief Construct a new Internet Protocol Address object
 * 
 * @param address 
 */
InternetProtocolAddress::InternetProtocolAddress(const uint32_t address){
  this->setAddress(address);
  return;
}

/**
 * @brief Construct a new Internet Protocol Address object
 * 
 * @param a1 
 * @param a2 
 * @param a3 
 * @param a4 
 */
InternetProtocolAddress::InternetProtocolAddress(const uint8_t a1, const uint8_t a2, const uint8_t a3, const uint8_t a4){
  this->setAddress(a1, a2, a3, a4);
  return;
}

/**
 * @brief Construct a new Internet Protocol Address object
 * 
 * @param address 
 */
InternetProtocolAddress::InternetProtocolAddress(const uint8_t address[4]){
  this->setAddress(address);
}

/**
 * @brief Construct a new Internet Protocol Address object
 * 
 * @param address 
 */
InternetProtocolAddress::InternetProtocolAddress(const String& address){
  this->setAddress(address);
  return;
}

/**
 * @brief Destroy the Internet Protocol Address object
 * 
 */
InternetProtocolAddress::~InternetProtocolAddress(void){
  *reinterpret_cast<int*>(this->mInternetProtocolAddress) = 0;
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
/**
 * @brief Get the Address object
 * 
 * @return int 
 */
uint32_t InternetProtocolAddress::getAddress(void){
  return *reinterpret_cast<uint32_t*>(this->mInternetProtocolAddress);
}
  
/**
 * @brief Get the Address object
 * 
 * @param a1 
 * @param a2 
 * @param a3 
 * @param a4 
 */
void InternetProtocolAddress::getAddress(uint8_t& a1, uint8_t& a2, uint8_t& a3, uint8_t& a4){
  a1 = this->mInternetProtocolAddress[0];
  a2 = this->mInternetProtocolAddress[1];
  a3 = this->mInternetProtocolAddress[2];
  a4 = this->mInternetProtocolAddress[3];
  return;
}
    
/**
 * @brief Get the Address object
 * 
 * @param result 
 */
void InternetProtocolAddress::getAddress(uint8_t* result){
  *reinterpret_cast<uint32_t*>(result) = *reinterpret_cast<uint32_t*>(this->mInternetProtocolAddress);
  return;
}

/**
 * @brief Get the Address object
 * 
 * @param address 
 */
void InternetProtocolAddress::getAddress(mcuf::lang::String& result){
  result.format("%d.%d.%d.%d\0", this->mInternetProtocolAddress[0], 
                                 this->mInternetProtocolAddress[1], 
                                 this->mInternetProtocolAddress[2], 
                                 this->mInternetProtocolAddress[3]);
  return;
}

/**
 * @brief 
 * 
 * @return mcuf::lang::String 
 */
String InternetProtocolAddress::toString(void){
  String result = String(16);
  this->getAddress(result);                                 
  return result;
}

/**
 * @brief Set the Address object
 * 
 * @param address 
 */
void InternetProtocolAddress::setAddress(uint32_t address){
  *reinterpret_cast<uint32_t*>(this->mInternetProtocolAddress) = address;
  return;
}

/**
 * @brief Set the Address object
 * 
 * @param a1 
 * @param a2 
 * @param a3 
 * @param a4 
 */
void InternetProtocolAddress::setAddress(const uint8_t a1, const uint8_t a2, const uint8_t a3, const uint8_t a4){
  this->mInternetProtocolAddress[0] = a1;
  this->mInternetProtocolAddress[1] = a2;
  this->mInternetProtocolAddress[2] = a3;
  this->mInternetProtocolAddress[3] = a4;
  return;  
}

/**
 * @brief Set the Address object
 * 
 * @param address 
 */
void InternetProtocolAddress::setAddress(const uint8_t address[4]){
  *reinterpret_cast<uint32_t*>(this->mInternetProtocolAddress) = *reinterpret_cast<const uint32_t*>(address);
  return;
}

/**
 * @brief Set the Address object
 * 
 * @param address 
 */
void InternetProtocolAddress::setAddress(const mcuf::lang::String& address){
  *reinterpret_cast<uint32_t*>(this->mInternetProtocolAddress) = 0;
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
    this->mInternetProtocolAddress[i] = Byte::valueOf(cache);
    
    head = tail + 1;
  }
  return;
}

/**
 * @brief 
 * 
 * @return true 
 * @return false 
 */
bool InternetProtocolAddress::isNull(void){
  return (*reinterpret_cast<uint32_t*>(this->mInternetProtocolAddress) == 0);
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
