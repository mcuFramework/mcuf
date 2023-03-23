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
#include "./../mcuf/package-info.h"

//-----------------------------------------------------------------------------------------
#include "./PrintStream.h"

/* ****************************************************************************************
 * Namespace
 */
namespace cli{
  interface Console;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface cli::Console extends virtual mcuf::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   * @return cli::PrintStream& 
   */
  virtual cli::PrintStream& out(void) abstract;

  /**
   * @brief 
   * 
   * @return mcuf::InputStreamBuffer& 
   */
  virtual mcuf::InputStream& in(void) abstract;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_5FA35131_C5D9_4E33_8EB1_69BFC20000FB */
