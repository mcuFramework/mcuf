/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_242D7CFC_C83D_4A29_8BC7_A6FF9CCEDD5D
#define MCUF_242D7CFC_C83D_4A29_8BC7_A6FF9CCEDD5D

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
  namespace lang{
    interface Interface;
    class Object;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::lang::Interface{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief Destroy the Interface object
   * 
   */
  virtual ~Interface(void) = default;
  
  /**
   *
   */
  virtual mcuf::lang::Object& getObject(void);

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_242D7CFC_C83D_4A29_8BC7_A6FF9CCEDD5D */
