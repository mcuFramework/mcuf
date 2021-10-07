/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_B13FC504_C653_4436_A427_B6D01A462988
#define MCUF_B13FC504_C653_4436_A427_B6D01A462988

/* ****************************************************************************************
 * Integer
 */  
#include "mcuf_base.h"
#include "mcuf/lang/number/Number.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    namespace number{
      class Integer;
    }
  }
}



/* ****************************************************************************************
 * Class Integer
 */  
class mcuf::lang::number::Integer extends mcuf::lang::number::Number{

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
  public: Integer(void) = default;

  /**
   * Construct.
   */
  public: Integer(int value);
  
  /**
   * Destruct.
   */
  public: virtual ~Integer() = default;

  /* **************************************************************************************
   * Operator Method
   */

  /**
   * 
   */
  public: operator int(void);

  /**
   * 
   */  
  public: bool operator==(int v);

  /**
   * 
   */
  public: bool operator==(Integer& v);

  /**
   * 
   */
  public: bool operator==(Number& v);

  /**
   * 
   */
  public: int operator=(int v);

  /**
   * 
   */
  public: Integer operator+=(int v);

  /**
   * 
   */
  public: Integer operator-=(int v);

  /**
   * 
   */
  public: Integer operator*=(int v);

  /**
   * 
   */
  public: Integer operator/=(int v);
  
  /**
   * 
   */
  public: Integer operator++(int);
  
  /**
   * 
   */
  public: Integer operator++(void);

  /**
   * 
   */
  public: Integer operator--(int);
  
  /**
   * 
   */
  public: Integer& operator--(void);
  
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


#endif/* MCUF_B13FC504_C653_4436_A427_B6D01A462988 */
