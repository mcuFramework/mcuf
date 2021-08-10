/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_EEC25F8B_68C8_45FC_A820_3773DB4D7EF7
#define MCUF_EEC25F8B_68C8_45FC_A820_3773DB4D7EF7

/* ****************************************************************************************
 * Include
 */  
#include "../lang/Object.hpp"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace lang{
    class Math;
  }
}



/* ****************************************************************************************
 * Class Math
 */  
class mcuf::lang::Math :
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

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

  /**
   * Construct.
   */
  public: Math(void) = default;

  /**
   * Disconstruct.
   */
  public: virtual ~Math(void) = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */ 

  /**
   * Returns the absolute value of an int value. If the argument is not negative, the 
   * argument is returned. If the argument is negative, the negation of the argument is 
   * returned.
   * 
   * Note that if the argument is equal to the value of Integer.MIN_VALUE, the most 
   * negative representable int value, the result is that same value, which is negative.
   * 
   * @param a the argument whose absolute value is to be determined
   * @return the absolute value of the argument.
   */
  public: static int abs(int a);

  /**
   * Returns the absolute value of a long value. If the argument is not negative, the 
   * argument is returned. If the argument is negative, the negation of the argument is 
   * returned.
   * 
   * Note that if the argument is equal to the value of Long.MIN_VALUE, the most 
   * negative representable long value, the result is that same value, which is negative.
   * 
   * @param a the argument whose absolute value is to be determined
   * @return the absolute value of the argument.
   */
  public: static long abs(long a);

  /**
   * Returns the absolute value of a float value. If the argument is not negative, the 
   * argument is returned. If the argument is negative, the negation of the argument is 
   * returned.
   * 
   * Note that if the argument is equal to the value of Float.MIN_VALUE, the most 
   * negative representable float value, the result is that same value, which is negative.
   * 
   * @param a the argument whose absolute value is to be determined
   * @return the absolute value of the argument.
   */
  public: static float abs(float a); 

  /**
   * 
   */
  public: static int ceil(int dividend, int divisor);

  /**
   * 
   */
  public: static uint32_t ceil(uint32_t dividend, uint32_t divisor);  

  /**
   * 
   */
  public: static uint32_t min(uint32_t a, uint32_t b);

  /**
   * 
   */
  public: static uint32_t max(uint32_t a, uint32_t b);

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


#endif/* MCUF_EEC25F8B_68C8_45FC_A820_3773DB4D7EF7 */
