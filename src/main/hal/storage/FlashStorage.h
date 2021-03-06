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
#include "hal/Base.h"
#include "mcuf/io/ByteBuffer.h"
#include "hal/storage/FlashStorageControl.h"

/* ****************************************************************************************
 * Namespace
 */  

namespace hal{  
  namespace storage{
    interface FlashStorage;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface hal::storage::FlashStorage extends 
hal::Base,
hal::storage::FlashStorageControl{

  /* **************************************************************************************
   * Method
   */
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_DE1F2BD6_EFF1_4410_A5B2_5A1C14D00695 */
