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
#include "./Interface.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace mcuf{
  interface NioExecuteMethod;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::NioExecuteMethod extends virtual mcuf::Interface{

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
