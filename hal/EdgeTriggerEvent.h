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
#include "../mcuf/package-info.h"

//-----------------------------------------------------------------------------------------
#include "../mcuf/Interface.h"

//-----------------------------------------------------------------------------------------
#include "./EdgeTriggerStatus.h"

/* ****************************************************************************************
 * Namespace
 */

namespace hal{
  interface EdgeTriggerEvent;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::EdgeTriggerEvent extends virtual mcuf::Interface{
  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @param status 
   */
  virtual void onEdgeTriggerEvent(hal::EdgeTriggerStatus status) abstract;
  
};



/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_BA8DBAF0_DCE9_4F33_B776_7C5470172961 */
