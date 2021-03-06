/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_E537A6FD_D802_4D38_AB7E_1AAF3D6487AD
#define MCUF_E537A6FD_D802_4D38_AB7E_1AAF3D6487AD

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/lang/Interface.h"


/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace function{
    template<typename T> interface Consumer;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
template<typename T>
interface mcuf::function::Consumer extends virtual mcuf::lang::Interface{

  /* **************************************************************************************
   * Method
   */
  
  /**
   * @brief 
   * 
   * @param t 
   */
  virtual void accept(T t) abstract;
   
};


/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_E537A6FD_D802_4D38_AB7E_1AAF3D6487AD */
