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
#include "mcuf_base.h"
#include "mcuf/lang/Object.h"



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
class mcuf::lang::number::Number extends mcuf::lang::Object{

  /* **************************************************************************************
   * Subclass
   */

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */
  protected: uint32_t mValue;
  
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
  public: bool booleanValue(void);

  /**
   * 
   */
  public: char byteValue(void);

  /**
   * 
   */
  public: unsigned char unsignedByteValue(void);

  /**
   * 
   */
  public: short shortValue(void);

  /**
   * 
   */                                       
  public: unsigned short unsignedShortValue(void);

  /**
   * 
   */
  public: int intValue(void);

  /**
   * 
   */
  public: unsigned int unsignedIntValue(void);

  /**
   * 
   */
  public: float floatValue(void);

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
