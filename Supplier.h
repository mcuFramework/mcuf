/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_A59752C6_6883_4BC0_86C8_5C004260E415
#define MCUF_A59752C6_6883_4BC0_86C8_5C004260E415

/* ****************************************************************************************
 * Include
 */  
#include "./mcuf_base.h"
#include "./Object.h"
#include "./Interface.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  template<typename T> interface Supplier;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
template<typename T>
interface mcuf::Supplier extends virtual mcuf::Interface{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @return T 
   */
  virtual T get(void) abstract;
   
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_A59752C6_6883_4BC0_86C8_5C004260E415 */
