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
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "hal/general/EdgeTriggerStatus.h"
#include "mcuf/lang/Interface.h"

/* ****************************************************************************************
 * Namespace
 */

namespace hal{
  namespace general{
    interface EdgeTriggerEvent;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::general::EdgeTriggerEvent extends virtual mcuf::lang::Interface{
  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @param status 
   */
  virtual void onEdgeTriggerEvent(hal::general::EdgeTriggerStatus status) abstract;
  
};



/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_BA8DBAF0_DCE9_4F33_B776_7C5470172961 */
