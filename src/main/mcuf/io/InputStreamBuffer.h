/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_D4F7F817_17A8_4EC2_8B3B_F96F763689AC
#define MCUF_D4F7F817_17A8_4EC2_8B3B_F96F763689AC

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/io/OutputBuffer.h"
#include "mcuf/io/InputStream.h"


/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  namespace io{
    interface InputStreamBuffer;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::io::InputStreamBuffer extends mcuf::io::InputStream{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief Get the Output Buffer object
   * 
   * @return mcuf::io::OutputBuffer& 
   */
  virtual mcuf::io::OutputBuffer& getOutputBuffer(void) abstract;
  
};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_D4F7F817_17A8_4EC2_8B3B_F96F763689AC */
