/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_E88C2036_9666_4C5D_8F92_CB77EC035D49
#define MCUF_E88C2036_9666_4C5D_8F92_CB77EC035D49

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/lang/Exception.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    class IOException;
  }
}

/* ****************************************************************************************
 * Class Object
 */  
class mcuf::io::IOException extends mcuf::lang::Exception{

  /* **************************************************************************************
   * Subclass
   */

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
  public: IOException(const char* path, const char* message);

  /**
   * Construct
   */
  public: IOException(const char* path, mcuf::lang::String& message);
  
  /**
   * Construct
   */
  public: IOException(const char* path, mcuf::lang::String&& message);  

  /**
   * Destruct.
   */
  public: virtual ~IOException(void) = default;

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

#endif/* MCUF_E88C2036_9666_4C5D_8F92_CB77EC035D49 */