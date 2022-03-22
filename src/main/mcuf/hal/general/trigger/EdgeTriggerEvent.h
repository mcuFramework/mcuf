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
#include "mcuf/hal/general/trigger/EdgeTriggerStatus.h"

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  namespace hal{
    namespace general{
      namespace trigger{
        interface EdgeTriggerEvent;
      }
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::general::trigger::EdgeTriggerEvent{
  
  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @param status 
   */
  virtual void onEdgeTriggerEvent(mcuf::hal::general::trigger::EdgeTriggerStatus status) abstract;
  
};



/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_BA8DBAF0_DCE9_4F33_B776_7C5470172961 */
