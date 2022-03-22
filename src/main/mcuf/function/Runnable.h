/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef MCUF_A54036B2_950E_4F06_9CD4_6FD23597926A
#define MCUF_A54036B2_950E_4F06_9CD4_6FD23597926A

/* ****************************************************************************************
 * Include
 */  
#include "mcuf_base.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace mcuf{
  namespace function{
    interface Runnable;
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
interface mcuf::function::Runnable{

  /* **************************************************************************************
   * Method
   */

  /**
   * @brief 
   * 
   */
  virtual void run(void) abstract;
  
};

/* *****************************************************************************************
 * End of file
 */ 

#endif /* MCUF_A54036B2_950E_4F06_9CD4_6FD23597926A */
