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
#include "mcuf\InputStreamBuffer.h"
#include "mcuf\PrintStream.h"
#include "mcuf\Interface.h"


/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  interface Console;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::Console extends virtual mcuf::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @return mcuf::PrintStream& 
   */
  virtual mcuf::PrintStream& out(void) abstract;

  /**
   * @brief 
   * 
   * @return mcuf::InputStreamBuffer& 
   */
  virtual mcuf::InputStreamBuffer& in(void) abstract;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_5FA35131_C5D9_4E33_8EB1_69BFC20000FB */
