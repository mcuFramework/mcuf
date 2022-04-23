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
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/io/InputBuffer.h"
#include "mcuf/io/OutputBuffer.h"

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  namespace io{
    interface Buffer;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::io::Buffer extends mcuf::io::InputBuffer, 
  mcuf::io::OutputBuffer{

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
