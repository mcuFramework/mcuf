/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_EE4E0BE6_E1E0_43B2_B9D2_2CE26334D212
#define MCUF_EE4E0BE6_E1E0_43B2_B9D2_2CE26334D212

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/lang/Object.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class Error;
  }
}

/* ****************************************************************************************
 * Class Object
 */  
class mcuf::lang::Error final extends mcuf::lang::Object{

  /* **************************************************************************************
   * Subclass
   */
  public: enum Code{
    NONE                       = 0,
    HARD_FAULT                 = 1,
    OUT_OF_MEMORY              = 2,
    NULL_POINTER               = 3,
    ILLEGAL_ARGUMENT           = 4,
    INSUFFICIENT_MEMORY        = 5,
    WRITE_TO_READONLY_MEMORY   = 6,
    MEMORY_NOT_ALIGNMENT_32BIT = 5,
    MEMORY_NOT_ALIGNMENT_64BIT = 8,
    RESERVED                   = 0x7FFFFFFF
  };
  

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

  /**
   * Construct.
   */
  private: Error(void) = default;

  /**
   * Destruct.
   */
  private: virtual ~Error(void) = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method
   */

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */
   
  /* **************************************************************************************
   * Private Method
   */  

};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_EE4E0BE6_E1E0_43B2_B9D2_2CE26334D212 */
