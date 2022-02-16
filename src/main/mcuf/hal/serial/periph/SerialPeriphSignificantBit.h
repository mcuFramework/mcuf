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
#include "mcuf_base.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace hal{
    namespace serial{
      namespace periph{
        enum struct SerialPeriphSignificantBit : char;
      }
    }
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
enum struct mcuf::hal::serial::periph::SerialPeriphSignificantBit : char{
  LSB,
  MSB 
};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_C8AC42CA_904A_4527_85EE_B491AEEBF6D9 */