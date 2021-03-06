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

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/io/ByteBuffer.h"
#include "hal/storage/FlashStorageStatus.h"
#include "mcuf/lang/Interface.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{  
  namespace storage{
    interface FlashStorageEvent;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::storage::FlashStorageEvent extends virtual mcuf::lang::Interface{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @param status 
   * @param byteBuffer 
   */
  virtual void onFlashStorageEvent(hal::storage::FlashStorageStatus status, 
                                   int result,
                                   void* attachment) abstract;

};

#endif /* MCUF_D9F1072A_3AF8_4A2E_9CFA_09471F1D5AA0 */
