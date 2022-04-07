/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_CB9A04D9_33CB_4041_B02B_A0E46058BC54
#define MCUF_CB9A04D9_33CB_4041_B02B_A0E46058BC54

/* ****************************************************************************************
 * Include
 */
#include "mcuf_base.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{
  namespace serial{
    enum struct SerialPortStatus : char;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
enum struct hal::serial::SerialPortStatus : char{
  READ_SUCCESSFUL,
  READ_FAIL,
  READ_ABROT,
  WRITE_SUCCESSFUL,
  WRITE_FAIL,
  WRITE_ABROT,

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_CB9A04D9_33CB_4041_B02B_A0E46058BC54 */
