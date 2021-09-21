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
class mcuf::lang::String extends mcuf::lang::Object{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */
  public: static char emptyString;

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */

  /**
   * Static
   */
  private: static char handleMemory[MCUF_STRING_HANDLE_MEMORY_SIZE];

  /**
   * Non-static
   */
  private: char* mPointer;
  private: uint32_t mSize;


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
  private: String(char* str, uint32_t size);

  /**
   * Construct.
   */
  public: String(const char* original);

  /**
   * Construct.
   */
  public: String(void);

  /**
   * Disconstruct.
   */
  public: ~String(void);

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

  /**
   * 
   */
  public: static char* formatChar(const char* format, va_list arg);

  /**
   * 
   */
  public: static char* formatChar(const char* format, ...);

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

  /**
   * 
   */
  public: bool isConst(void);

  /**
   * 
   */
  public: uint32_t length(void);

  /**
   * 
   */
  public: const char* toPointer(void);

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
