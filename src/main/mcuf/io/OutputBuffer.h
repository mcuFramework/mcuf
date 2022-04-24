/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_739FA0D6_740F_4CA0_975C_FD713D983D41
#define MCUF_739FA0D6_740F_4CA0_975C_FD713D983D41

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"
//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  namespace io{
    interface OutputBuffer;
    interface InputBuffer;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::io::OutputBuffer{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @return int 
   */
  virtual int avariable(void) const abstract;

  /**
   * @brief pop buffer byte non blocking.
   * 
   * @param result 
   * @return true has data in buffer.
   * @return false no data in buffer.
   */
  virtual bool getByte(char& result) abstract;

  /**
   * @brief 
   * 
   * @param byteBuffer 
   * @return int 
   */
  virtual int get(mcuf::io::InputBuffer& inputBuffer) abstract;

  /**
   * @brief 
   * 
   * @param buffer 
   * @param bufferSize 
   * @return int 
   */
  virtual int get(void* buffer, int bufferSize) abstract;

  /**
   * @brief 
   * 
   * @param value 
   * @return int 
   */
  virtual int skip(int value) abstract;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_739FA0D6_740F_4CA0_975C_FD713D983D41 */
