/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_5FA35131_C5D9_4E33_8EB1_69BFC20000FB
#define MCUF_5FA35131_C5D9_4E33_8EB1_69BFC20000FB

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf_base.h"

//-----------------------------------------------------------------------------------------
#include "mcuf/io/InputStreamBuffer.h"
#include "mcuf/io/PrintStream.h"
#include "mcuf/lang/Interface.h"


/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  namespace io{
    interface Console;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::io::Console extends mcuf::lang::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @return mcuf::io::PrintStream& 
   */
  virtual mcuf::io::PrintStream& out(void) abstract;

  /**
   * @brief 
   * 
   * @return mcuf::io::InputStreamBuffer& 
   */
  virtual mcuf::io::InputStreamBuffer& in(void) abstract;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_5FA35131_C5D9_4E33_8EB1_69BFC20000FB */
