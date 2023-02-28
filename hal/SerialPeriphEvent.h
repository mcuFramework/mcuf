/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_B4701C5A_F9C9_4C60_AF27_09CD2013EE9A
#define MCUF_B4701C5A_F9C9_4C60_AF27_09CD2013EE9A

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "../mcuf/mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "../mcuf/ByteBuffer.h"
#include "../mcuf/Interface.h"

//-----------------------------------------------------------------------------------------
#include "./SerialPeriphStatus.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace mcuf::hal{
  interface SerialPeriphEvent;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::SerialPeriphEvent extends virtual mcuf::Interface{
  
  /* **************************************************************************************
   * Method
   */  
  
  /**
   * @brief 
   * 
   * @param status 
   * @param transfer 
   * @param receiver 
   */
  virtual void onSerialPeriphEvent(mcuf::hal::SerialPeriphStatus status, 
                                   mcuf::ByteBuffer* transfer,
                                   mcuf::ByteBuffer* receiver) abstract;
};


/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_B4701C5A_F9C9_4C60_AF27_09CD2013EE9A */
