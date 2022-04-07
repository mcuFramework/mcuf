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
#include "mcuf_base.h"
#include "hal/Base.h"
#include "hal/counter/PulseWidthPortControl.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */

namespace hal{
  namespace counter{
    interface PulseWidthPort;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface hal::counter::PulseWidthPort extends 
  hal::Base,
  hal::counter::PulseWidthPortControl{

  /* **************************************************************************************
   * Method
   */

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_9C2CA0D2_D921_428A_B411_A41968013B4F */
