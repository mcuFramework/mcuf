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

namespace hal{
  namespace serial{
    enum struct SerialPeriphPolarity : char;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
enum struct hal::serial::SerialPeriphPolarity : char{
  ACTIVE_HIGH,
  ACTIVE_LOW 
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_CDD21DA5_6229_4F95_B7D7_255A5FC8B894 */
