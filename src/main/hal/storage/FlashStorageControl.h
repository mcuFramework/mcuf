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
#include "hal/storage/FlashStorageEvent.h"
#include "mcuf/lang/Interface.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace hal{  
  namespace storage{
    interface FlashStorageControl;    
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::storage::FlashStorageControl extends virtual mcuf::lang::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief Set the Address object
   * 
   * @param address 
   */
  virtual void setAddress(uint32_t address) abstract;

  /**
   * @brief Get the Address object
   * 
   * @return uint32_t 
   */
  virtual uint32_t getAddress(void) abstract;

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
   * @param pageNumber 
   * @return true 
   * @return false 
   */
  virtual bool pageErase(uint32_t pageNumber) abstract;

  /**
   * @brief 
   * 
   * @return uint32_t 
   */
  virtual uint32_t sectorSize(void) abstract;

  /**
   * @brief 
   * 
   * @param sectorNumber 
   * @return true 
   * @return false 
   */
  virtual bool sectorErase(uint32_t sectorNumber) abstract;

  /**
   * @brief 
   * 
   * @param bytebuffer 
   * @param attachment 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool write(mcuf::io::ByteBuffer& bytebuffer, 
                     void* attachment,
                     hal::storage::FlashStorageEvent* event) abstract;

  /**
   * @brief 
   * 
   * @param bytebuffer 
   * @param attachment 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool read(mcuf::io::ByteBuffer& bytebuffer, 
                    void* attachment,
                    hal::storage::FlashStorageEvent* event) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_F56A812F_5E00_4EFF_8297_AB5B36B7100E */
