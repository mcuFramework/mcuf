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
#include "mcuf/lang/Pointer.h"


/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{  
    interface FlashStorage;
  }
}



/* ****************************************************************************************
 * Interface FlashStorage
 */  
interface mcuf::hal::FlashStorage implement mcuf::hal::Base{

  /* **************************************************************************************
   * Subclass
   */
  interface Event;

  /* **************************************************************************************
   * Method
   */

  /**
   * 
   */
  virtual uint32_t flashSize(void) abstract;

  /**
   * 
   */
  virtual uint32_t pageSize(void) abstract;

  /**
   * 
   */
  virtual uint32_t sectorSize(void) abstract;

  /**
   * 
   */
  virtual uint32_t minimumWriteSize(void) abstract;

  /**
   * 
   */
  virtual bool write(mcuf::io::ByteBuffer* bytebuffer, Event* event) abstract;

  /**
   * 
   */
  virtual bool read(mcuf::io::ByteBuffer* bytebuffer, Event* event) abstract;

};



/* ****************************************************************************************
 * Interface FlashStorage::Event
 */  
interface mcuf::hal::FlashStorage::Event{
  /* **************************************************************************************
   * Subclass
   */
  enum Status{
    WRITE_SUCCESSFUL,
    WRITE_FAIL,
    READ_SUCCESSFUL,
    READ_FAIL,
  };

  /* **************************************************************************************
   * Method
   */
  
  /**
   *
   */
  virtual void onFlashStorageEvent(Status status, mcuf::io::ByteBuffer* byteBuffer) abstract;
};


/* *****************************************************************************************
 * End of file
 */ 


#endif/* MCUF_DE1F2BD6_EFF1_4410_A5B2_5A1C14D00695 */
