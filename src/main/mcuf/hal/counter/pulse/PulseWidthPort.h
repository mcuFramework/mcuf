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
#include "mcuf/hal/Base.h"
#include "mcuf/hal/counter/pulse/PulseWidthPortControl.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  namespace hal{
    namespace counter{
      namespace pulse{
        interface PulseWidthPort;
      }
    }
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::hal::counter::pulse::PulseWidthPort extends 
  mcuf::hal::Base,
  mcuf::hal::counter::pulse::PulseWidthPortControl{

  /* **************************************************************************************
   * Method
   */

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_9C2CA0D2_D921_428A_B411_A41968013B4F */
