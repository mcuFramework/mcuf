/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_AFC4FE87_30BB_41E2_AA63_BB2BEA2A3024
#define MCUF_AFC4FE87_30BB_41E2_AA63_BB2BEA2A3024

/* ****************************************************************************************
 * Include
 */
#include "mcuf_base.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    namespace counter{
      namespace timer{
        enum struct TimerStatus : char;
      }
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
enum struct mcuf::hal::counter::timer::TimerStatus : char{
  TRIGGER,
  CANCEL
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_AFC4FE87_30BB_41E2_AA63_BB2BEA2A3024 */
