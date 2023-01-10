/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_574AD0C2_CCFB_47E3_8947_EF72B95F966B
#define MCUF_574AD0C2_CCFB_47E3_8947_EF72B95F966B

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf/mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/OutputBuffer.h"
#include "mcuf/InputBuffer.h"

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  interface Buffer;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::Buffer extends 
mcuf::OutputBuffer, 
mcuf::InputBuffer{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   */
  virtual void flush(void) abstract;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_574AD0C2_CCFB_47E3_8947_EF72B95F966B */
