/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_C8AC42CA_904A_4527_85EE_B491AEEBF6D9
#define MCUF_C8AC42CA_904A_4527_85EE_B491AEEBF6D9

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "../mcuf/package-info.h"

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
  enum struct SerialPeriphMode : char;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
enum struct hal::SerialPeriphMode : char{
  MSB_HIGH_FIRST,
  MSB_HIGH_SECOND,
  MSB_LOW_FIRST,
  MSB_LOW_SECOND,
  LSB_HIGH_FIRST,
  LSB_HIGH_SECOND,
  LSB_LOW_FIRST,
  LSB_LOW_SECOND
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_C8AC42CA_904A_4527_85EE_B491AEEBF6D9 */
