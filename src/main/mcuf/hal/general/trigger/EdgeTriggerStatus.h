/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_CB359CE6_8F18_42CE_8BD4_F63868B55909
#define MCUF_CB359CE6_8F18_42CE_8BD4_F63868B55909

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    namespace general{
      namespace trigger{
        enum struct EdgeTriggerStatus : char;
      }
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
enum struct mcuf::hal::general::trigger::EdgeTriggerStatus : char{
  RISE,
  FALL
};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_CB359CE6_8F18_42CE_8BD4_F63868B55909 */
