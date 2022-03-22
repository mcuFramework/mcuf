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
#include "mcuf/hal/storage/flash/FlashStorageStatus.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{  
    namespace storage{
      namespace flash{
        interface FlashStorageEvent;
      }
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::storage::flash::FlashStorageEvent{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @param status 
   * @param byteBuffer 
   */
  virtual void onFlashStorageEvent(mcuf::hal::storage::flash::FlashStorageStatus status, 
                                   mcuf::io::ByteBuffer* byteBuffer) abstract;

};

#endif /* MCUF_D9F1072A_3AF8_4A2E_9CFA_09471F1D5AA0 */
