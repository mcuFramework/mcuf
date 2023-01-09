/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_A0D6B8FB_0339_412F_8DD0_D6C82479607C
#define MCUF_A0D6B8FB_0339_412F_8DD0_D6C82479607C

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf\ByteBuffer.h"
#include "mcuf\Interface.h"

//-----------------------------------------------------------------------------------------
#include "hal\Base.h"
#include "hal\SerialPeriphEvent.h"
#include "hal\SerialPeriphPacket.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
  interface SerialPeriphTransfer;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::SerialPeriphTransfer extends virtual mcuf::Interface{

  /* **************************************************************************************
   * Method
   */
   
  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool abort(void) abstract;
  
  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool isBusy(void) abstract;

  /**
   * @brief 
   * 
   * @param chipSelect 
   * @param packet 
   * @param event 
   * @return true 
   * @return false 
   */
  virtual bool transfer(uint32_t chipSelect, 
                        hal::SerialPeriphPacket* packet,
                        hal::SerialPeriphEvent* event) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_A0D6B8FB_0339_412F_8DD0_D6C82479607C */
