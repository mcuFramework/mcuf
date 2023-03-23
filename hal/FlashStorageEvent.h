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
#include "../mcuf/package-info.h"

//-----------------------------------------------------------------------------------------
#include "../mcuf/Interface.h"

//-----------------------------------------------------------------------------------------
#include "./FlashStorageStatus.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
  interface FlashStorageEvent;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::FlashStorageEvent extends virtual mcuf::Interface{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @param status 
   * @param flashStorage 
   */
  virtual void onFlashStorageEvent(hal::FlashStorageStatus status) abstract;

};

#endif /* MCUF_D9F1072A_3AF8_4A2E_9CFA_09471F1D5AA0 */
