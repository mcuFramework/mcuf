/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_F9B57639_6FC2_4ABB_B8EB_618F2228B096
#define MCUF_F9B57639_6FC2_4ABB_B8EB_618F2228B096

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
      class Byte;
    }
  }
}



/* ****************************************************************************************
 * Class Byte
 */  
class mcuf::lang::number::Byte extends mcuf::lang::number::Number{
      
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
  public: Byte(void) = default;

  /**
   * Construct.
   */
  public: Byte(char value);
  
  /**
   * Disconstruct.
   */
  public: virtual ~Byte() = default;

  /* **************************************************************************************
   * Operator Method
   */
   
  /**
   * 
   */
  public: operator char(void);

  /**
   * 
   */  
  public: bool operator==(int v);

  /**
   * 
   */
  public: bool operator==(Byte& v);

  /**
   * 
   */
  public: bool operator==(Number& v);
  
  /**
   * 
   */
  public: char operator=(char v);

  /**
   * 
   */
  public: Byte operator+=(int v);

  /**
   * 
   */
  public: Byte operator-=(int v);

  /**
   * 
   */
  public: Byte operator*=(int v);

  /**
   * 
   */
  public: Byte operator/=(int v);
  
  /**
   * 
   */
  public: Byte operator++(int);
  
  /**
   * 
   */
  public: Byte operator++(void);

  /**
   * 
   */
  public: Byte operator--(int);
  
  /**
   * 
   */
  public: Byte& operator--(void);
  
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


#endif/* MCUF_F9B57639_6FC2_4ABB_B8EB_618F2228B096 */
