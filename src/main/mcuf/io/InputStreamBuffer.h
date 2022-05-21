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
interface mcuf::io::InputStreamBuffer extends 
  virtual mcuf::io::OutputBuffer, 
  virtual mcuf::io::InputStream{

  /* **************************************************************************************
   * Method
   */
  using mcuf::io::OutputBuffer::skip;
  using mcuf::io::InputStream::skip;
  
};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_D4F7F817_17A8_4EC2_8B3B_F96F763689AC */
