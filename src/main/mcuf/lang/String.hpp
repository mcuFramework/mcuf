/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_F115800B_0B0A_4795_ABFB_A37BD1DE2055
#define MCUF_F115800B_0B0A_4795_ABFB_A37BD1DE2055

/* ****************************************************************************************
 * Include
 */  
#include <stdarg.h>

#include "mcuf_base.h"
#include "mcuf_config.h"
#include "mcuf/lang/Memory.hpp"
#include "mcuf/lang/Object.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class String;
  }
}

/* ****************************************************************************************
 * Class String
 */  
class mcuf::lang::String extends mcuf::lang::Memory{

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
   *
   */
  private: String(uint32_t size);

  /**
   * Construct.
   */
  public: String(const char* str);
  
  /**
   * Construct
   */
  public: String(mcuf::lang::Memory& memory);
  
  /**
   * Construct
   */
  public: String(mcuf::lang::Memory&& memory);

  /**
   * Destruct.
   */
  public: virtual ~String(void) = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /**
   * 
   */
  public: static String format(const char* format, va_list arg);

  /**
   * 
   */
  public: static String format(const char* format, ...);

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method
   */
  
  // /**
  //  * 
  //  */
  // public: char charAt(int index);

  // /**
  //  * 
  //  */
  // public: int compairTo(String& anotherString);

  // /**
  //  * 
  //  */
  // public: int compareToIgnoreCase(String str);

  // /**
  //  * 
  //  */
  // public: String& concat(String str); 


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
 

#endif/* MCUF_F115800B_0B0A_4795_ABFB_A37BD1DE2055 */
