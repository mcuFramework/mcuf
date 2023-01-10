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
#include "mcuf/mcuf_base.h"
#include "mcuf/Object.h"
#include "mcuf/Interface.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace function{
    template<typename T> interface Supplier;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
template<typename T>
interface mcuf::function::Supplier extends virtual mcuf::Interface{

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
