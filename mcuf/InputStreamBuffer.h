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


//-----------------------------------------------------------------------------------------
#include "./OutputBuffer.h"
#include "./InputStream.h"


/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  interface InputStreamBuffer;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::InputStreamBuffer extends mcuf::InputStream{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief Get the Output Buffer object
   * 
   * @return mcuf::OutputBuffer& 
   */
  virtual mcuf::OutputBuffer& getOutputBuffer(void) abstract;
  
};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_D4F7F817_17A8_4EC2_8B3B_F96F763689AC */
