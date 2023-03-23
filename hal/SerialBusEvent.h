/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_F948F450_E9C5_4979_8B11_1563B5BE65F6
#define MCUF_F948F450_E9C5_4979_8B11_1563B5BE65F6

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "../mcuf/package-info.h"

//-----------------------------------------------------------------------------------------
#include "../mcuf/Interface.h"
#include "../mcuf/ByteBuffer.h"

//-----------------------------------------------------------------------------------------
#include "./SerialBusStatus.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
  interface SerialBus;
  interface SerialBusEvent;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::SerialBusEvent extends virtual mcuf::Interface{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief SerialBus讀取事件
   * 
   * @param status 事件狀態
   * @param serialBus 執行本體
   */
  virtual void onSerialBusEvent(hal::SerialBusStatus status, hal::SerialBus& serialBus) abstract;
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_F948F450_E9C5_4979_8B11_1563B5BE65F6 */
