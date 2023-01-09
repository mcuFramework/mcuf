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
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf\Interface.h"
#include "mcuf\ByteBuffer.h"

//-----------------------------------------------------------------------------------------
#include "hal\SerialBusStatus.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
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
   * @brief 
   * 
   * @param status handle status
   * @param result 0 = successful, other = remaining byte count.
   * @param attachment user data
   */
  virtual void onSerialBusEvent(hal::SerialBusStatus status, 
                                int result,
                                void* attachment) abstract;
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_F948F450_E9C5_4979_8B11_1563B5BE65F6 */
