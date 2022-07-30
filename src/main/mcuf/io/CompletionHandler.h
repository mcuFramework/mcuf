/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_F628179A_5A6B_4572_99A4_3338D77AED7B
#define MCUF_F628179A_5A6B_4572_99A4_3338D77AED7B

/* ****************************************************************************************
 * Include
 */
#include "mcuf_base.h"
#include "mcuf/lang/Object.h"
#include "mcuf/lang/Interface.h"


/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    template<typename V, typename A> interface CompletionHandler;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */
template<typename V, typename A>
interface mcuf::io::CompletionHandler extends mcuf::lang::Interface{

  /* **************************************************************************************
   *  Method
   */
    
  /**
   * @brief 
   * 
   * @param result 
   * @param attachment 
   */
  virtual void completed(V result, A attachment) abstract;
  
  /**
   * @brief 
   * 
   * @param exc 
   * @param attachment 
   */
  virtual void failed(void* exc, A attachment) abstract;

};

/* *****************************************************************************************
 *    End of file
 */ 

#endif /* MCUF_F628179A_5A6B_4572_99A4_3338D77AED7B */
