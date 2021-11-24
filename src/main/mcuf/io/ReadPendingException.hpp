/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_D4937ADD_3905_457A_8668_A4FFE0CD1051
#define MCUF_D4937ADD_3905_457A_8668_A4FFE0CD1051

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/io/IOException.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    class ReadPendingException;
  }
}

/* ****************************************************************************************
 * Class Object
 */  
class mcuf::io::ReadPendingException extends mcuf::io::IOException{

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
  public: ReadPendingException(const char* path, const char* message);

  /**
   * Construct
   */
  public: ReadPendingException(const char* path, mcuf::lang::String& message);
  
  /**
   * Construct
   */
  public: ReadPendingException(const char* path, mcuf::lang::String&& message);  

  /**
   * Destruct.
   */
  public: virtual ~ReadPendingException(void) = default;

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

#endif/* MCUF_D4937ADD_3905_457A_8668_A4FFE0CD1051 */