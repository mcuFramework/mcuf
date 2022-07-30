/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

#ifndef MCUF_B0CBE2EB_7208_46F6_A04E_DBE8865889DF
#define MCUF_B0CBE2EB_7208_46F6_A04E_DBE8865889DF

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"
#include "mcuf/lang/Interface.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace util{
    namespace concurrent{
      template<typename V> interface Future;
    }
  }
}



/* ****************************************************************************************
 * Class Future
 */  
template<typename V>
interface mcuf::util::concurrent::Future extends virtual mcuf::lang::Interface{
  
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

  /**
   * 
   */
  virtual bool cancel(bool mayInterruptIfRunning) abstract;

  /**
   * 
   */
  virtual V get(void) abstract;

  /**
   * 
   */
  virtual V get(uint32_t timeoutMilliSecond) abstract;

  /**
   * 
   */
  virtual bool isCancelled(void) abstract;

  /**
   * 
   */
  virtual bool isDone(void) abstract;

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */

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
 *   End of file
 */ 


#endif /* MCUF_B0CBE2EB_7208_46F6_A04E_DBE8865889DF */
