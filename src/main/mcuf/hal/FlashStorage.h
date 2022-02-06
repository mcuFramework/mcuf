/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_DE1F2BD6_EFF1_4410_A5B2_5A1C14D00695
#define MCUF_DE1F2BD6_EFF1_4410_A5B2_5A1C14D00695

/* ****************************************************************************************
 * Include
 */  
#include "mcuf/hal/Base.h"
#include "mcuf/io/ByteBuffer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{  
    interface FlashStorage;
    interface FlashStorageEvent;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::FlashStorage extends mcuf::hal::Base{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @return uint32_t 
   */
  virtual uint32_t flashSize(void) abstract;

  /**
   * @brief 
   * 
   * @return uint32_t 
   */
  virtual uint32_t pageSize(void) abstract;

  /**
   * @brief 
   * 
   * @return uint32_t 
   */
  virtual uint32_t sectorSize(void) abstract;

  /**
   * @brief 
   * 
   * @return uint32_t 
   */
  virtual uint32_t minimumWriteSize(void) abstract;

  /**
   * @brief 
   * 
   * @param bytebuffer 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool write(mcuf::io::ByteBuffer* bytebuffer, FlashStorageEvent* event) abstract;

  /**
   * @brief 
   * 
   * @param bytebuffer 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool read(mcuf::io::ByteBuffer* bytebuffer, FlashStorageEvent* event) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_DE1F2BD6_EFF1_4410_A5B2_5A1C14D00695 */
