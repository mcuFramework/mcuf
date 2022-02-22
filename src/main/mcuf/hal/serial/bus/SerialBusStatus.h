/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_B5F2B33F_CF53_4949_8CAE_65784F1DA1C6
#define MCUF_B5F2B33F_CF53_4949_8CAE_65784F1DA1C6

/* ****************************************************************************************
 * Include
 */
#include "mcuf_base.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    namespace serial{
      namespace bus{
        enum struct SerialBusStatus : char;
      }
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
enum struct mcuf::hal::serial::bus::SerialBusStatus : char{
  WRITE_SUCCESSFUL,
  WRITE_FAIL,
  READ_SUCCESSFUL,
  READ_FAIL, 
};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_B5F2B33F_CF53_4949_8CAE_65784F1DA1C6 */
