/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_CBE0B0A6_99A6_4C44_B1B5_4FB3B8FA3AD4
#define MCUF_CBE0B0A6_99A6_4C44_B1B5_4FB3B8FA3AD4

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mcuf.h"
#include "mcuf/lang/Interface.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  namespace util{
    interface NioExecuteMethod;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::util::NioExecuteMethod extends virtual mcuf::lang::Interface{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief NIO套件處理的進入方法
   *
   */
  virtual void execute(void) abstract;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_CBE0B0A6_99A6_4C44_B1B5_4FB3B8FA3AD4 */
