/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_33288B9C_6095_4B26_9F88_332BF138D71A
#define MCUF_33288B9C_6095_4B26_9F88_332BF138D71A

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/io/InputBuffer.h"
#include "mcuf/io/OutputStream.h"

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  namespace io{
    interface OutputStreamBuffer;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::io::OutputStreamBuffer extends mcuf::io::OutputStream{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief Get the Input Buffer object
   * 
   * @return mcuf::io::InputBuffer& 
   */
  virtual mcuf::io::InputBuffer& getInputBuffer(void) abstract;
  
};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_33288B9C_6095_4B26_9F88_332BF138D71A */
