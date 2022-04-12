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
  memcpy(this->mMediaAccessControlAddress, address, 6);
}

/**
 * @brief Construct a new Media Access Control Address object
 * 
 * @param address 
 */
MediaAccessControlAddress::MediaAccessControlAddress(const String& address){
  if(address.size() != 17){
    memset(this->mMediaAccessControlAddress, 0x00, 6);
    return;
  }
  
  for(uint8_t i=0, shift = 0; i<6; ++i, shift += 3){
    this->mMediaAccessControlAddress[i] = Character::hexCharToChar(address[shift], address[shift+1]);
  }
}

/**
 * @brief Destroy the Media Access Control Address object
 * 
 */
MediaAccessControlAddress::~MediaAccessControlAddress(void){
  
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
