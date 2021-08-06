/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_C6CF2DB4_1F61_4562_8698_C0C22D0C69FA
#define MCUF_C6CF2DB4_1F61_4562_8698_C0C22D0C69FA

/* ****************************************************************************************
 * Include
 */  
#include "../../lang/Object.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    namespace number{
      class Number;
    }
  }
}



/* ****************************************************************************************
 * Class Integer
 */  
class mcuf::lang::number::Number: 
      public mcuf::lang::Object{

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

  /**
   * 
   */  
  public: virtual bool booleanValue(void) = 0;

  /**
   * 
   */
  public: virtual char byteValue(void) = 0;

  /**
   * 
   */
  public: virtual unsigned char unsignedByteValue(void) = 0;

  /**
   * 
   */
  public: virtual short shortValue(void) = 0;

  /**
   * 
   */                                       
  public: virtual unsigned short unsignedShortValue(void) = 0;

  /**
   * 
   */
  public: virtual int intValue(void) = 0;

  /**
   * 
   */
  public: virtual unsigned int unsignedIntValue(void) = 0;

  /**
   * 
   */
  public: virtual long long longValue(void) = 0;

  /**
   * 
   */
  public: virtual unsigned long long unsignedLongValue(void) = 0;

  /**
   * 
   */
  public: virtual float floatValue(void) = 0;

  /**
   * 
   */
  public: virtual double doublevalue(void) = 0;
  
  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

  /**
   * 
   */
  public: Number(void) = default;
  
  /**
   * 
   */
  public: virtual ~Number() = default;

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
  public: bool equal(Number* object);

  /**
   * 
   */
  public: bool equal(Number& object);
  
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


#endif/* MCUF_C6CF2DB4_1F61_4562_8698_C0C22D0C69FA */
