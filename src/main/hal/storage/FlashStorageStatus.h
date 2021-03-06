/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_DF2D31FA_37AC_4954_9377_E941FAC1AA0E
#define MCUF_DF2D31FA_37AC_4954_9377_E941FAC1AA0E

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
  namespace storage{
    enum struct FlashStorageStatus : char;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
enum struct hal::storage::FlashStorageStatus : char{
  WRITE_SUCCESSFUL,
  WRITE_FAIL,
  READ_SUCCESSFUL,
  READ_FAIL
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_DF2D31FA_37AC_4954_9377_E941FAC1AA0E */
