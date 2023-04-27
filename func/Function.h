/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_B1264AE8_03E1_49A5_9EE7_8C4B88B06CFE
#define MCUF_B1264AE8_03E1_49A5_9EE7_8C4B88B06CFE

/* ****************************************************************************************
 * Include
 */  
 
//-----------------------------------------------------------------------------------------
#include "./../mcuf/Interface.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  
namespace func{
  template<typename T, typename R> interface Function;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
template<typename T, typename R>
interface func::Function extends virtual mcuf::Interface{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @param t 
   * @return R 
   */
  virtual R apply(T t) abstract;

};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_B1264AE8_03E1_49A5_9EE7_8C4B88B06CFE */