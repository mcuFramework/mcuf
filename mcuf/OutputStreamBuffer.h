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
#include "mcuf\InputBuffer.h"
#include "mcuf\OutputStream.h"

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  interface OutputStreamBuffer;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::OutputStreamBuffer extends mcuf::OutputStream{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief Get the Input Buffer object
   * 
   * @return mcuf::InputBuffer& 
   */
  virtual mcuf::InputBuffer& getInputBuffer(void) abstract;
  
};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_33288B9C_6095_4B26_9F88_332BF138D71A */
