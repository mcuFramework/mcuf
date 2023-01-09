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
  interface Interface;
  class Object;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
interface mcuf::Interface{

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
  virtual mcuf::Object& getObject(void) abstract;

};

/* ****************************************************************************************
 * End of file
 */

#endif /* MCUF_242D7CFC_C83D_4A29_8BC7_A6FF9CCEDD5D */
