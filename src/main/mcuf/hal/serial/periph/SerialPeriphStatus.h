/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_AD956F3B_4912_4A25_945A_FA7139E16CEA
#define MCUF_AD956F3B_4912_4A25_945A_FA7139E16CEA

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
        enum struct SerialPeriphStatus : char;
      }
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
enum struct mcuf::hal::serial::periph::SerialPeriphStatus : char{
  SUCCESSFUL,
  FAIL,
  ABORT,
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_AD956F3B_4912_4A25_945A_FA7139E16CEA */
