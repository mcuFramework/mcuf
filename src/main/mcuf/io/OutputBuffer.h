/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_866C8352_DB87_4C00_A483_93113124908D
#define MCUF_866C8352_DB87_4C00_A483_93113124908D

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
  virtual int remaining(void) const abstract;

  /**
   * @brief pop buffer byte non blocking.
   * 
   * @param result 
   * @return true has data in buffer.
   * @return false no data in buffer.
   */
  virtual bool putByte(const char result) abstract;

  /**
   * @brief 
   * 
   * @param byteBuffer 
   * @return int 
   */
  virtual int put(mcuf::io::InputBuffer& inputBuffer) abstract;

  /**
   * @brief 
   * 
   * @param buffer 
   * @param bufferSize 
   * @return int 
   */
  virtual int put(const void* buffer, int bufferSize) abstract;
};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_866C8352_DB87_4C00_A483_93113124908D */
