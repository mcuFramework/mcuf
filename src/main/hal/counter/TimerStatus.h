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

namespace hal{
  namespace counter{
    enum struct TimerStatus : char;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
enum struct hal::counter::TimerStatus : char{
  TRIGGER,
  CANCEL
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_AFC4FE87_30BB_41E2_AA63_BB2BEA2A3024 */
