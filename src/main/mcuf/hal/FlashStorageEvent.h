/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_D9F1072A_3AF8_4A2E_9CFA_09471F1D5AA0
#define MCUF_D9F1072A_3AF8_4A2E_9CFA_09471F1D5AA0

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/io/ByteBuffer.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{  
    interface FlashStorageEvent;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::FlashStorageEvent{

  /* **************************************************************************************
   * enum FlashStorageStatus
   */
  enum FlashStorageStatus{
    HAL_FLASHSOTRAGE_WRITE_SUCCESSFUL,
    HAL_FLASHSOTRAGE_WRITE_FAIL,
    HAL_FLASHSOTRAGE_READ_SUCCESSFUL,
    HAL_FLASHSOTRAGE_READ_FAIL,
  };

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @param status 
   * @param byteBuffer 
   */
  virtual void onFlashStorageEvent(FlashStorageStatus status, mcuf::io::ByteBuffer* byteBuffer) abstract;

};

#endif/* MCUF_D9F1072A_3AF8_4A2E_9CFA_09471F1D5AA0 */
