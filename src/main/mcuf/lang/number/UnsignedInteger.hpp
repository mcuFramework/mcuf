/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_B3EAD09E_123F_4FD3_B329_BFB99FE91D79
#define MCUF_B3EAD09E_123F_4FD3_B329_BFB99FE91D79

/* ****************************************************************************************
 * UnsignedInteger
 */  
#include "NumberTemplate.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    namespace number{
      class UnsignedInteger;
    }
  }
}



/* ****************************************************************************************
 * Class UnsignedInteger
 */  
class mcuf::lang::number::UnsignedInteger : 
      public mcuf::lang::number::NumberTemplate<unsigned int>{

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
  public: UnsignedInteger(void) = default;

  /**
   * Construct.
   */
  public: UnsignedInteger(unsigned int value);
  
  /**
   * Disconstruct.
   */
  public: virtual ~UnsignedInteger() = default;

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


#endif/* MCUF_B3EAD09E_123F_4FD3_B329_BFB99FE91D79 */
