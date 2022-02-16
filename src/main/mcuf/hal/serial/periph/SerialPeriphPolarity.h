/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_CDD21DA5_6229_4F95_B7D7_255A5FC8B894
#define MCUF_CDD21DA5_6229_4F95_B7D7_255A5FC8B894

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
      namespace periph{
        enum struct SerialPeriphPolarity : char;
      }
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
enum struct mcuf::hal::serial::periph::SerialPeriphPolarity : char{
  ACTIVE_HIGH,
  ACTIVE_LOW 
};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_CDD21DA5_6229_4F95_B7D7_255A5FC8B894 */