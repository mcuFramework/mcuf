/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_F56A812F_5E00_4EFF_8297_AB5B36B7100E
#define MCUF_F56A812F_5E00_4EFF_8297_AB5B36B7100E

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf/io/ByteBuffer.h"
#include "mcuf/hal/storage/flash/FlashStorageEvent.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{  
    namespace storage{
      namespace flash{
        interface FlashStorageControl;
      }
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::storage::flash::FlashStorageControl{

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
  virtual bool write(mcuf::io::ByteBuffer* bytebuffer, 
                     mcuf::hal::storage::flash::FlashStorageEvent* event) abstract;

  /**
   * @brief 
   * 
   * @param bytebuffer 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool read(mcuf::io::ByteBuffer* bytebuffer, 
                    mcuf::hal::storage::flash::FlashStorageEvent* event) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_F56A812F_5E00_4EFF_8297_AB5B36B7100E */
