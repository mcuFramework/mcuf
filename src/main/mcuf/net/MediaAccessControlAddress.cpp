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

//-----------------------------------------------------------------------------------------
#include "mcuf/net/MediaAccessControlAddress.h"
#include "mcuf/lang/Character.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using mcuf::net::MediaAccessControlAddress;
using mcuf::lang::String;
using mcuf::lang::Character;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/**
 * @brief Construct a new Media Access Control Address object
 * 
 * @param address 
 */
MediaAccessControlAddress::MediaAccessControlAddress(const uint8_t address[6]){
  this->setMediaAccessControlAddress(address);
  return;
}

/**
 * @brief Construct a new Media Access Control Address object
 * 
 * @param address 
 */
MediaAccessControlAddress::MediaAccessControlAddress(const String& address){
  this->setMediaAccessControlAddress(address);
  return;
}

/**
 * @brief Destroy the Media Access Control Address object
 * 
 */
MediaAccessControlAddress::~MediaAccessControlAddress(void){
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
 * @brief Set the Media Access Control Address object
 * 
 * @param address 
 */
void MediaAccessControlAddress::setMediaAccessControlAddress(const uint8_t address[6]){
  memcpy(this->mMediaAccessControlAddress, address, 6);
  return;
}

/**
 * @brief Set the Media Access Control Address object
 * 
 * @param address 
 */
void MediaAccessControlAddress::setMediaAccessControlAddress(const mcuf::lang::String& address){
  if(address.size() < 17){
    memset(this->mMediaAccessControlAddress, 0x00, 6);
    return;
  }
  
  for(uint8_t i=0, shift = 0; i<6; ++i, shift += 3){
    this->mMediaAccessControlAddress[i] = Character::hexCharToChar(address[shift], address[shift+1]);
  }
  return;
}

/**
 * @brief Get the Media Access Control Address object
 * 
 * @param result 
 */
void MediaAccessControlAddress::getMediaAccessControlAddress(uint8_t* result){
  memcpy(result, this->mMediaAccessControlAddress, 6);
  return;
}
/**
 * @brief Get the Media Access Control Address object
 * 
 * @param result 
 */
void MediaAccessControlAddress::getMediaAccessControlAddress(mcuf::lang::String& result){
  result.format("%02x:%02x:%02x:%02x:%02x:%02x\0", this->mMediaAccessControlAddress[0]
                                                 , this->mMediaAccessControlAddress[1]
                                                 , this->mMediaAccessControlAddress[2]
                                                 , this->mMediaAccessControlAddress[3]
                                                 , this->mMediaAccessControlAddress[4]
                                                 , this->mMediaAccessControlAddress[5]);
  return;
}

/**
 * @brief 
 * 
 * @return mcuf::lang::String 
 */
String MediaAccessControlAddress::toString(void){
  String result = String(18);
  this->getMediaAccessControlAddress(result);
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
