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
#include "../mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "./ByteBuffer.h"
#include "../Interface.h"

//-----------------------------------------------------------------------------------------
#include "./FlashStorageStatus.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace mcuf::hal{  
  interface FlashStorageEvent;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::FlashStorageEvent extends virtual mcuf::Interface{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @param status 
   * @param byteBuffer 
   */
  virtual void onFlashStorageEvent(mcuf::hal::FlashStorageStatus status, 
                                   int result,
                                   void* attachment) abstract;

};

#endif /* MCUF_D9F1072A_3AF8_4A2E_9CFA_09471F1D5AA0 */
