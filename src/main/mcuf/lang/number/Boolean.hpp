/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_AB5A72F1_A2BD_4DB3_94EF_8F0B7AE9215A
#define MCUF_AB5A72F1_A2BD_4DB3_94EF_8F0B7AE9215A

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/lang/number/Number.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    namespace number{
      class Boolean;
    }
  }
}



/* ****************************************************************************************
 * Class Boolean
 */  
class mcuf::lang::number::Boolean extends mcuf::lang::number::Number{
      
  /* **************************************************************************************
   * Subclass
   */
   
  /* **************************************************************************************
   * valueariable <Public>
   */

  /* **************************************************************************************
   * valueariable <Protected>
   */

  /* **************************************************************************************
   * valueariable <Private>
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
  public: Boolean(void);

  /**
   * Construct.
   */
  public: Boolean(bool valuealue);
  
  /**
   * Destruct.
   */
  public: virtual ~Boolean() = default;

  /* **************************************************************************************
   * Operator Method
   */
   
  /**
   * 
   */
  public: operator bool(void);
  
  /**
   * 
   */  
  public: bool operator==(bool value);

  /**
   * 
   */
  public: bool operator==(Boolean& value);

  /**
   * 
   */
  public: bool operator==(Number& value);
  
  /**
   * 
   */
  public: bool operator=(bool value);

  /**
   * 
   */
  public: Boolean operator+=(int value);

  /**
   * 
   */
  public: Boolean operator-=(int value);

  /**
   * 
   */
  public: Boolean operator*=(int value);

  /**
   * 
   */
  public: Boolean operator/=(int value);
  
  /**
   * 
   */
  public: Boolean operator++(int);
  
  /**
   * 
   */
  public: Boolean operator++(void);

  /**
   * 
   */
  public: Boolean operator--(int);
  
  /**
   * 
   */
  public: Boolean& operator--(void);
  
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
 *  End of file
 */ 


#endif/* MCUF_AB5A72F1_A2BD_4DB3_94EF_8F0B7AE9215A */
