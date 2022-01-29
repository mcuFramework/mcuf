/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_A35B63D2_8288_4C2E_ACB8_69DAC9906340
#define MCUF_A35B63D2_8288_4C2E_ACB8_69DAC9906340

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/lang/number/Number.h"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    namespace number{
      class Short;
    }
  }
}



/* ****************************************************************************************
 * Class Short
 */  
class mcuf::lang::number::Short extends mcuf::lang::number::Number{

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
  public: Short(void) = default;

  /**
   * Construct.
   */
  public: Short(short value);
  
  /**
   * Destruct.
   */
  public: virtual ~Short() = default;

  /* **************************************************************************************
   * Operator Method
   */
  
  /**
   * 
   */
  public: operator short(void);

  /**
   * 
   */  
  public: bool operator==(int value);

  /**
   * 
   */
  public: bool operator==(Short& value);

  /**
   * 
   */
  public: bool operator==(Number& value);

  /**
   * 
   */
  public: Short operator=(Short value);

  /**
   * 
   */
  public: Short operator+=(int value);

  /**
   * 
   */
  public: Short operator-=(int value);

  /**
   * 
   */
  public: Short operator*=(int value);

  /**
   * 
   */
  public: Short operator/=(int value);
  
  /**
   * 
   */
  public: Short operator++(int);
  
  /**
   * 
   */
  public: Short operator++(void);

  /**
   * 
   */
  public: Short operator--(int);
  
  /**
   * 
   */
  public: Short& operator--(void);
  
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


#endif/* MCUF_A35B63D2_8288_4C2E_ACB8_69DAC9906340 */
