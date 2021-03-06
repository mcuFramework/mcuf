/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_D6F1DE5B_EB64_4F4E_8E76_26C5EE0EF55F
#define MCUF_D6F1DE5B_EB64_4F4E_8E76_26C5EE0EF55F

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
  namespace general{
    enum struct GeneralPinMode : char;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
enum struct hal::general::GeneralPinMode : char{
  NOT_SUPPORT,
  PUSH_PULL,
  PULL_UP,
  PULL_DOWN,
  OPEN_DRAIN
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_D6F1DE5B_EB64_4F4E_8E76_26C5EE0EF55F */
