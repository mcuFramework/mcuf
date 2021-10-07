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
#include "mcuf/lang/Object.hpp"
#include "mcuf/lang/Throwable.hpp"



/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace io{
    namespace channel{
      template<typename V, typename A> interface CompletionHandler;
    }
  }
}



/* ****************************************************************************************
 * Class Map
 */
template<typename V, typename A>
interface mcuf::io::channel::CompletionHandler{
  /* **************************************************************************************
   *  Variable <Public>
   */

  /* **************************************************************************************
   *  Variable <Protected>
   */

  /* **************************************************************************************
   *  Variable <Private>
   */

  /* **************************************************************************************
   *  Abstract method <Public>
   */
    
  /**
   *
   */
  virtual void completed(V result, A attachment) abstract;
  
  /**
   *
   */
  virtual void failed(mcuf::lang::Throwable& exc, A attachment) abstract;

  /* **************************************************************************************
   *  Abstract method <Protected>
   */

  /* **************************************************************************************
   *  Construct Method
   */

  /* **************************************************************************************
   *  Public Method <Static>
   */

  /* **************************************************************************************
   *  Public Method <Override>
   */

  /* **************************************************************************************
   *  Public Method
   */
  
  /* **************************************************************************************
   *  Protected Method <Static>
   */

  /* **************************************************************************************
   *  Protected Method <Override>
   */

  /* **************************************************************************************
   *  Protected Method
   */

  /* **************************************************************************************
   *  Private Method <Static>
   */

  /* **************************************************************************************
   *  Private Method <Override>
   */
   
  /* **************************************************************************************
   *  Private Method
   */
};



/* *****************************************************************************************
 *    End of file
 */ 


#endif/* MCUF_F628179A_5A6B_4572_99A4_3338D77AED7B */
