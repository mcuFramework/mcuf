/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_D16651C7_B337_4816_97E6_0AAFC016A73D
#define MCUF_D16651C7_B337_4816_97E6_0AAFC016A73D

/* ****************************************************************************************
 * Include
 */
#include "mcuf_base.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace hal{
  namespace serial{
    enum struct SerialPeriphPhase : char;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
enum struct hal::serial::SerialPeriphPhase : char{
    FIRST_EDGE,
    SECOND_EDGE
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_D16651C7_B337_4816_97E6_0AAFC016A73D */
