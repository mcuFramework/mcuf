/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_9C2CA0D2_D921_428A_B411_A41968013B4F
#define MCUF_9C2CA0D2_D921_428A_B411_A41968013B4F

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf/mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/hal/Base.h"
#include "mcuf/hal/PulseWidthPortControl.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */

namespace mcuf::hal{
  interface PulseWidthPort;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::hal::PulseWidthPort extends 
mcuf::hal::Base,
mcuf::hal::PulseWidthPortControl{

  /* **************************************************************************************
   * Method
   */

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_9C2CA0D2_D921_428A_B411_A41968013B4F */
