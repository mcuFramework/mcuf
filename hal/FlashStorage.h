/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_DE1F2BD6_EFF1_4410_A5B2_5A1C14D00695
#define MCUF_DE1F2BD6_EFF1_4410_A5B2_5A1C14D00695

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf/ByteBuffer.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/hal/Base.h"
#include "mcuf/hal/FlashStorageControl.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  

namespace mcuf::hal{  
  interface FlashStorage;
}


/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::hal::FlashStorage extends 
mcuf::hal::Base,
mcuf::hal::FlashStorageControl{

  /* **************************************************************************************
   * Method
   */
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_DE1F2BD6_EFF1_4410_A5B2_5A1C14D00695 */
