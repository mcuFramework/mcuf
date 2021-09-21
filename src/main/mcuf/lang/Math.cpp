/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */  
#include "Math.hpp"
 
/* ****************************************************************************************
 * Using
 */  
using mcuf::lang::Math;
 
/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */
 
/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

/**
 * 
 */
int Math::abs(int a){
  if(a<0)
    return (a * (-1));
  
  return a;
}

/**
 * 
 */
long Math::abs(long a){
  if(a<0)
    return (a * (-1));
  
  return a;
}

/**
 * 
 */
float Math::abs(float a){
  if(a<0)
    return (a * (-1));
  
  return a;
}

/**
 * 
 */
int Math::ceil(int dividend, int divisor){
  int result = dividend/divisor;
  if(dividend%divisor)
    ++result;
  
  return result;
}

/**
 * 
 */
uint32_t Math::ceil(uint32_t dividend, uint32_t divisor){
  uint32_t result = dividend/divisor;
  if(dividend%divisor)
    ++result;
  
  return result;
}

/**
 * 
 */
uint32_t Math::min(uint32_t a, uint32_t b){
  return ((a)<(b)?(a):(b));
}

/**
 * 
 */
uint32_t Math::max(uint32_t a, uint32_t b){
  return ((a)>(b)?(a):(b));
}

/* ****************************************************************************************
 * Protected Method <Static>
 */
 
/* ****************************************************************************************
 * Protected Method <Override>
 */ 

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */
 
/* ****************************************************************************************
 * End of file
 */ 
