/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_BA8DBAF0_DCE9_4F33_B776_7C5470172961
#define MCUF_BA8DBAF0_DCE9_4F33_B776_7C5470172961

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf/mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/Interface.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/hal/EdgeTriggerStatus.h"

/* ****************************************************************************************
 * Namespace
 */

namespace mcuf::hal{
  interface EdgeTriggerEvent;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::EdgeTriggerEvent extends virtual mcuf::Interface{
  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @param status 
   */
  virtual void onEdgeTriggerEvent(mcuf::hal::EdgeTriggerStatus status) abstract;
  
};



/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_BA8DBAF0_DCE9_4F33_B776_7C5470172961 */
