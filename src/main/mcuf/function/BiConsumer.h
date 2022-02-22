/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_CE48C601_AB18_4B36_8C89_8ACA733118B1
#define MCUF_CE48C601_AB18_4B36_8C89_8ACA733118B1

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace function{
    template<typename T, typename U> interface BiConsumer;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
template<typename T, typename U>
interface mcuf::function::BiConsumer{

  /* **************************************************************************************
   * Method 
   */
  
  /**
   * @brief 
   * 
   * @param t 
   * @param u 
   */
  virtual void accept(T t, U u) abstract;
   
};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* MCUF_CE48C601_AB18_4B36_8C89_8ACA733118B1 */
