/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_A1CEB570_37B1_46EF_A349_E340807CFCCB
#define MCUF_A1CEB570_37B1_46EF_A349_E340807CFCCB

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/lang/Object.hpp"
#include "mcuf/lang/String.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class Throwable;
  }
}



/* ****************************************************************************************
 * Class Throwable
 */  
class mcuf::lang::Throwable extends mcuf::lang::Object{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */
  protected: const char* mPath;
  protected: const char* mType;
  protected: String mMessage;

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
  public: Throwable(const char* path, const char* message);

  /**
   * Construct
   */
  public: Throwable(const char* path, mcuf::lang::String& message);
  
  /**
   * Construct
   */
  public: Throwable(const char* path, mcuf::lang::String&& message);  

  /**
   * Destruct.
   */
  public: virtual ~Throwable(void) = default;

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
  
  /**
   *
   */
  public: mcuf::lang::String getPath(void);
  
  /**
   *
   */
  public: mcuf::lang::String getMessage(void);
  
  /**
   *
   */
  public: mcuf::lang::String getType(void);
  

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


#endif/* MCUF_A1CEB570_37B1_46EF_A349_E340807CFCCB */
